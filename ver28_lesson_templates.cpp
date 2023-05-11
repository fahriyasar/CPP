/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/// C++ templates





/*

template -> şablon

- template give a way us to define type dependent
- template provides us to write a code in complier!
- there are two types:

function template in compile time
class template in compile time 

- generic cost does not exist in run time

* function template => one function that can be used in every type
* clas template => one class that can be used in every type/class

keyword/syntax rules

template<class T>
void sub()
{ 
}

template<typename T>
void add()
{
}

*/

///////////////////////////////////////////
/// Ex1 

/*

#include <iostream>


using namespace std;


template<typename T>
void MySwap(T &r1,T &r2)
{
    T temp(r1);
    r1 = r2;
    r2 = temp;
}

int main()
{
    double x = 10;
    double y = 20;
    MySwap(x,y);
    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
    return 0;
}
*/


///////////////////////////////////////////////////
/// Ex2

/*

#include <iostream>

using namespace std;

template <class T,class U,class X>   // template class name can be added!
void add(T num1, U num2, X num3)
{
    T result = num1 + num2 ;
    cout << "Result : " << result << endl;
}


int main()
{ 
    double num1 = 2.1;
    int num2 = 3;

    add(num1,num2,5);
    add<double,double,int>(num1,num2,5);  

    // all information about type of variable may be given in calling operation!

    return 0;
}

*/

///////////////////////////////////////////////////
/// Ex5

/*

#include <iostream>

using namespace std;


////////////// Decleration

template<typename T,class U>
T add(T,U);

//////////// DEfinition

template<typename T,class U>
void display(T num1,U num2)
{
   T result = add(num1,num2);
   cout << "Result : " << result << endl;
}


template<typename T,class U>
T add(T num1,U num2)
{
    T result = num1 + num2;
    return result;
}


int main()
{ 
    double x = 5.1;
    double y = 4.3;
    display(x,y);
    return 0;
}

*/

/////////////////////////////////////////////////
///Ex6
/*

#include <iostream>
#include <typeinfo>

using namespace std;

template<class T = int,class U = int>
class MyClass
{

public:
   MyClass()
   {
     cout << "Constructor" << endl;
     T result1;
     U result2;
     cout << "Result1 : " << typeid(result1).name() << endl;;
     cout << "Result2 : " << typeid(result2).name() << endl;;
   }
   ~MyClass()
   {
     cout << "Destructor" << endl;
   }
};

int main()
{
    MyClass<> m1;
    
    return 0;
}
*/


/////////////////////////////////////////////////////////
/// Ex8

#include <iostream>

using namespace std;

template<class T=int>
class MyClass
{
private:
    T num1;
    T num2;
public:
   MyClass()
   {
    cout << "Default constructor" << endl;
   }
   MyClass(T val1,T val2): num1(val1),num2(val2)
   {
    cout << "Overloading constructor " <<endl;
   }
   ~MyClass()
   {
    cout << "Default destructor" << endl;
   }
   void add()
   {
     T result = num1 + num2;
     cout << "Result add default : " << result << endl;
   }
   template<typename U>
   void add(U val, U val1)
   {
    U result = val+val1;
    cout << "Result add overloading : " << result << endl;
   }
};


int main()
{
    MyClass<> m1;

    m1.add(4.2,3.2);

    MyClass<double> m2(5.3,5.2);
    m2.add();

    return 0;
}

/// C++ templates
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
