#include <iostream>
#include "PowerballTicket.h"
#include "PowerballLottery.h"
#include <cassert>
using namespace std;

int main()
{

	// testing PowerballTicket functions
	PowerballTicket ticket( 1, 2, 3, 4, 5, 6 );
	           assert( ticket.getBall1() == 1);
	           assert( ticket.getBall2() == 2);
	           assert( ticket.getBall3() == 3);
	           assert( ticket.getBall4() == 4);
	           assert( ticket.getBall5() == 5);
	           assert( ticket.getPowerball() == 6);


	// testing PowerballLottery getBall functions
	PowerballLottery lottery( 1, 2, 3, 4, 5, 6 );
			              assert( lottery.getBall1() == 1);
			              assert( lottery.getBall2() == 2);
			              assert( lottery.getBall3() == 3);
			              assert( lottery.getBall4() == 4);
			              assert( lottery.getBall5() == 5);
			              assert( lottery.getPowerball() == 6);
			              assert( lottery.checkTicket(ticket) == PowerballLottery::WinningPossibility::FIVEPLUSPOWERBALL);
			              ticket = PowerballTicket( 1, 2, 3, 4, 5, 12 );
			              assert( lottery.checkTicket(ticket) == PowerballLottery::WinningPossibility::FIVE);
			              ticket = PowerballTicket( 1, 2, 3, 4, 15, 12 );




	// testing PowerballLottery quickPick function
	PowerballTicket quickPickTicket( 1, 2, 3, 4, 5, 6);
            for (int i = 0; i < 20; i++)
            {
                quickPickTicket = lottery.quickPick();
                // all the ball numbers need to be different...
                assert( quickPickTicket.getBall1() != quickPickTicket.getBall2() &&
                        quickPickTicket.getBall1() != quickPickTicket.getBall3() &&
                        quickPickTicket.getBall1() != quickPickTicket.getBall4() &&
                        quickPickTicket.getBall1() != quickPickTicket.getBall5() &&
                        quickPickTicket.getBall2() != quickPickTicket.getBall3() &&
                        quickPickTicket.getBall2() != quickPickTicket.getBall4() &&
                        quickPickTicket.getBall2() != quickPickTicket.getBall5() &&
                        quickPickTicket.getBall3() != quickPickTicket.getBall4() &&
                        quickPickTicket.getBall3() != quickPickTicket.getBall5() &&
                        quickPickTicket.getBall4() != quickPickTicket.getBall5());
           }


		   // testing PREDEFINED PowerballLottery checkTicket & printWhatHappened functions
		   PowerballLottery lotteryA1(1, 2, 3, 4, 5, 6);
		   PowerballTicket ticketA1(1, 2, 3, 4, 5, 6);
		   assert (lotteryA1.checkTicket(ticketA1) == PowerballLottery::WinningPossibility::FIVEPLUSPOWERBALL);
		   lotteryA1.printWhatHappened(ticketA1);

		   	PowerballLottery lotteryA2(1, 2, 3, 4, 5, 7);
			PowerballTicket ticketA2(1, 2, 3, 4, 5, 6);
			assert (lotteryA2.checkTicket(ticketA2) == PowerballLottery::WinningPossibility::FIVE);
			lotteryA2.printWhatHappened(ticketA2);


		PowerballLottery lotteryA3(1, 2, 3, 6, 7, 6);
		PowerballTicket ticketA3(1, 2, 3, 4, 5, 6);
		assert (lotteryA3.checkTicket(ticketA3) == PowerballLottery::WinningPossibility::THREEPLUSPOWERBALL);
		lotteryA3.printWhatHappened(ticketA3);

		PowerballLottery lotteryA4(1, 2, 3, 6, 7, 6);
		PowerballTicket ticketA4(1, 2, 3, 4, 5, 61);
		assert (lotteryA4.checkTicket(ticketA4) == PowerballLottery::WinningPossibility::THREE);
		lotteryA4.printWhatHappened(ticketA4);

		PowerballLottery lotteryA5(1, 2, 3, 6, 7, 61);
		PowerballTicket ticketA5(1, 2, 9, 4, 5, 61);
		assert (lotteryA5.checkTicket(ticketA5) == PowerballLottery::WinningPossibility::TWOPLUSPOWERBALL);
		lotteryA5.printWhatHappened(ticketA5);

		PowerballLottery lotteryA6(1, 2, 3, 6, 7, 61);
		PowerballTicket ticketA6(1, 2, 9, 4, 5, 62);
		assert (lotteryA6.checkTicket(ticketA6) == PowerballLottery::WinningPossibility::NOTWINNING);
		lotteryA6.printWhatHappened(ticketA6);

		PowerballLottery lotteryA7(1, 2, 3, 6, 7, 61);
		PowerballTicket ticketA7(1, 11, 9, 4, 5, 62);
		assert (lotteryA7.checkTicket(ticketA7) == PowerballLottery::WinningPossibility::NOTWINNING);
		lotteryA7.printWhatHappened(ticketA7);


		PowerballLottery lotteryA8(1, 2, 3, 4, 7, 6);
		PowerballTicket ticketA8(1, 2, 3, 4, 5, 6);
		assert (lotteryA8.checkTicket(ticketA8) == PowerballLottery::WinningPossibility::FOURPLUSPOWERBALL);
		lotteryA8.printWhatHappened(ticketA8);

		PowerballLottery lotteryA9(1, 2, 3, 4, 7, 6);
		PowerballTicket ticketA9(1, 2, 3, 4, 5, 61);
		assert (lotteryA9.checkTicket(ticketA9) == PowerballLottery::WinningPossibility::FOUR);
		lotteryA9.printWhatHappened(ticketA9);


		// testing PowerballLottery get functions

		PowerballLottery swagticket(10, 11, 12, 13, 14, 15);
		assert (swagticket.getBall1() == 10);
		assert (swagticket.getBall2() == 11);
		assert (swagticket.getBall3() == 12);
		assert (swagticket.getBall4() == 13);
		assert (swagticket.getBall5() == 14);
		assert (swagticket.getPowerball() == 15);


		// testing PowerballLottery default constructor
		for (int z = 0; z < 20; z++)
		{
		PowerballLottery ticketswag;

		cerr << ticketswag.getBall1() << endl;
		cerr << ticketswag.getBall2() << endl;
		cerr << ticketswag.getBall3() << endl;
		cerr << ticketswag.getBall4() << endl;
		cerr << ticketswag.getBall5() << endl;
		cerr << ticketswag.getPowerball() << endl;
	}


		cerr << "Testing random stuff" << endl;


		// testing RANDOM PowerballLottery checkTicket & printWhatHappened functions
		for (int i=0; i<30; i++){
		PowerballLottery lotteryB1(1, 2, 3, 4, 5, 6);
		PowerballTicket ticketB1(1, 2, 3, 4, 5, 6);
		ticketB1 = lotteryB1.quickPick();
		lotteryB1.printWhatHappened(ticketB1);


		PowerballLottery lotteryB2(1, 2, 3, 4, 5, 6);
		PowerballTicket ticketB2(1, 2, 3, 4, 5, 6);
		ticketB2 = lotteryB2.quickPick();
		lotteryB2.printWhatHappened(ticketB2);


		PowerballLottery lotteryB3(1, 2, 3, 4, 5, 6);
		PowerballTicket ticketB3(1, 2, 3, 4, 5, 6);
		ticketB3 = lotteryB3.quickPick();
		lotteryB3.printWhatHappened(ticketB3);

		}

		   cerr << "all tests passed!" << endl;

          return 0;

}
