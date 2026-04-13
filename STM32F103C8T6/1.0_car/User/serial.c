#include <stdio.h>
#include <string.h>

#include "serial.h"


struct Struct_SerialRx rx;


void SerialGetData( struct Struct_SerialRx * rx ){
	rx->recv_done=0;
	
	rx->data_token = strtok((char *)rx->rx_buf, "[,]");
	
	if(strcmp(rx->data_token, "key")==0){
		rx->key.name=strtok(NULL, "[,]");
		rx->key.operation=strtok(NULL, "[,]");
	}
	else if (strcmp(rx->data_token, "slider")==0){
		rx->slider.name=strtok(NULL, "[,]");
		rx->slider.value=atof(strtok(NULL, "[,]"));
	}
	else if(strcmp(rx->data_token, "joystick")==0){
		rx->joystick.lh = atoi(strtok(NULL, "[,]"));
		rx->joystick.lv = atoi(strtok(NULL, "[,]"));
		rx->joystick.rh = atoi(strtok(NULL, "[,]"));	
		rx->joystick.rv = atoi(strtok(NULL, "[,]"));		
	}
}


//char rx_buf[] = "[key,1,down]";
//char *token;

//token = strtok(rx_buf, "[,]");
//char *key = token;

//token = strtok(NULL, "[,]");
//int value = atoi(token);

//token = strtok(NULL, "[,]");
//char *state = token;
