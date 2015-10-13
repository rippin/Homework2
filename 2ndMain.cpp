//
//  2ndMain.cpp
//  Homework2
//
//  Created by Eric Franco on 10/7/15.
//  Copyright (c) 2015 Eric Franco. All rights reserved.
//

#include "Coins.h"

using namespace std;

int main() {
    
    Coins pocket(5, 3, 6, 8);
    Coins piggyBank(50,50,50,50);
    pocket.extractChange(68);
    
    cout << "You have bought some chips and now have " << pocket <<endl;
    
    
    
    piggyBank.transfer(49, 20, 30, 8, pocket);
        cout << "Transferring coins.\n";
    
    cout << "Piggybank contains  " << piggyBank << endl;
    cout << "Pocket contains " << pocket << endl;
    
    Coins sofa(2,3,5, 20);
    
    cout << "Found " << sofa << " in the sofa" << endl;
    
    sofa.depositChange(pocket);
}
