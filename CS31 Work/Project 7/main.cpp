 // main.cpp
 // HandHomework
 //
 // Created by Howard Stahl on 4/30/15.
 // Copyright (c) 2015 Howard Stahl. All rights reserved.

//
//#include <iostream>
//#include <string>
//#include "Card.h"
//#include "Deck.h"
//#include "Game.h"
//#include <cassert>
//void clearScreen();
//
//
//
//int main(int argc, const char * argv[])
//{
//
//    using namespace cs31;
//    using namespace std;
//    string action;
//
//    Game g;
//    g.deal();
//    clearScreen();
//    if (g.playerHasBlackJack() || g.dealerHasBlackJack())
//    {
//        g.playerStands();
//        g.dealerStands();
//    }
//    else
//    {
//        do
//        {
//            g.display( "(h)it (s)tand or (q)uit:" );
//            getline( cin, action );
//            if (action.size() == 0)
//            {
//                g.playerStands();
//            }
//            else
//            {
//                switch (action[0])
//                {
//                    default:   // if bad move, nobody moves
//                        cout << '\a' << endl;  // beep
//                        continue;
//                    case 'Q':
//                    case 'q':
//                        return 0;
//                    case 'h':
//                    case 'H':
//                        g.playerHits();
//                        clearScreen();
//                        break;
//                    case 's':
//                    case 'S':
//                        g.playerStands();
//                        break;
//                }
//            }
//        } while( !g.playerBusted() && !g.playerStood() );
//
//        clearScreen();
//        g.dealerPlays();
//    }
//
//    if (g.playerWon())
//    {
//        g.display( "WON!", true );
//    }
//    else if (g.playerLost())
//    {
//        g.display( "LOST!", true );
//    }
//    else
//    {
//        g.display( "TIED!", true );
//    }
//
//
//
//    return 0;
//}
//
//
//
/////////////////////////////////////////////////////////////////////////////
////  clearScreen implementations
/////////////////////////////////////////////////////////////////////////////
//
//// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
//// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.
//
//// Note to Xcode users:  clearScreen() will just write a newline instead
//// of clearing the window if you launch your program from within Xcode.
//// That's acceptable.
//
//#ifdef _MSC_VER  //  Microsoft Visual C++
//
//#include <windows.h>
//
//void clearScreen()
//{
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_SCREEN_BUFFER_INFO csbi;
//    GetConsoleScreenBufferInfo(hConsole, &csbi);
//    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
//    COORD upperLeft = { 0, 0 };
//    DWORD dwCharsWritten;
//    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
//                               &dwCharsWritten);
//    SetConsoleCursorPosition(hConsole, upperLeft);
//}
//
//#else  // not Microsoft Visual C++, so assume UNIX interface
//
//#include <cstring>
//
//void clearScreen()  // will just write a newline in an Xcode output window
//{
//    using namespace std;
//    static const char* term = getenv("TERM");
//    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
//    {
//        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
//    }
//    else
//    {
//        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
//        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
//    }
//}
//
//#endif


#include <iostream>
#include <string>
#include <cassert>
#include "Game.h"
#include "Player.h"
#include "Card.h"

