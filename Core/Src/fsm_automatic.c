/*
 * fsm_automatic.h
 *
 *  Created on: Sep 30, 2022
 *      Author: hatru
 */

#include "fsm_automatic.h"
#include "SOFTWARE_TIMER.h"
#include "main.h"
#include "input_reading.h"

void fsm_automatic_run()
{
	switch(status1)
	{
	case INIT:
		status1 = AUTO_RED_GREEN;
		set_road1_time(red_time);
		set_road2_time(green_time);
		setTimer1(green_time);
		setTimer2(1000);
		break;
	case AUTO_RED_GREEN:
		Red_On();
		Green1_On();
		if(timer2_flag == 1)
		{
			count_down_show();
			setTimer2(1000);
		}
		if(timer1_flag == 1)
		{
			status1 = AUTO_RED_YELLOW;
			set_road1_time(yellow_time);
			set_road2_time(yellow_time);
			setTimer1(yellow_time);
		}
		if(button_flag[1] == 1)
		{
			button_flag[1]=0;
			status1 = MAN_RED_GREEN;
			setTimer1(timeout_duration);
		}
		break;
	case AUTO_RED_YELLOW:
		Red_On();
		Yellow1_On();
		if(timer2_flag == 1)
		{
			count_down_show();
			setTimer2(1000);
		}
		if(timer1_flag == 1)
		{
			status1 = AUTO_GREEN_RED;
			set_road1_time(green_time);
			set_road2_time(red_time);
			setTimer1(green_time);
		}
			if(button_flag[1] == 1)
		{

			button_flag[1]=0;
			status1 = MAN_RED_YELLOW;
			setTimer1(timeout_duration);
		}
		break;
	case AUTO_GREEN_RED:
		Red1_On();
		Green_On();
		if(timer2_flag == 1)
		{
			count_down_show();
			setTimer2(1000);
		}
		if(timer1_flag == 1)
		{
			status1 = AUTO_YELLOW_RED;
			set_road1_time(yellow_time);
			set_road2_time(yellow_time);
			setTimer1(yellow_time);
		}
		if(button_flag[1] == 1)
		{

			button_flag[1]=0;
			status1 = MAN_GREEN_RED;
			setTimer1(timeout_duration);
		}
		break;
	case AUTO_YELLOW_RED:
		Red1_On();
		Yellow_On();
		if(timer2_flag == 1)
		{
			count_down_show();
			setTimer2(1000);
		}
		if(timer1_flag == 1)
		{
			status1 = AUTO_RED_GREEN;
			set_road1_time(red_time);
			set_road2_time(green_time);
			setTimer1(green_time);
		}
				if(button_flag[1] == 1)
		{

			button_flag[1]=0;
			status1 = MAN_YELLOW_RED;
			setTimer1(timeout_duration);
		}
		break;
	default:
		break;
	}
}
