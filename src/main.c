/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/14 08:20:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jonesax (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "nethub.h"
#include <unistd.h>
int main(int argc, char **argv) {

	nethub_obj *nh = nethub_create("wlp1s0","225.1.1.1","9095");

	nethub_run(nh);

	while(1) {

		sleep(0.5);
	}


	return 0;

}
