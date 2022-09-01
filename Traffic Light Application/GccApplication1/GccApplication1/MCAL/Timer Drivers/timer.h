/*
 * timer.h
 *
 * Created: 28/08/2022 01:36:09 م
 *  Author: THE HAG
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../UTIL/Types.h"
#include "../../UTIL/register.h"
#include <math.h>
void Timer_init();
void Delay_IN_SEC(int delay);
void Delay_IN_MSEC(int delay);

#endif /* TIMER_H_ */