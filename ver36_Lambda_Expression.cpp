/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
///// C++ multithreading application and its rules


 /*
  
-c++11, pave the way for creating inline function in main code!

Complier make

* creating class in main code
* writing operator() in the class
* defining temporary object with the base of lambda/class definition

closure type : type of class with respect to lambda expression

closure object : lamba expression/name

Syntax rules


* [] -> lamba introducer
* () -> function calling operator
* {} -> area that can be coded!
* () ?? {code} => int, mutable, noexcept,constexpr
* [] ?? () => <typename T>


[] <typename T> () int, constexpr, double {code}

[] <typename T> () int {code}


There are advantages of using lambda expression:

* readable
* there is no need to design source code!
* increasing efficieny
* easy to implement with respect to class definition
* return type/value is possible!
* passing as a template to the function

*/



///////////////////////////////////////////////////////////
//// Ex1

/*

#include <iostream>
#include <cstdio>

using namespace std;

class lambda_1_1
{
public:
       void operator()()
       {
          cout << "lambda_1_1 is calling" << endl;
       }
private:
};



int main()
{
    
    [](){cout << "Hello Guys!"<< endl;}();
    
    lambda_1_1 a;

    a();

    return 0;
}
*/

/////////////////////////////////////////////////////////
//// Ex2


/*
#include <iostream>
#include <cstdio>

using namespace std;

class lambda_1_1
{
public:
       void operator()()
       {
          cout << "lambda_1_1 is calling" << endl;
       }
private:
};



int main()
{
    // version 1
    [](){cout << "Hello Guys!"<< endl;}();
    
    // version 2
    lambda_1_1()();

    class lambda_1_2
    {
    public:
          void operator()()
          {
            cout << "lambda_1_2 is calling!" << endl;
          }
    };
    
    //version3
    lambda_1_2()();

    return 0;
}

*/

/////////////////////////////////////////////////////////
//// Ex3
/*

#include <iostream>
#include <cstdio>

using namespace std;


int main()
{

    [](){cout << "Fahri"<< endl;}();

    class lambda_1_1
    {
    public:
      void operator()()
      {
        cout << "Yaşar" << endl;
      }

    private:
    };    
    
    lambda_1_1()();

    return 0;
}
*/


///////////////////////////////////////////////////
/// Ex4
/*

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
  
  auto f = [](int x)
  {
    cout << "Value : " << x << endl;
    return x;
  };

  f(5);

  return 0;
}
*/


///////////////////////////////////////////////////
/// Ex5
/*

#include <iostream>
#include <cstdio>

using namespace std;

class LambdaExp
{
public:
   LambdaExp(int y)
   {
     cout << "Y : " << y << endl;
   }
   
   auto operator()(int x)
   {
     cout << "Value: " << x << endl;
     return x*5;
   }
};

int main()
{
  
  auto f = [](int x)
  {
    cout << "Value : " << x << endl;
    return x;
  };

  f(5);

  auto G = LambdaExp(20)(5);

  cout << "G : " << G << endl;

  return 0;
}

*/

/////////////////////////////////////////////
//// Ex6 

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{

  auto g = [](double x,double y,double z)->double
  {return x+y+z;};

  cout << "Hello" << endl;

  cout << [](double y){return y+y;}(2.2) << endl;

  return 0;
}



///// C++ multithreading application and its rules
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////