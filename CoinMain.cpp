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

int main() {
    
    ///  The first line creates a Coins object called 'pocket.'
    Coins pocket( 100, 10, 10, 100 );
    cout << "I started with " << pocket << " In my pocket." << endl;
    ///  This line creates a Coins object called payForCandy and initializes it.
    Coins payForCandy = pocket.extractChange( CENTS_FOR_CANDYBAR );
    cout << "I bought a candy bar for " << CENTS_FOR_CANDYBAR
    << " cents using " << payForCandy << endl;
    cout << "I have " << pocket << " left in my pocket." << endl;
    
    Coins piggyBank(50,50,50,50);
    pocket.extractChange(68);
    
    cout << "I have bought some chips and now have " << pocket <<endl;
    
    
        cout << "Depositing pocket into piggybank.\n";
    piggyBank.depositChange(49, 5, 8, 8, pocket);

    
    cout << "Piggybank contains  " << piggyBank << endl;
    cout << "Pocket contains " << pocket << endl;
    
    Coins sofa(2,3,5, 20);
    
    cout << "Found " << sofa << " in the sofa" << endl;
    
    sofa.depositChange(pocket);
    
    return 0;
}