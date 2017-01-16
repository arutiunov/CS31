//
//  Game.cpp
//  HandHomework
//
//  Created by Howard Stahl on 12/6/15.
//  Copyright © 2015 Howard Stahl. All rights reserved.
//

#include "Game.h"
#include "RandomNumber.h"
#include <iostream>

// CS 31 Students need to complete this class.
// Please read over the assignment and the TODO comments in the accompanying
// implementation file for further instructions.
namespace cs31
{

// default contructor
Game::Game()
{
	mOutcome = NOOUTCOME;
	mPlayerStood = false;
}

// constructor with two players passed as the parameters
Game::Game( Player player, Player dealer ) : Game( )
{
    mPlayer = player;
    mDealer = dealer;
}

// did the Player win?
bool Game::playerWon()
{
    return( mOutcome == PLAYERWON );
}

// did the Player lose?
bool Game::playerLost()
{
    return( mOutcome == PLAYERLOST );
}

// did the Player and the Dealer tie?
bool Game::playerTied( )
{
        return( mOutcome == TIED );
}

void Game::deal()
{
	mDeck.shuffleDeck(); // call method of object mDeck

	for (int i = 0; i < 2; i++)
	{
		mPlayer.acceptCard(mDeck.dealCard()); // each player starts out with two cards
	}

	for (int j = 0; j < 2; j++)
	{
		mDealer.acceptCard(mDeck.dealCard());
	}

}

void Game::playerHits( )
{
	mPlayer.acceptCard(mDeck.dealCard()); // call method of object mDeck
}

// let the Game know that the Player's turn is over
void Game::playerStands()
{
    mPlayerStood = true;
}

// has the Player's turn ended?
bool Game::playerStood() const
{
    return( mPlayerStood );
}

void Game::dealerHits( )
{
	mDealer.acceptCard(mDeck.dealCard());
}
    
// various situations of who has larger handcount

void Game::dealerStands( )
{
if (mPlayer.handcount() < mDealer.handcount() && !playerBusted() && !dealerBusted())
		mOutcome = PLAYERLOST;

if (mPlayer.handcount() == mDealer.handcount() && !playerBusted() && !dealerBusted())
	mOutcome = TIED;

if (mPlayer.handcount() > mDealer.handcount() && !playerBusted() && !dealerBusted())
	mOutcome = PLAYERWON;

if (playerBusted())
	mOutcome = PLAYERLOST;

if (dealerBusted())
	mOutcome = PLAYERWON;
    
if (playerHasBlackJack() && dealerHasBlackJack())
    mOutcome = TIED;

if (playerBusted() && dealerBusted())
    mOutcome = PLAYERLOST;
    
}
    
// if handcount greater than 21
bool Game::dealerBusted( ) const
{
    bool result = false;
	if (mDealer.handcount() > 21)
		result = true;

    return( result );
}

bool Game::playerBusted( ) const
{
	bool result = false;
	if (mPlayer.handcount() > 21)
		result = true;

    return( result );
}
    
    // dealer plays until he gets to at least 17 

void Game::dealerPlays()
{
	if (playerBusted() == false)
	{
		while (mDealer.handcount() < 17)
		{
			mDealer.acceptCard(mDeck.dealCard());
			if (dealerBusted() == true)
				playerWon();
		}
	}
    // let the Game know that play has ended
    dealerStands();
}

bool Game::playerHasBlackJack( ) const
{
	bool result = false;
	if (mPlayer.hasBlackJack() == true)
	{
		result = true;
	}
    return( result );
}

bool Game::dealerHasBlackJack( ) const
{
    bool result = false;
	if (mDealer.hasBlackJack() == true)
	{
		result = true;
	}
    return( result );
}

//
// ALL THE CODE BELOW THIS POINT SHOULD NOT BE CHANGED!
//
void Game::display( std::string s , bool allCards )
{
    // when allCards is true  --> show all dealer cards
    // otherwise just show the one turned up dealer card
    // and then display the passed message at the bottom of the screen, if supplied
    using namespace std;
    int dealerCount = mDealer.handcount();
    int playerCount = mPlayer.handcount();
    cout << "DEALER'S HAND:" << endl;
    if (allCards)
    {
        cout << mDealer << endl;
    }
    else
    {
        cout << mDealer.getCard(0) << endl;
    }
    if (dealerBusted())
    {
        cout << "          --->dealer busted!" << endl;
    }
    else if (allCards)
    {
        cout << "          --->" << dealerCount << endl;
    }
    cout << endl;
    cout << "PLAYER'S HAND:" << endl;
    cout << mPlayer << endl;
    if (playerBusted())
    {
        cout << "          --->player busted!" << endl;
    }
    else if (allCards)
    {
        cout << "          --->" << playerCount << endl;
    }

    if (s != "")
        cout << s << endl;
}




}
