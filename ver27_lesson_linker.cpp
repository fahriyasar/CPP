////////////////////////////////////////////////////
////////////////////////////////////////////////////
//// linked in c++

///////////////////////////////////////
/// Ex1

// Namespace bölebiliyorsun fakat classları bölemiyorsun Bunu unutma!


/*
#include <iostream>

namespace Ali
{
    
    class MyClass
    {
      
      public:
      void func(){
      std::cout << "Myclass func" << std::endl;
      }
    };
}

namespace Ali
{
    double a;
    // class MyClass{};
}


int main()
{
    Ali::a;
 

    return 0;
}

*/


/////////////////////////////////////////////////
/// Ex2

/*


#include <iostream>

namespace Ali
{
    using namespace std;
    class MyClass
    {
      
      public:
      void func(MyClass x);
    };
}


void Ali::MyClass::func(MyClass x)
{
    cout << "My class func" << endl;
}


int main()
{
     Ali::MyClass m1;
     Ali::MyClass m2;

     m1.func(m2);
 
   
    return 0;
}
*/

//////////////////////////////////////////////////
/// Ex3

/*

#include <iostream>

namespace Ali
{
    using namespace std;
    class MyClass
    {
      
      public:
      
    };
    void func(MyClass x);
}


void Ali::func(Ali::MyClass x)
{
    cout << "My class func" << endl;
}


int main()
{
     Ali::MyClass m1;
     Ali::func(m1);
   
    return 0;
}

*/



//// linked in c++
////////////////////////////////////////////////////
////////////////////////////////////////////////////
