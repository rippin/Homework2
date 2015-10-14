//
//  Coins.h
//  Homework2
//
//  Created by Eric Franco on 10/7/15.
//  Copyright (c) 2015 Eric Franco. All rights reserved.
//


#include <iostream>
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;
class Coins
{
private:
    int quarters, dimes, nickels, pennies;
    enum Coin{Quarter, Dime, Nickel, Penny };
    
    int getCoins(Coin enumeration){
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
    /*
     Changes an integer amount to the least amount of Coins
     @param int
     The integer amount that will be used to get coins.
     @return Coins
     The Coin object with the least amount of coins.
     
     */
    Coins amountToCoins(int amount){
        std::cout << "Making change from " << amount << "\n";
        int q = 0, n = 0, d = 0, p = 0;
        int i = 1;
        switch (i) {
            case 1:
                while (amount >= CENTS_PER_QUARTER){
                    amount -= CENTS_PER_QUARTER;
                    ++q;
                }
            case 2:
                while (amount >= CENTS_PER_DIME){
                    amount -= CENTS_PER_DIME;
                    ++d;
                }
            case 3:
                while (amount >= CENTS_PER_NICKEL){
                    amount -= CENTS_PER_NICKEL;
                    ++n;                }
            case 4:
                while (amount >= 1){
                    amount -= 1;
                    ++p;                }
            default:
                break;
        }
        return Coins(q,n,d,p);
    }

public:
    Coins(int q, int d, int n, int p )
    :quarters(q), dimes(d), nickels(n), pennies(p)
    {
    }
    
    /*
     Removes coins from deposit and adds
     to this object.
     @param Coins
     The coin object that is being withdrawaled from.
     */
    void depositChange(Coins & w){
        try {
            int q = w.getCoins(Quarter), d = w.getCoins(Dime), n = w.getCoins(Nickel), p = w.getCoins(Penny);
            
            w.addCoins(Quarter, -q);
            w.addCoins(Dime, -d);
            w.addCoins(Nickel, -n);
            w.addCoins(Penny, -p);
            
            this->addCoins(Quarter, q);
            this->addCoins(Dime, d);
            this->addCoins(Nickel, n);
            this->addCoins(Penny, p);
            
        } catch (std::invalid_argument & e){
            std::cerr << "Not enough coins to transfer. Error!\n";
            return;
        }
    }
    
    void deposit(int q1, int d1, int n1, int p1, Coins & w){
        try {
            //withdrawal
            w.addCoins(Quarter, -q1);
            w.addCoins(Dime, -d1);
            w.addCoins(Nickel, -n1);
            w.addCoins(Penny, -p1);
            
            //deposit
            this->addCoins(Quarter, q1);
            this->addCoins(Dime, d1);
            this->addCoins(Nickel, n1);
            this->addCoins(Penny, p1);
        } catch (std::invalid_argument & e){
            std::cerr << "Not enough coins to transfer. Error!\n";
            return;
        }
    }
    
    friend std::ostream & operator << ( std::ostream & out, Coins & c );
    
    bool hasSufficientAmount( int amount ){
       
      return ((quarters * CENTS_PER_QUARTER) +
              (dimes * CENTS_PER_DIME) + (nickels * CENTS_PER_NICKEL) + pennies) >= amount;
    }
    /*
     
     */
    Coins extractChange(int amount ){
      if (hasSufficientAmount(amount)) {
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
          Coins c(q,d,n,p);
        if (amount != 0){
            Coins a = amountToCoins(amount);
            c.depositChange(a);
            
        }
          return c;
      } else {
          std::cerr << "You do not have sufficient amount to extract that.\n";
          return Coins(0,0,0,0);
      }
    }
    void print(std::ostream & out ){
        out << quarters << " quarters " << dimes
        << " dimes " << nickels << " nickles " << pennies << " pennies.";
    }
};

std::ostream & operator << ( std::ostream & out, Coins & c ){
    c.print(out);
    return out;
}






