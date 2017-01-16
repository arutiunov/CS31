#include "PowerballTicket.h"

// implementation of default contructor function
PowerballTicket::PowerballTicket(int ball1, int ball2, int ball3, int ball4, int ball5, int Powerball)
{
	mBall1 = ball1;
	mBall2 = ball2;
	mBall3 = ball3;
	mBall4 = ball4;
	mBall5 = ball5;
	mPowerball = Powerball;
}

// implementation of getBall methods
int PowerballTicket::getBall1()
{
	return mBall1;
}

int PowerballTicket::getBall2()
{
	return mBall2;
}

int PowerballTicket::getBall3()
{
	return mBall3;
}

int PowerballTicket::getBall4()
{
	return mBall4;
}

int PowerballTicket::getBall5()
{
	return mBall5;
}

int PowerballTicket::getPowerball()
{
	return mPowerball;
}
