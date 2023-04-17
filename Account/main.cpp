#include <iostream>
#include "account.hpp"

using namespace std;

int main()
{
   Account a1(1900);
   a1.display();

   a1.deposit(800);
   a1.display();

   Account a2(3000);
   a2.draw(500);

   a2.display();

   a2.transfer(a1,600);
   a1.display();
   a2.display();

   double d = a1.getBalance() + a2.getBalance();

   cout << "get balance : " << d << endl;
   
   int x = a1.getAccountNumber();

   cout << "a1 = " << x << endl;

   return 0;
}