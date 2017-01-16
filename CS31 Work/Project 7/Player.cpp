//
//  Hand.cpp
//  HandHomework
//
//  Created by Howard Stahl on 4/30/15.
//  Copyright (c) 2015 Howard Stahl. All rights reserved.
//

#include "Player.h"
#include <stdexcept>
#include "Deck.h"

// CS 31 Students need to complete this class.
// Please read over the assignment and the TODO comments in the accompanying
// implementation file for further instructions.
namespace cs31
{

Player::Player( )
{
    // The Player has no Cards in his hand
    myNumberOfCards = 0;
}

    // overriding operator
std::ostream& operator <<( std::ostream& outs, const Player & p )
{

    for (int i = 0; i < p.myNumberOfCards; i++)
    {
        std::cout << p.myCards[i] << std::endl;
    }
    return( outs );
}

    // exception if number of cards greater than 12
void Player::acceptCard(Card c)
{
    if (myNumberOfCards >= 12)
    {
        std::logic_error room ("Not enough space for another card!");
        throw (room);
    }
    else
	{
        myCards[myNumberOfCards] = c;
		myNumberOfCards++;
	}
}

Card Player::getCard( int index ) const
{
    Card c;

    if (index > 11 || index < 0)
    {
        std::logic_error badindex ("This index is invalid.");
        throw (badindex);
    }

    else
    {
        c = myCards[index];
        return( c );
    }
}

int  Player::handcount( ) const
{
    int total = 0;
    for (int i = 0; i <myNumberOfCards; i++){
        total = total + myCards[i].count();
    }
    for (int i = 0; i < myNumberOfCards; i++)
    {
        if (myCards[i].getFace() == ACE && total <= 11)
            total = total + 10;
    }
    return total;
}

//	int total = 0;
//	Card A;
//	for (int k = 0; k < myNumberOfCards; k++)
//	{
//		A = myCards[k]; // assigns card from array to card A
//		if (A.getFace() == ACE)
//		{
//			if (total + 11 <= 21)
//				total = total + 11;
//			else
//				total = total + 1;
//		}
//		else
//			total += A.count();
//	}
//    return( total );
//}
    
    
    
    
int Player::cardCount()
{
    return myNumberOfCards;
}



bool Player::hasBlackJack( ) const
{
    bool result = false;
    if (myNumberOfCards == 2 && handcount() == 21)
    {
        result = true;
    }
    return( result );
}

}
