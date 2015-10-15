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
    enum Coin{Quarter, Dime, Nickel, Penny};
    
    /**
     
     Gets the amount of a specific coin.
     
     @param enumeration - A coin enum that is used
     to return the amount of coins.
     @return The amount of the specific coin.
     
     */
    
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
            return pennies;
        }
        else {
            return 0;
        }
    }
    
    /**
     
     Add Coins Method
     
     Can be used as addition and subtraction of coins.
     
     @param enumeration - A coin enumeration can be 
     Quarter, Dime, Nickel, Penny.
     @param i - Integer amount of coins to be added.
     CAN be negative to be used as subtraction but must
     have that amount of coins already.
     
     
     */
    
    void addCoins(Coin enumeration, int i){
        if (enumeration == Quarter) {
            if (quarters + i >= 0)
                quarters += i;
            else
                throw std::invalid_argument("You do not have that many quarters in your coin object.");
        }
        else if (enumeration == Dime) {
            if (dimes + i >= 0)
                dimes += i;
            else
                throw std::invalid_argument("You do not have that many dimes in your coin object.");
        }
        else if (enumeration == Nickel) {
            if (nickels + i >= 0)
                nickels += i;
            else
                throw std::invalid_argument("You do not have that many nickels in your coin object.");
        }
        else if (enumeration == Penny) {
            if (pennies + i >= 0)
                pennies += i;
            else
                throw std::invalid_argument("You do not have that many Pennies in your coin object.");
        }
        else {
            throw std::invalid_argument(" Something went really wrong.");
        }
    }
    

public:
    //Constructor
    Coins(int q, int d, int n, int p )
    :quarters(q), dimes(d), nickels(n), pennies(p)
    {
    }
    
    /**
     
     Deposits all coins from w to this object.
     
     @param w - The coin object that is being
     withdrawaled from.
     
     */
    
    void depositChange(Coins & w){
        try {
            const int q = w.getCoins(Quarter), d = w.getCoins(Dime), n = w.getCoins(Nickel), p = w.getCoins(Penny);
            //withdrawal
            w.addCoins(Quarter, -q);
            w.addCoins(Dime, -d);
            w.addCoins(Nickel, -n);
            w.addCoins(Penny, -p);
            
            //deposit
            this->addCoins(Quarter, q);
            this->addCoins(Dime, d);
            this->addCoins(Nickel, n);
            this->addCoins(Penny, p);
            
        } catch (std::invalid_argument & e){
            std::cerr << e.what() << std::endl;
            return;
        }
    }
    /**
     
     Deposit a specific amount of coins to this object
     from w.
     
     @param q1 - Number of quarters to deposit.
     @param d1 - Number of dimes to deposit.
     @param n1 - Number of nickels to deposit.
     @param p1 - Number of pennies to deposit.
     @param w  - Coins object that will have coins removed
     from and added to this object.
     
     */
    
    void depositChange(int q1, int d1, int n1, int p1, Coins & w){
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
            std::cerr << e.what() << std::endl;
            return;
        }
    }
    
    /**
     
     Checks if amount is greater than sufficient.
     
     @param amount - the amount that is checked.
     @return boolean whether is sufficient.
     
     */
    
    bool hasSufficientAmount( int amount ){
       
      return ((quarters * CENTS_PER_QUARTER) +
              (dimes * CENTS_PER_DIME) + (nickels * CENTS_PER_NICKEL) + pennies) >= amount;
    }
    
    /**
     
     Extracts change from the coin object.
     
     @param amount The amount that is extracted.
     @return Coin object after coins have been extracted.
     
     */
    
    Coins extractChange(int amount ){
      if (hasSufficientAmount(amount)) {
        int q = 0, n = 0, d = 0, p = 0;
        int i = 1;
        switch (i) {
            case 1:
                while (amount >= CENTS_PER_QUARTER && quarters > 0){
                    amount -= CENTS_PER_QUARTER;
                    ++q;
                    --quarters;
                }
            case 2:
                while (amount >= CENTS_PER_DIME && dimes > 0){
                    amount -= CENTS_PER_DIME;
                    ++d;
                    --dimes;
                }
            case 3:
                while (amount >= CENTS_PER_NICKEL && nickels > 0){
                    amount -= CENTS_PER_NICKEL;
                    ++n;
                    --nickels;
                }
            case 4:
                while (amount >= 1 && pennies > 0){
                    amount -= 1;
                    ++p;
                    --pennies;
                }
            default:
                break;
        }
          Coins c(q,d,n,p);
        if (amount != 0){
            std::cout << "You do not have specific amount of coins!\n";
        }
          return c;
      } else {
          std::cout << "You do not have sufficient amount to extract that.\n";
          return Coins(0,0,0,0);
      }
    }
    /**
     
     Prints to out.
     
     @param out The ostream that gets the string.
     
     
     */
    
    void print(std::ostream & out ){
        out << quarters << " quarters " << dimes
        << " dimes " << nickels << " nickels " << pennies << " pennies";
    }
    
    //Overload << operator decleration.
    friend std::ostream & operator << ( std::ostream & out, Coins & c );
};

/**
 Overloads the << operator
 
 @param out - The ostream that will be printed
 @param c - The coins object that is being overloaded.
 @return - The ostream that is being returned.
 
 */

std::ostream & operator << ( std::ostream & out, Coins & c ){
    c.print(out);
    return out;
}






