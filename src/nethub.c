/*
 * =====================================================================================
 *
 *       Filename:  nethub.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/14 08:25:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jonesax (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <unistd.h>
#include "nethub.h"
#include <string.h>
#include <stdio.h>
#include <jnxc_headers/jnxthread.h>
#include <jnxc_headers/jnxcheck.h>
#include <jnxc_headers/jnxlog.h>
//protobuf
#include "../proto/proto_multicast.pb-c.h"

size_t nethub_generate_ping(nethub_obj *nh,void **obuffer) {
	
	MulticastMsg m = MULTICAST_MSG__INIT;
	uint64_t message[256];
	bzero(message,256);
	sprintf((char*)message,"%s|PING",nh->localipv4);
	printf("message: %s\n",message);
	m.n_c = strlen((char*)message);
	m.c = malloc(sizeof(uint64_t) * m.n_c);
	memcpy(m.c,message,m.n_c);
	
	//##Pack our protobuf data structure here
	int len = multicast_msg__get_packed_size(&m);
	*obuffer = malloc(len);
	multicast_msg__pack(&m,*obuffer);
	free(m.c);
	return len;
}
nethub_obj* nethub_create(char *interface, char *group, char *group_port) {
	JNXCHECK(interface);
	JNXCHECK(group);
	JNXCHECK(group_port);
	nethub_obj *nh = malloc(sizeof(nethub_obj));
	nh->udp_multicaster = jnx_socket_udp_create(AF_INET);
	nh->udp_listener = jnx_socket_udp_create(AF_INET);
	nh->group = group;
	nh->interface = interface;
	nh->group_port = group_port;
	int ret = jnx_network_interface_to_string(&nh->localipv4,"wlp1s0",AF_INET);
	JNXCHECK(ret == 0);
	
	return nh;
}
void *nethub_loop(void *args) {
	JNX_LOGC(JLOG_NORMAL,"Starting multicaster...\n");
	nethub_obj *nh = args;
	while(1){

		void *buffer;
		size_t len = nethub_generate_ping(nh,&buffer);	
		printf("o message len %d\n",len);
		
		jnx_socket_udp_send(nh->udp_multicaster,nh->group,nh->group_port,buffer,len);
		
		free(buffer);
		sleep(2);
	}
	return 0;
}
int nethub_listener_cb(uint8_t *msg, size_t len, jnx_socket *s) {
	
	MulticastMsg *m;
	//## Unpack our data structure here
	m = multicast_msg__unpack(NULL,len,msg);
	if(m == NULL) {
		printf("Something went wrong...\n");
		return 1;
	}else {
		printf("Unpacked: %s\n",m->c);
		multicast_msg__free_unpacked(m,NULL);
		free(msg);
	}
	return 0;
}
void *nethub_listen(void *args) {
	JNX_LOGC(JLOG_NORMAL,"Starting listener...\n");
	nethub_obj *nh = args;
	jnx_socket_udp_enable_multicast_listen(nh->udp_multicaster,nh->localipv4,nh->group);
	jnx_socket_udp_listen(nh->udp_listener,nh->group_port,24,nethub_listener_cb);
	return 0;
}
void nethub_run(nethub_obj* nh) {
	jnx_thread_create_disposable(nethub_loop,nh); 
	jnx_thread_create_disposable(nethub_listen,nh);
}
