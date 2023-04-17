#include <iostream>
#include <cstdlib>

#include "account.hpp"

using namespace std;

static int gAccountCounter = 12000;

Account::Account(double sum)
{
    mAccountNumber = ++gAccountCounter;
    mBalance = sum ;
    mOpCounter = 0;
}

int Account::getAccountNumber() const
{
    return mAccountNumber;
}

double Account::getBalance() const
{
    return mBalance;
}

Account &Account::deposit(double sum)
{
    mOpCounter++;
    mBalance = mBalance + sum;
    return *this;
}   

Account &Account::draw(double sum)
{
   if(sum > mBalance)
    {
      exit(EXIT_FAILURE);
      cout << "Not enough balance!" << endl;
    }
    mOpCounter++;
    mBalance = mBalance - sum;
    return *this;
}   

void Account::transfer(Account &other,double sum)
{
    other.draw(sum);
    deposit(sum);
}

void Account::display() const
{
   cout << "************************" << endl;
   cout << "Account ID : " << mAccountNumber << endl;
   cout << "Balance : " << mBalance << endl;
   cout << "************************" << endl;

}