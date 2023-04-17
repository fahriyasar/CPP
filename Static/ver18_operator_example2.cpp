///////////////////////////////////////////////////
///////////////////////////////////////////////////
// Operator convension 

// Operator defaulttu sadece bir değişken için yapabiliriz. 

/*
#include <iostream>

using namespace std;

class MyClass
{
private:
  int mVal;
  double y;
public:
  MyClass(double val) : y(val) 
  {

  }


  operator double() const
  {
    return y;
  }

};

int main()
{
   MyClass m1(4.2);
   MyClass m2(6.2);

   cout << "m1+m2 : " << m1+m2 << endl;  // m1,m2  ->  int,plus!

}

*/


///////////////////////////////////////////////////////////////
/// Ex2

//////// Sağlıklı değil bu yüzden bakma buraya


#include <iostream>

using namespace std;

class B;


class A
{
public:
   A(const B &r)
   {

   }
   A()
   {

   }
};

class B
{
public:
  operator A() const
  {
  }

};


int main()
{
    A a;
    B b; 

    a = b ; // B nin içindeki her şeyi A ya ceviriyoruz.


    return 0;
}
/// video 124 kaldı
