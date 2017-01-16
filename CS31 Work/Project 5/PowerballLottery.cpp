#include "PowerballLottery.h"
#include "RandomNumber.h"
#include "PowerballTicket.h"
#include <iostream>
using namespace std;

// function implementation for default contructor PowerballLottery
PowerballLottery::PowerballLottery()
{
// creating 6 distinct objects of class RandomNumber to ensure that there are no copies
RandomNumber random(1, 69);
RandomNumber random2(1, 69);
RandomNumber random3(1, 69);
RandomNumber random4(1, 69);
RandomNumber random5(1, 69);
RandomNumber random6(1, 26);

mBall1 = random.random();
mBall2 = random2.random();

while (mBall2 == mBall1) // keeps on randomizing until not the same
{
	mBall2 = random2.random();
}

mBall3 = random3.random();

while (mBall3 == mBall2 || mBall3 == mBall1) // keeps on randomizing until not the same
{
	mBall3 = random3.random();
}

mBall4 = random4.random();

while (mBall4 == mBall1 || mBall4 == mBall2 || mBall4 == mBall3 ) // keeps on randomizing until not the same
{
	mBall4 = random4.random();
}

mBall5 = random5.random();

while (mBall5 == mBall1 || mBall5 == mBall2 || mBall5 == mBall3 || mBall5 == mBall4) // keeps on randomizing until not the same
{
	mBall5 = random5.random();
}

mPowerball = random6.random();

}

// constructor if parameters are already passed (assures there are 6 parameters)
PowerballLottery::PowerballLottery(int ball1, int ball2, int ball3, int ball4, int ball5, int powerball)
{
	mBall1 = ball1;
	mBall2 = ball2;
	mBall3 = ball3;
	mBall4 = ball4;
	mBall5 = ball5;
	mPowerball = powerball;
}

// implementation of quickPick functions
PowerballTicket PowerballLottery::quickPick()
{
	PowerballLottery substitute_ticket; // creates object of PowerballLottery to access default constructor + getball method
	PowerballTicket ticket(substitute_ticket.getBall1(), substitute_ticket.getBall2(), substitute_ticket.getBall3(),
						substitute_ticket.getBall4(), substitute_ticket.getBall5(), substitute_ticket.getPowerball());

	return ticket;
}

// implementation of checkTicket method of PowerballLottery which returns type WinningPossibility (enumeration)
PowerballLottery::WinningPossibility PowerballLottery::checkTicket( PowerballTicket ticket )
{
int counter = 0;
int counter2 = 0;
int Lottery_Ticket[6] = {ticket.getBall1(), ticket.getBall2(), ticket.getBall3(),
						ticket.getBall4(), ticket.getBall5(), ticket.getPowerball()}; // array of random numbers

int Winning_Numbers[6] = {getBall1(), getBall2(), getBall3(), getBall4(), getBall5(), getPowerball()}; //calls accesor function

for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i < 5; i++)
			if (Lottery_Ticket[k] == Winning_Numbers[i])
				counter++;
	}

if (Lottery_Ticket[5] == Winning_Numbers[5])
	counter2++;

// possibilities of NOTWINNING
if (counter == 0 && counter2 == 0)
	return NOTWINNING;

if (counter == 1 && counter2 == 0)
	return NOTWINNING;

if (counter == 2 && counter2 == 0)
	return NOTWINNING;


// various possibilites
if (counter == 0 && counter2 == 1)
	return POWERBALL;

if (counter == 1 && counter2 == 1)
	return ONEPLUSPOWERBALL;

if (counter == 2 && counter2 == 1)
	return TWOPLUSPOWERBALL;

if (counter == 3 && counter2 == 0)
	return THREE;

if (counter == 3 && counter2 == 1)
	return THREEPLUSPOWERBALL;

if (counter == 4  && counter2 == 0)
	return FOUR;

if (counter == 4 && counter2 == 1)
	return FOURPLUSPOWERBALL;

if (counter == 5 && counter2 == 0)
	return FIVE;

if (counter == 5 && counter2 == 1)
	return FIVEPLUSPOWERBALL;

return NOTWINNING; // default return
}

// implementation of function printWhatHappened
void PowerballLottery::printWhatHappened( PowerballTicket ticket )
{
	if (checkTicket (ticket) == POWERBALL)
		cout << "You matched just the powerball. Congratulations!" << endl;
	if (checkTicket (ticket) == NOTWINNING)
		cout << "You didn't win anything. Please buy another ticket!" << endl;
	if (checkTicket (ticket) == ONEPLUSPOWERBALL)
		cout << "You matched one ball plus the powerball. Congratulations!" << endl;
	if (checkTicket (ticket) == TWOPLUSPOWERBALL)
		cout << "You matched two balls plus the powerball. Congratulations!" << endl;
	if (checkTicket (ticket) == THREE)
		cout << "You matched three balls but not the powerball. Congratulations!" << endl;
	if (checkTicket (ticket) == THREEPLUSPOWERBALL)
		cout << "You matched three balls plus the powerball. Congratulations!" << endl;
	if (checkTicket (ticket) == FOUR)
		cout << "You matched four balls plus the powerball. Congratulations!" << endl;
	if (checkTicket (ticket) == FOURPLUSPOWERBALL)
		cout << "You matched four balls but not the powerball. Congratulations!" << endl;
	if (checkTicket (ticket) == FIVE)
		cout << "You matched five balls but not the powerball. Congratulations!" << endl;
	if (checkTicket (ticket) == FIVEPLUSPOWERBALL)
		cout << "You won the jackpot - all balls plus the powerball. Congratulations!" << endl;

}

// implementation of functions getBall
int PowerballLottery::getBall1()
{
	return mBall1;
}
int PowerballLottery::getBall2()
{
	return mBall2;
}
int PowerballLottery::getBall3()
{
	return mBall3;
}
int PowerballLottery::getBall4()
{
	return mBall4;
}
int PowerballLottery::getBall5()
{
	return mBall5;
}
int PowerballLottery::getPowerball()
{
	return mPowerball;
}
