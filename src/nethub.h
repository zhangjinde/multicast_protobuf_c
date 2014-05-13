/*
 * =====================================================================================
 *
 *       Filename:  nethub.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/14 08:21:26
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jonesax (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __NET_HUB_H__
#define __NET_HUB_H__
#include <jnxc_headers/jnxnetwork.h>
#include <jnxc_headers/jnxlist.h>
#include <jnxc_headers/jnxsocket.h>
#include <jnxc_headers/jnxsignal.h>
typedef struct nethub_obj {
	jnx_socket *udp_multicaster;
	jnx_socket *udp_listener;
	jnx_socket *udp_direct_send;
	char *localipv4;
	char *interface;
	char *group_port;
	char *group;
	jnx_signal *update_sig;

}nethub_obj;


nethub_obj* nethub_create(char *interface, char *group, char *group_port);
void nethub_run(nethub_obj* nh);
#endif