// using namespace std;
//
// int main()
// {
// 	   using namespace std;
// 	   using namespace cs31;
//
// 	   // Howard's test code
// 	   Player p;
//
// 	   Card c( Face::ACE, Suit::DIAMONDS );
// 	   Card d( Face::TEN, Suit::CLUBS );
// 	   Card e( Face::THREE, Suit::SPADES );
// 	   Card f( Face::EIGHT, Suit::HEARTS );
//
// 	   assert( p.handcount() == 0 );
// 	   assert( p.hasBlackJack() == false );
// 	   assert( p.cardCount() == 0 );
// 	   p.acceptCard( c );
// 	   assert( p.handcount() == 11 );
// 	   assert( p.hasBlackJack() == false );
// 	   assert( p.cardCount() == 1 );
// 	   assert( p.getCard(0) == c);
// 	   p.acceptCard( d );
// 	   assert( p.handcount() == 21 );
// 	   assert( p.hasBlackJack() == true );
//
//
// 	   p = Player();
// 	   Player dealer;
// 	   Game g( p, dealer );
// 	   g.playerStands();
// 	   g.dealerStands();
// 	   assert( g.dealerBusted()==false );
// 	   assert( g.playerBusted()==false );
// 	   assert( g.playerTied() == true );
// 	   assert( g.playerWon() == false );
// 	   assert( g.playerLost() == false );
// 	   assert( g.playerHasBlackJack() == false );
// 	   assert( g.dealerHasBlackJack() == false );
//
//
// 	   p = Player( );
// 	   p.acceptCard( c );
// 	   p.acceptCard( d );
// 	   dealer = Player( );
// 	   dealer.acceptCard( e );
// 	   dealer.acceptCard( f );
// 	   g = Game( p, dealer );
// 	   g.playerStands();
// 	   g.dealerStands();
// 	   assert( g.dealerBusted()==false );
// 	   assert( g.playerBusted()==false );
// 	   assert( g.playerTied() == false );
// 	   assert( g.playerWon() == true );
// 	   assert( g.playerLost() == false );
// 	   assert( g.playerHasBlackJack() == true );
// 	   assert( g.dealerHasBlackJack() == false );
//     
//    
//     
//        // Artiom's test code
//     
//        Player Artiom;
//        Card j (Face::KING, Suit::DIAMONDS );
//        Card j2 (Face::DEUCE, Suit::HEARTS);
//        Card j3 (Face::EIGHT, Suit::CLUBS);
//        Card j4 (Face::ACE, Suit::SPADES);
//        Card j5 (Face::ACE, Suit::HEARTS);
//        Card j6 (Face::ACE, Suit::CLUBS);
//        Card j7 (Face::ACE, Suit::DIAMONDS);
//        Card j8 (Face::FIVE, Suit::DIAMONDS);
//        Card j9 (Face::THREE, Suit::HEARTS);
//        Card j10 (Face::FOUR, Suit::SPADES);
//     
//        // testing the value of multiple aces
//     
//        Artiom.acceptCard(j4);
//        Artiom.acceptCard(j5);
//        Artiom.acceptCard(j6);
//        Artiom.acceptCard(j7);
//     
//        assert( Artiom.handcount() == 14);
//     
//    // testing the logic errors
//     
//     Player Artiom2;
//     
//     try
//     {
//         for (int i = 0; i <= 13; i++)
//         {
//         Artiom2.acceptCard(j);
//         }
//     }
//     
//     
//     catch (std::logic_error room )
//     {
//         cerr << "Not enough space for another card!" << endl;
//     }
//     
//     
//     try
//     {
//         Artiom2.getCard(12);
//     }
//     
//     catch (std::logic_error badindex)
//     {
//         cerr << "This index is invalid." << endl;
//     }
//     
//     
//     
//     
//     // testing various scenarios
//     
//     //testing for default player loss if both bust
//     
//     Player artiom3;
//     Player dealer2;
//     artiom3.acceptCard(j);
//     artiom3.acceptCard(j3);
//     artiom3.acceptCard(j8);
//     dealer2.acceptCard(j);
//     dealer2.acceptCard(j3);
//     dealer2.acceptCard(j8);
//     assert (artiom3.handcount() == 23);
//     assert(dealer2.handcount() == 23);
//     
//     Game g2 (artiom3, dealer2);
//
//     assert( g2.playerBusted() == true);
//     assert( g2.dealerBusted() == true);
//     g2.playerStands();
//     g2.dealerStands();
//     assert( g2.playerLost() == true);
//     
//     // testing for normal player wins scenario
//     
//     Player artiom4;
//     Player dealer3;
//     artiom4.acceptCard(j9);
//     artiom4.acceptCard(j);
//     artiom4.acceptCard(j3);
//     dealer3.acceptCard(j);
//     dealer3.acceptCard(j3);
//     
//     Game g3 (artiom4, dealer3);
//     
//     g3.playerStands();
//     g3.dealerStands();
//     
//     assert(g3.playerWon() == true);
//     
//     
//     // testing for normal dealer wins scenario (with blackjack)
//     
//     
//     Player artiom5;
//     Player dealer4;
//     artiom5.acceptCard(j);
//     artiom5.acceptCard(j9);
//     artiom4.acceptCard(j10);
//     dealer4.acceptCard(j);
//     dealer4.acceptCard(j7);
//     
//     Game g4 (artiom5, dealer4);
//     
//     g4.playerStands();
//     g4.dealerStands();
//     
//     assert(g4.playerHasBlackJack() == false);
//     assert(g4.dealerHasBlackJack() == true);
//     
//     assert(g4.playerLost() == true);
//     
//     
//     // testing for player winning with blackjack
//     
//     Player artiom6;
//     Player dealer5;
//     artiom6.acceptCard(j);
//     artiom6.acceptCard(j4);
//     dealer5.acceptCard(j);
//     dealer5.acceptCard(j9);
//     dealer5.acceptCard(j10);
//
//     
//     Game g5 (artiom6, dealer5);
//     
//     g5.playerStands();
//     g5.dealerStands();
//     
//     assert(g5.playerHasBlackJack() == true);
//     assert(g5.dealerHasBlackJack() == false);
//     
//     assert(g5.playerWon() == true);
//
//     // testing for both getting blackjack
//     
//     Player artiom7;
//     Player dealer6;
//     artiom7.acceptCard(j);
//     artiom7.acceptCard(j4);
//     dealer6.acceptCard(j);
//     dealer6.acceptCard(j5);
//     
//     Game g6 (artiom7, dealer6);
//     
//     g6.playerStands();
//     g6.dealerStands();
//     
//     assert(g6.playerHasBlackJack() == true);
//     assert(g6.dealerHasBlackJack() == true);
//     assert(g6.playerTied() == true);
//     
//     // testing the getCard functions
//     
//     Card i2 = p.getCard(0);
//     cerr << i2 << endl;
//     i2 = p.getCard(1);
//     cerr << i2 << endl;
//     i2 = dealer.getCard(0);
//     cerr << i2 << endl;
//     i2 = dealer.getCard(1);
//     cerr << i2 << endl;
//     
//     Card i = p.getCard(0);
//     
//     cout << i << endl;
//     
//     i = p.getCard(1);
//     
//     cout << i << endl;
//     
//     i = dealer.getCard(0);
//     
//     cout << i << endl;
//     
//     i = dealer.getCard(1);
//     
//     cout << i << endl;
//     
//     
//     cerr << "all tests passed!" << endl;
// 	   return 0;
//     
//
// }
//
#include <iostream>
#include <string>
#include <cassert>
#include "Game.h"
#include "Player.h"
#include "Card.h"
#include "Deck.h"
void testone(int n)
{
    using namespace cs31;
    using namespace std;
    
    Player p;  Player dealer;   Game g( p, dealer );
    Card c( Face::ACE, Suit::DIAMONDS );
    Card d( Face::TEN, Suit::CLUBS );
    Card e( Face::THREE, Suit::SPADES );
    Card f( Face::EIGHT, Suit::HEARTS );
    Card h( Face::DEUCE, Suit::DIAMONDS );
    Card i( Face::FOUR, Suit::CLUBS );
    Card j( Face::FIVE, Suit::SPADES );
    Card k( Face::SIX, Suit::HEARTS );
    
    int countWins = 0, countLosses = 0, countTies = 0;
    
    switch (n)
    {
        case  1:
            
            assert( p.handcount() == 0 );
            assert( p.hasBlackJack() == false );
            assert( p.cardCount() == 0 );
            break;
            
        case 2:
            p.acceptCard( c );
            assert( p.handcount() == 11 );
            assert( p.hasBlackJack() == false );
            assert( p.cardCount() == 1 );
            assert( p.getCard(0) == c);
            break;
            
        case 3:
            p.acceptCard( c );
            p.acceptCard( d );
            assert( p.handcount() == 21 );
            assert( p.hasBlackJack() == true );
            assert( p.cardCount() == 2 );
            assert( p.getCard(0) == c);
            assert( p.getCard(1) == d);
            break;
        case 4:
            
            p.acceptCard( c );
            p.acceptCard( d );
            p.acceptCard( e );
            assert( p.handcount() == 14 );
            assert( p.hasBlackJack() == false );
            assert( p.cardCount() == 3 );
            assert( p.getCard(0) == c);
            assert( p.getCard(1) == d);
            assert( p.getCard(2) == e);
            break;
            
        case 5:
            p.acceptCard( c );
            p.acceptCard( d );
            p.acceptCard( e );
            p.acceptCard( f );
            assert( p.handcount() == 22 );
            assert( p.hasBlackJack() == false );
            assert( p.cardCount() == 4 );
            assert( p.getCard(0) == c);
            assert( p.getCard(1) == d);
            assert( p.getCard(2) == e);
            assert( p.getCard(3) == f);
            break;
            
        case 6:
            g.dealerStands();
            assert( g.dealerBusted()==false );
            assert( g.playerBusted()==false );
            assert( g.playerTied() == true );
            assert( g.playerWon() == false );
            assert( g.playerLost() == false );
            assert( g.playerHasBlackJack() == false );
            assert( g.dealerHasBlackJack() == false );
            break;
            
        case 7:
            p.acceptCard( c );
            p.acceptCard( d );
            dealer.acceptCard( e );
            dealer.acceptCard( f );
            g = Game( p, dealer );
            g.playerStands();
            g.dealerStands();
            assert( g.dealerBusted()==false );
            assert( g.playerBusted()==false );
            assert( g.playerTied() == false );
            assert( g.playerWon() == true );
            assert( g.playerLost() == false );
            assert( g.playerHasBlackJack() == true );
            assert( g.dealerHasBlackJack() == false );
            break;
            
        case 8:
            p.acceptCard( e );
            p.acceptCard( f );
            dealer.acceptCard( c );
            dealer.acceptCard( d );
            g = Game( p, dealer );
            g.playerStands();
            g.dealerStands();
            assert( g.dealerBusted()==false );
            assert( g.playerBusted()==false );
            assert( g.playerTied() == false );
            assert( g.playerWon() == false );
            assert( g.playerLost() == true );
            assert( g.playerHasBlackJack() == false );
            assert( g.dealerHasBlackJack() == true );
            break;
            
        case 9:
            p.acceptCard( e );
            p.acceptCard( f );
            p.acceptCard( c );
            p.acceptCard( d );
            g = Game( p, dealer );
            g.playerStands();
            g.dealerStands();
            assert( g.dealerBusted()==false );
            assert( g.playerBusted()==true );
            assert( g.playerTied() == false );
            assert( g.playerWon() == false );
            assert( g.playerLost() == true );
            assert( g.playerHasBlackJack() == false );
            assert( g.dealerHasBlackJack() == false );
            break;
            
        case 10:
            p.acceptCard( e );
            p.acceptCard( f );
            dealer.acceptCard( e );
            dealer.acceptCard( f );
            dealer.acceptCard( c );
            dealer.acceptCard( d );
            g = Game( p, dealer );
            g.playerStands();
            g.dealerStands();
            assert( g.dealerBusted()==true );
            assert( g.playerBusted()==false );
            assert( g.playerTied() == false );
            assert( g.playerWon() == true );
            assert( g.playerLost() == false );
            assert( g.playerHasBlackJack() == false );
            assert( g.dealerHasBlackJack() == false );
            break;
            
        case 11:
            p.acceptCard( e );
            p.acceptCard( c );
            p.acceptCard( h );
            p.acceptCard( i );
            p.acceptCard( j );
            p.acceptCard( k );
            dealer.acceptCard( d );
            dealer.acceptCard( f );
            g = Game( p, dealer );
            g.playerStands();
            g.dealerStands();
            assert( g.dealerBusted()==false );
            assert( g.playerBusted()==false );
            assert( g.playerTied() == false );
            assert( g.playerWon() == true );
            assert( g.playerLost() == false );
            assert( g.playerHasBlackJack() == false );
            assert( g.dealerHasBlackJack() == false );
            break;
            
            
        case 12:
            dealer.acceptCard( e );
            dealer.acceptCard( c );
            dealer.acceptCard( h );
            dealer.acceptCard( i );
            dealer.acceptCard( j );
            dealer.acceptCard( k );
            p.acceptCard( d );
            p.acceptCard( f );
            g = Game( p, dealer );
            g.playerStands();
            g.dealerStands();
            assert( g.dealerBusted()==false );
            assert( g.playerBusted()==false );
            assert( g.playerTied() == false );
            assert( g.playerWon() == false );
            assert( g.playerLost() == true );
            assert( g.playerHasBlackJack() == false );
            assert( g.dealerHasBlackJack() == false );
            break;
            
        case 13:
            dealer.acceptCard( e );
            dealer.acceptCard( c );
            dealer.acceptCard( h );
            dealer.acceptCard( i );
            dealer.acceptCard( j );
            dealer.acceptCard( k );
            dealer.acceptCard( d );
            p.acceptCard( f );
            g = Game( p, dealer );
            g.playerStands();
            g.dealerStands();
            assert( g.dealerBusted()==true );
            assert( g.playerBusted()==false );
            assert( g.playerTied() == false );
            assert( g.playerWon() == true );
            assert( g.playerLost() == false );
            assert( g.playerHasBlackJack() == false );
            assert( g.dealerHasBlackJack() == false );
            break;
            
        case 14:
            p.acceptCard( e );
            p.acceptCard( c );
            p.acceptCard( h );
            p.acceptCard( i );
            p.acceptCard( j );
            p.acceptCard( k );
            p.acceptCard( d );
            dealer.acceptCard( f );
            g = Game( p, dealer );
            g.playerStands();
            g.dealerStands();
            assert( g.dealerBusted()==false );
            assert( g.playerBusted()==true );
            assert( g.playerTied() == false );
            assert( g.playerWon() == false );
            assert( g.playerLost() == true );
            assert( g.playerHasBlackJack() == false );
            assert( g.dealerHasBlackJack() == false );
            break;
            
            
        case 15:
            for (int z = 1; z <= 1000; z++)
            {
                g = Game();
                g.deal();
                g.playerStands();
                g.dealerPlays();
                if (g.playerWon())
                    countWins++;
                if (g.playerLost())
                    countLosses++;
                if (g.playerTied())
                    countTies++;
            }
            
            assert( (countWins + countLosses + countTies) == 1000 );
            assert( countWins > 1 );
            assert( countLosses > 1 );
            assert( countTies > 1 );
            break;
            
            
        case 16:
            for (int z = 1; z <= 1000; z++)
            {
                g = Game( );
                g.deal();
                g.playerHits();
                g.playerStands();
                g.dealerPlays();
                if (g.playerWon())
                    countWins++;
                if (g.playerLost())
                    countLosses++;
                if (g.playerTied())
                    countTies++;
            }
            
            assert( (countWins + countLosses + countTies) == 1000 );
            assert( countWins > 1 );
            assert( countLosses > 1 );
            assert( countTies > 1 );
            
            break;
            
            
            
        default:
            cout << "Bad argument" << endl;
            break;
    }
}

int main()
{
    
    using namespace std;
    cout << "Enter test number: ";
    int n;
    cin >> n;
    testone(n);
    cout << "Passed!" << endl;
}