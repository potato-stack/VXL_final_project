/*
 * fsm_pedestrian.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Thinh Dang
 */
#include "fsm_pedestrian.h"
#include "display_control.h"


void fsm_pedestrian(){
	switch(status2){
	case AUTO_RED_GREEN :
		//Redp_On();
		if(timer3_flag == 1) {
			Reset_p();
			status2 = -14;
		}
		else Redp_On();
		break;
	case AUTO_RED_YELLOW:
		//Redp_On();
		if(timer3_flag == 1) {
			Reset_p();
			status2 = -14;
		}
		else Redp_On();
		break;
	case AUTO_GREEN_RED:
		//Greenp_On();
		if(timer3_flag == 1) {
			Reset_p();
			status2 = -14;
		}
		else Greenp_On();
		break;
	case AUTO_YELLOW_RED:
		//Greenp_On();
		if(timer3_flag == 1) {
			Reset_p();
			status2 = -14;
		}
		else Greenp_On();
		break;
	case MAN_RED_GREEN:
		Redp_On();
		if(timer3_flag == 1) {
			Reset_p();
			status2 = -14;
		}
		break;
	case MAN_RED_YELLOW:
		Redp_On();
		if(timer3_flag == 1) {
			Reset_p();
			status2 = -14;
		}
		break;
	case MAN_GREEN_RED:
		Greenp_On();
		if(timer3_flag == 1) {
			Reset_p();
			status2 = -14;
		}
		break;
	case MAN_YELLOW_RED:
		Greenp_On();
		if(timer3_flag == 1) {
			Reset_p();
			status2 = -14;
		}
		break;

	default: break;
}
}
