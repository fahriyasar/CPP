#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

class Account
{
private:
  int mAccountNumber;
  double mBalance;
  int mOpCounter; 
public:
  Account(double sum = 0.0);
  int getAccountNumber() const;
  double getBalance() const;
  Account &deposit(double sum);
  Account &draw(double sum);
  void display() const;
  void transfer(Account &other, double sum);
};

#endif