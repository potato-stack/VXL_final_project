/*
 * fsm_manual.h
 *
 *  Created on: Oct 7, 2022
 *      Author: hatru
 */
#include "fsm_manual.h"
#include "input_reading.h"
#include "display_control.h"

void fsm_manual_run()
{
	switch(status1)
	{
	case MAN_RED_GREEN:
		Green1_On();
		if(timer1_flag == 1)
		{
			change_mode(0);
			status1=AUTO_RED_GREEN;
			set_road1_time(red_time);
			set_road2_time(green_time);
			setTimer1(green_time);
		}
		if(button_flag[1] == 1)
		{
			button_flag[1]=0;
			status1=MAN_RED_YELLOW;
			setTimer1(timeout_duration);
		}
		break;
	case MAN_RED_YELLOW:
		Red_On();
		Yellow1_On();
		if(timer1_flag == 1)
		{
			change_mode(0);
			status1=AUTO_RED_YELLOW;
			set_road1_time(yellow_time);
			set_road2_time(yellow_time);
			setTimer1(yellow_time);
		}
		if(button_flag[1]  == 1)
		{
			button_flag[1]=0;
			status1=MAN_GREEN_RED;
			setTimer1(timeout_duration);
		}
		break;
	case MAN_GREEN_RED:
		Red1_On();
		Green_On();
		if(timer1_flag == 1)
		{
			change_mode(0);
			status1=AUTO_GREEN_RED;
			set_road1_time(green_time);
			set_road2_time(red_time);
			setTimer1(green_time);
		}
		if(button_flag[1]  == 1)
		{
			button_flag[1]=0;
			status1=MAN_YELLOW_RED;
			setTimer1(timeout_duration);
		}
		break;
	case MAN_YELLOW_RED:
		Red1_On();
		Yellow_On();
		if(timer1_flag == 1)
		{
			change_mode(0);
			status1=AUTO_YELLOW_RED;
			set_road1_time(yellow_time);
			set_road2_time(yellow_time);
			setTimer1(yellow_time);
		}
		if(button_flag[1]  == 1)
		{
			button_flag[1]=0;
			status1=MAN_RED_GREEN;
			setTimer1(timeout_duration);
		}
		break;
	default:
		break;
	}
}

