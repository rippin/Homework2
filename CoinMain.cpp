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

using namespace std;

int main() {
    
    Coins pocket(5, 3, 6, 8);
    Coins piggyBank(50,50,50,50);
    pocket.extractChange(68);
    
    cout << "I have bought some chips and now have " << pocket << " in my pocket." << endl;
    
    cout << "Depositing from piggybank into pocket.\n";
    
    pocket.depositChange(20, 5, 8, 8, piggyBank);

    
    cout << "Piggybank contains " << piggyBank << endl;
    cout << "Pocket contains " << pocket << endl;
    
    Coins sofa(2,3,5, 20);
    
    cout << "Found " << sofa << " in the sofa" << endl;
    
    piggyBank.depositChange(sofa);
        cout << "Depositing sofa into piggybank which now contains  " << piggyBank << endl;
    
    return 0;
}