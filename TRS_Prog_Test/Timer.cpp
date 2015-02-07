////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2010-2011, Turtle Rock Studios.  All rights reserved.
//
//	Timer.cpp
//  Description: implementation of timer functionality
//
////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include "Timer.h"


// variable that receives the current performance-counter frequency, in counts per second. 
static LARGE_INTEGER s_liFreq;

// variable that holds the initial value of the high-resolution performance counter
static LARGE_INTEGER s_liInitialCount;

static double s_flPcFreq = 0.0;	// perf frequency as double



void TimerInitialize()
{
	// Retrieves the frequency of the high-resolution performance counter, if one exists. 
	// The frequency cannot change while the system is running.
	QueryPerformanceFrequency( &s_liFreq );

	s_flPcFreq = ((double)s_liFreq.QuadPart);


	QueryPerformanceCounter( &s_liInitialCount );
}

double TimerGetTime64()
{
	LARGE_INTEGER li;

	// Retrieves the current value of the high-resolution performance counter.
	QueryPerformanceCounter( &li );
	
	return ((double)(li.QuadPart-s_liInitialCount.QuadPart)) / s_flPcFreq;
}

float TimerGetTime32()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter( &li );

	return (float) (((double) (li.QuadPart-s_liInitialCount.QuadPart)) / s_flPcFreq);
}