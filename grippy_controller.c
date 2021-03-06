#include <stdio.h>
#include <libplayerc/playerc.h>
#include "grippy.h"

int main(int argc, char *argv[]){
	playerc_client_t *client;
	playerc_position2d_t *position2d;
	playerc_ranger_t *ranger;
	int i, j;

	/* Connect to robot and initilize devices */
	client = playerc_client_create(NULL, GRIPPY_HOST, GRIPPY_PORT);
	if(playerc_client_connect(client) != 0){
		fprintf(stderr, "Failed to connect to client\n");
		return -1;
	}

	position2d = playerc_position2d_create(client, 0);
	if(playerc_position2d_subscribe(position2d, PLAYER_OPEN_MODE)){
		fprintf(stderr, "Filed to find position2d device\n");
		return -1;
	}

	ranger = playerc_ranger_create(client, 0);
	if(playerc_ranger_subscribe(ranger, PLAYER_OPEN_MODE)){
		fprintf(stderr, "Failed to find ranger device\n");
		return -1;
	}

	/* MAIN CONTROLLER CODE: Do something */
	for(i=0; i<10; i++){
		playerc_client_read(client);
		playerc_position2d_get_geom(position2d);
		printf("Position: %f %f %f\n", position2d->px, position2d->py, position2d->pa);
		printf("%d Scanned points\n", ranger->ranges_count);
		for(j=0; j<ranger->ranges_count; j++){
			printf("  %f", ranger->ranges[j]);
		}
		printf("\n\n");
		playerc_position2d_set_cmd_vel(position2d, 1, 0, 1, 0);
	}

	/* Shut down connected devices */
	playerc_ranger_unsubscribe(ranger);
	playerc_ranger_destroy(ranger);

	playerc_position2d_unsubscribe(position2d);
	playerc_position2d_destroy(position2d);

	playerc_client_disconnect(client);
	playerc_client_destroy(client);

	return 0;
}
