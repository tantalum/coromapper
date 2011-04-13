#include <stdio.h>
#include <libplayerc/playerc.h>
#include "grippy.h"

int main(int argc, char *argv[]){
	playerc_client_t *client;
	playerc_device_info_t devinfo;
	int i;

	client = playerc_client_create(NULL, GRIPPY_HOST, GRIPPY_PORT);
	if(playerc_client_connect(client) != 0){
		fprintf(stderr, "Failed to connect to client: %s\n", playerc_error_str());
		return -1;
	}
	printf("Connected to client (%d) at [%s:%d]\n", client->sock, client->host, client->port);

	if(playerc_client_get_devlist(client) != 0){
		fprintf(stderr, "Failed to list devices: %s\n", playerc_error_str());
		return -1;
	}
	printf("Client has %d devices\n", client->devinfo_count);
	
	for(i=0; i<client->devinfo_count; i++){
		devinfo = client->devinfos[i];
		printf("\t%s:%d\n", devinfo.drivername, devinfo.addr.index);
	}

	return 0;
}
