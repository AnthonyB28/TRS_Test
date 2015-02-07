////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2010-2011, Turtle Rock Studios.  All rights reserved.
//
//	TRS_Prog_Test.cpp
//  Description: Defines the entry point for the console application.
//
////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Random.h"
#include "Timer.h"
#include "Solutions.h"

int _tmain(int argc, _TCHAR* argv[])
{
	// seed the random number generator
	RandomInitialize();

	// configure the timing system
	TimerInitialize();

	ProblemOne();
	ProblemTwo();
	ProblemThree();
	ProblemFour();
	return 0;
}

