//
//  MenuMain.cpp
//  Homework2
//
//  Created by Eric Franco on 10/12/15.
//  Copyright (c) 2015 Eric Franco. All rights reserved.
//

#include <iostream>
#include "Coins.h"

using namespace std;
void printMainMenu();
void printDepositMenu();

    int main(){
        int input;
        Coins myCoins(10, 5, 3, 4);
        printMainMenu();
        while (cin >> input){
            
            switch (input){
                case 1 :
                {
                    printDepositMenu();
                    int input2;
                    cin >> input2;
                    int i = 0;
                      switch(input2) {
                          case 1 :
                          {
                              cout << "Please enter an integer amount of quarters you would like to deposit.\n";
                              cin >> i;
                              Coins c(i,0,0,0);
                              myCoins.depositChange(c);
                              break;
                          }
                          case 2 :
                          {
                              cout << "Please enter an integer amount of dimes you would like to deposit.\n";
                              i = 0;
                              cin >> i;
                              Coins c(0,i,0,0);
                              myCoins.depositChange(c);
                              break;
                          }
                          case 3 :
                          {
                              cout << "Please enter an integer amount of nickels you would like to deposit.\n";
                              i = 0;
                              cin >> i;
                              Coins c(0,0,i,0);
                              myCoins.depositChange(c);
                              break;
                          }
                          case 4 :
                          {
                              cout << "Please enter an integer amount of pennies you would like to deposit.\n";
                              i = 0;
                              cin >> i;
                              Coins c(0,0,0,i);
                              myCoins.depositChange(c);
                              break;
                          }
                          case 5 :
                              break;
                          default:
                              return 0;
                        }
                    break;
                }
                case 2 :
                {
                    cout << "Please enter an integer amount you would like to extract.\n";
                    int j = 0;
                    cin >> j;
                    myCoins.extractChange(j);
                    break;
                }
                case 3 :
                    cout << "You have " << myCoins << endl;
                    break;
                default :
                    return 0;
                    
             }
            printMainMenu();
        }
    return 0;
}

void printMainMenu(){
    cout << "===================Coin Menu 9001====================\n";
    cout << "Enter the corresponding number with the menu choice you want.\n";
    cout << "1. Deposit Coins.\n";
    cout << "2. Extract Change\n";
    cout << "3. Print coins available.\n";
    cout << "Anything else will exit.\n";
}

void printDepositMenu(){
    cout << "===================Deposit Menu====================\n";
    cout << "Enter the correspoding number to deposit coins.\n";
    cout << "1. Deposit Quarters.\n";
    cout << "2. Deposit Dimes.\n";
    cout << "3. Deposit Nickels.\n";
    cout << "4. Deposit pennies.\n";
    cout << "5. Main Menu.\n";
    cout << "Anything else will exit.\n";
}


