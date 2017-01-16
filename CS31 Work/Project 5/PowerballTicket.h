#ifndef POWERBALL_H
#define POWERBALL_H

class PowerballTicket
{

public:
	PowerballTicket (int ball1, int ball2, int ball3, int ball4, int ball5, int Powerball);
	int getBall1();
	int getBall2();
	int getBall3();
	int getBall4();
	int getBall5();
	int getPowerball();

private:
	int mBall1;
	int mBall2;
	int mBall3;
	int mBall4;
	int mBall5;
	int mPowerball;

};

#endif
