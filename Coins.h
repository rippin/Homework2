//
//  Coins.h
//  Homework2
//
//  Created by Eric Franco on 10/7/15.
//  Copyright (c) 2015 Eric Franco. All rights reserved.
//


#include <iostream>
#include <limits.h>
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
private:
    int quarters, dimes, nickels, pennies;
    enum Coin{Quarter, Dime, Nickel, Penny };
    void addCoins(Coin enumeration, int i){
        if (enumeration == Quarter) {
            if (quarters + i >= 0)
                quarters += i;
            else
                throw std::invalid_argument("You do not have that many coins in your coin object.");
        }
        else if (enumeration == Dime) {
            if (dimes + i >= 0)
                dimes += i;
            else
                throw std::invalid_argument("You do not have that many coins in your coin object.");
        }
        else if (enumeration == Nickel) {
            if (nickels + i >= 0)
                nickels += i;
            else
                throw std::invalid_argument("You do not have that many coins in your coin object.");
        }
        else if (enumeration == Penny) {
            if (pennies + i >= 0)
                pennies += i;
            else
                throw std::invalid_argument("You do not have that many coins in your coin object.");
        }
        else {
            throw std::invalid_argument(" Something went really wrong.");
        }
    }

public:
    Coins(int q, int d, int n, int p )
    :quarters(q), dimes(d), nickels(n), pennies(p)
    {
    }
    
    void depositChange(Coins c ){
        quarters += c.quarters;
        dimes += c.dimes;
        nickels += nickels;
        pennies += pennies;
    
    }
    friend std::ostream & operator << ( std::ostream & out, Coins & c );
    
    bool hasSufficientAmount( int amount ){
       
      return ((quarters * CENTS_PER_QUARTER) +
              (dimes * CENTS_PER_DIME) + (nickels * CENTS_PER_NICKEL) + pennies) >= amount;
    }
    
    Coins extractChange(int amount ){
        int q = 0, n = 0, d = 0, p = 0;
        int i = 1;
        switch (i) {
            case 1:
                while (amount >= CENTS_PER_QUARTER && q <= quarters){
                    amount -= CENTS_PER_QUARTER;
                    ++q;
                    --quarters;
                }
            case 2:
                while (amount >= CENTS_PER_DIME && d <= dimes){
                    amount -= CENTS_PER_DIME;
                    ++d;
                    --dimes;
                }
            case 3:
                while (amount >= CENTS_PER_NICKEL && n <= nickels){
                    amount -= CENTS_PER_NICKEL;
                    ++n;
                    --nickels;
                }
            case 4:
                while (amount >= 1 && p <= pennies){
                    amount -= 1;
                    ++p;
                    --pennies;
                }
            default:
                break;
        }
        
        if (amount != 0){
            //q = INT_MAX, n = INT_MAX, d = INT_MAX, p = INT_MAX;
            std::cerr << "You do not have that specific amount of change\n";
            return Coins(0,0,0,0);
            
        }
        else{
            return Coins(q,d,n,p);
        }
    }
    void print(std::ostream & out ){
        out << quarters << " quarters " << dimes
        << " dimes " << nickels << " nickles " << pennies << " pennies.";
    }
    
    int getAmountofCoins(Coin enumeration){
        if (enumeration == Quarter){
        return quarters;
        }
        else if  (enumeration == Dime){
            return dimes;
        }
        else if  (enumeration == Nickel){
            return nickels;
        }
        else if  (enumeration == Penny){
            return Penny;
        }
        else {
            return 0;
        }
    }
    void setCoins(Coin enumeration, int i){
        if (enumeration == Quarter) {
            if (i >=0)
              quarters = i;
            else
              throw std::invalid_argument("You do not have that many coins in your coin object.");
        }
        
        if (enumeration == Dime) {
            if (i >=0)
                dimes = i;
            else
                throw std::invalid_argument("You do not have that many coins in your coin object.");
        }

        if (enumeration == Nickel) {
            if (i >=0)
                nickels = i;
            else
                throw std::invalid_argument("You do not have that many coins in your coin object.");
        }
        
        if (enumeration == Penny) {
            if (i >=0)
                pennies = i;
            else
                throw std::invalid_argument("You do not have that many coins in your coin object.");
        }

    
    }
    /*
     Add Coins Method
     
     Can be used as addition and subtraction of coins.
     
     @param Coin
     A coin enumeration can be, Quarter, Dime, Nickel, Penny
     @param int
     Integer amount of coins to be added. 
     CAN be negative to be used as subtraction but must
     have that amount of coins already.
     
     
     */
    
    void transfer(int q1, int d1, int n1, int p1, Coins & deposit){
      try {
        this->addCoins(Quarter, -q1);
        this->addCoins(Dime, -d1);
        this->addCoins(Nickel, -n1);
        this->addCoins(Penny, -p1);

        deposit.addCoins(Quarter, q1);
        deposit.addCoins(Dime, d1);
        deposit.addCoins(Nickel, n1);
        deposit.addCoins(Penny, p1);
      } catch (std::invalid_argument & e){
            std::cerr << "Not enough coins to transfer. Error!\n";
            return;
        }
    }
};

std::ostream & operator << ( std::ostream & out, Coins & c ){
    c.print(out);
    return out;
}






