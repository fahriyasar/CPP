///////////////////////////////////////////
///////////////////////////////////////////
// 


/*
 
inline (keyword) =>  cost reduction   //Maliyeti azaltmak

// loops -> for, while ... -> inline

inline double square(double d)
{
    return d*d;
}


INLINE

(1) NON-STATİC MEMBER FUNCTİON OF CLASS
(2) static member function of class
(3) friend class member function



*/


//////////////////////////////////////////////
// ex1 

/*
#include <iostream>

using namespace std;

inline int Max(int x, int y)
{
    return (x>y) ? x :y;
}

int main()
{

   cout << "Max(1,5) : " << Max(1,5) << endl;
    return 0;
}

*/

//////////////////////////////////////////////////
// ex2

/*

Convertin Constructor

*/

/*

#include <iostream>

using namespace std;

class MyClass
{
private:
   double myVar;

public:
   MyClass(double x)
   {
    myVar = x ;
   }
   void display() const
   {
    cout << "The value of variable is " << myVar << endl;
   }
};

int main()
{
   MyClass m1(10.5);
   m1.display();
   
   m1 = 5.5;   // conversion constructor

   m1.display();

    return 0;
}

*/

/////////////////////////////////////////////////////////
// ex3

/*
#include <iostream>

using namespace std;

class MyClass
{
private:
   double myVar;

public:
   MyClass(double x)
   {
    myVar = x ;
   }
   void display() const
   {
    cout << "The value of variable is " << myVar << endl;
   }
   MyClass &operator=(const MyClass &r)
   {
    cout << "operator = " << endl;
    return *this;
   }
};

int main()
{
   MyClass m1(10.5);
   m1.display();
   
   m1 = 5.5;   // tempory variable

   m1.display();

    return 0;
}
*/

////////////////////////////////////////////////////
// ex4

/*
#include <iostream>

using namespace std;

class Counter
{
private:
   
   int mVal;
   int bVal;

public:
   Counter(int val=0): mVal(val), bVal(val)
   { 
   }
   void display() const
   {
    cout << "(" << mVal << ")" << endl;
    cout << "(" << bVal << ")" << endl;
   }

};

int main()
{
    Counter myCounter(5);
    myCounter.display();

    myCounter = 80;
    myCounter.display();
    return 0;
}*/


////////////////////////////////////////////////////
// ex5

/*
#include <iostream>

using namespace std;

class Counter
{
private:
   
   int mVal;
   int bVal;

public:
   Counter(int val=0): mVal(val), bVal(val)
   { 
   }
   void display() const
   {
    cout << "(" << mVal << ")" << endl;
    cout << "(" << bVal << ")" << endl;
   }

};

int main()
{
    Counter myCounter(5);
    myCounter.display();

    myCounter = 80;
    myCounter.display();
    return 0;
}
*/
////////////////////////////////////////////
//// ex6

/*

named constructor -> member function creates variables.

*/


#include <iostream>

using namespace std;

class Complex
{
private:
   double Cmag,Cangle,Creal,Cimag;
   static int flag;
   Complex(double mag,double angle, int dummy) : Cmag(mag),Cangle(angle)
   {
     flag = 1;
   }
   Complex(double real, double imag) :Creal(real),Cimag(imag)
   {
     flag = 2;
   }
public:
   static Complex *createPolar(double mag,double angle)
   {
    return new Complex(mag,angle,0);
   }
   static Complex *createCartesian(double real,double imag)
   {
    return new Complex(real,imag);
   }
   void display() const
   {
    if(flag==1)
    {
      cout << "mag : " << Cmag << " angle : " << Cangle << endl;
    }
    if(flag==2)
    {
        cout << "real : " << Creal << " image : " << Cimag << endl;
    }
     
   }
};


int Complex::flag = 0;


int main()
{
    // Complex(1.1,1.2,1.3); syntax errror
    Complex *p1 = Complex::createPolar(5.5,3.5);        // Named constructor
    p1->display();
    Complex *p2 = Complex::createCartesian(2.3,2.5);    // Named constructor
    (*p2).display();

    return 0;
}




// 
///////////////////////////////////////////
///////////////////////////////////////////
