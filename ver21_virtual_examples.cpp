/////////////////////////////////////////////
/////////////////////////////////////////////
//// VİRTUAL MECHANİSM İN C++

/*

Base 

vptr = 2000
a
b

2000 start address
&f1
&f2
&f3
&f4

Der

vptr = 3600
a
b
x

3600

&Der::f1
&Der::f2
&Der::f3
&Der::f4

*/


////////////////////////////////////
///ex1

/*

#include <iostream>

using namespace std;

class Base
{
public:
int a,b; 
virtual void f1();
virtual void f2();
virtual void f3();


};

class Der : public Base
{
public:
int x,y;
virtual void f1();
};

int main()
{
   
   cout << sizeof(Base) <<endl;
   cout << sizeof(Der) <<endl;
    return 0;
}

*/

#include <iostream>

using namespace std;

class Base
{
public: 
  Base()
  {
    vfunc();
  }
  virtual void vfunc()
  {
    cout << "base vfunc" << endl;
  }
  void func()
  {
    vfunc();
  }
};

class Der: public Base
{
public:
   Der()
   {
    vfunc();
   }
   virtual void vfunc()
   {
    cout << "virtual Der vfunc" <<endl;
   }
};

void func(Base *ptr)
{
    ptr->vfunc();
}


int main()
{
    Der myder;

   // func(&myder);

    return 0;
}


//// VİRTUAL MECHANİSM İN C++
/////////////////////////////////////////////
/////////////////////////////////////////////
