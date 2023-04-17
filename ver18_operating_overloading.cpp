/////////////////////////////////////////////////
/////////////////////////////////////////////////
/// Operator Overloading



/*

Date MyDate()

There are two ways:

(1) calling operator member function
(2) calling global function operator

a+b => a.func(b)a+b => a.func(b)
!a = a.func()                       // Bu ifadeleri kullanarak 


Rules:

(1) non-existing operator cannot be overloaded 
(2) native type cannot be overloaded          (int, double)
(3) every operator cannot be overloaded!      (::, . , sizeof , .*)
(4) some operators can be overloaded as member functioni but cannot be in global scope
(5) * (product,asteriks) binary/unary can be overloaded!   (*,&,+,-)
(6) () has default argument, the others have not!
(7) a*b + c  => a.operator*(b).operator+(c)
(8) operator+,operator- ,,, operator >> keyword

MyClass operator()()
MyClass operator+()

(9) return type of operators can be selected as anything, except one

*/

//////////////////////////////////////////////////////////////////////
//// ex1 

// Bir fonkisyonu friend tanımlarsak o fonksiyon classın tüm variable ulaşabilir.

#include <iostream>

using namespace std;

class MyClass 
{
private:
    int x;
    void operator-(const MyClass &r)   // r->m2, this -> m1    
    {
        cout << "operator- is calling" << endl;
    }

public:
    friend void func();
    void operator+(const MyClass &r)   // r->m2, this -> m1
    {
        cout << "operator+ is calling" << endl;
    }
};

void func()
{
   MyClass m1,m2;   
   m1-m2 ;    
}


int main()
{
  MyClass m1,m2;
  m1 + m2;        //  m1.operator=(m2);
  func();
  return 0;
}





/// Operator Overloading
//////////////////////////////////////////////////
//////////////////////////////////////////////////