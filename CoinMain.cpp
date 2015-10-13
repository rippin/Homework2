//
//  CoinMain.cpp
//  Homework2
//
//  Created by Eric Franco on 10/7/15.
//  Copyright (c) 2015 Eric Franco. All rights reserved.
//

// CoinMain.cpp  /// The name of this file
#include "Coins.h"
#include <iostream>
const int CENTS_FOR_CANDYBAR = 482;
using namespace std;

int main()
{
    ///  The first line creates a Coins object called 'pocket.'
    Coins pocket( 100, 10, 10, 100 );
    cout << "I started with " << pocket << " in my pocket" << endl;
    ///  This line creates a Coins object called payForCandy and initializes it.
    Coins payForCandy = pocket.extractChange( CENTS_FOR_CANDYBAR );
    cout << "I bought a candy bar for " << CENTS_FOR_CANDYBAR
    << " cents using " << payForCandy << endl;
    cout << "I have " << pocket << " left in my pocket." << endl;
    return 0;
}
