///////////////////////////////////////////////////
///////////////////////////////////////////////////
/// Virtual keyword




/*

virtual -> abstract class -> function

Inheritance

virtual function -> member function of base

virtual function can be overriden ! (derived)

Rules for virtual keyword
(1) cannot be static!, cannot be a friend
(2) virtual function -> accessed by pointer/reference (run time polymorphism)
(3) virtual function -> defined in base, derived
(4) overriden in derived class, not necessary
(5) virtual destructor

)


*/

///////////////////////////////////////////////////////
//// Ex1


// virtual olan function ezebiliyoruz.v
/*
#include <iostream>
using namespace std;

class Base
{
public:
  virtual void func()
  {
    cout << "Base Func" << endl;
  }
  void show()
  {
    cout << "Base show" << endl;
  }
};

class Der : public Base
{
    public:
  void func()
  {
    cout << "Der Func" << endl;
  }
  void show()
  {
    cout << "Der show" << endl;
  }
};


int main()
{
    Base *ptr;
    Der b;
    
    // virtual function, binded at runtime 
    ptr = &b;
    
    ptr->func();
    ptr->show();

    return 0;
}
*/

/*

Polymorphism

Early binding  -> compile time (operator overloading)
Late Binding   -> run time (pointer, reference)

virtual pointer

*/

///////////////////////////////////////////////////////////////
//// Ex2

// virtual fonksiyonu bire bir aynı olması lazım.
// virtual sadece referans ve pointerlarlaa cağırabiliriz. 0
/*

#include <iostream>

using namespace std;

class Base
{
  public:
     void foo1()
     {
       cout << "Base foo1" << endl;
     }
     virtual void foo2()
     {
     cout << "Base foo2" << endl;
     }
     virtual void foo3(double b)
     {
      cout << "Base foo3" << endl;
     }
     virtual void foo4()
     {
      cout << "Base foo4" << endl;
     }
};

class Der: public Base
{
  public:
     void foo1()
     {
       cout << "Der foo1" << endl;
     }
     void foo2()
     {
      cout << "Der foo2" << endl;
     }
     void foo3(double b)
     {
      cout << "Der foo3" << endl;
     }
     void foo4()
     {
      cout << "Der foo4" << endl;
     }
};

int main()
{
  Base *p1;
  Der d1;

   p1 = &d1;

   p1->foo1();   //  early binding / compile time
   p1->foo2();   
   p1->foo3(5.2);


  return 0;
}

*/

/////////////////////////////////////////////////
// Ex3

#include <iostream>

using namespace std;

class Employee
{
public:
  void work()
  {
    cout << "Employees is working now!" << endl;
  }
};

class Driver : public Employee
{
public:
  virtual void work()
  {
    cout << "Driver is driving now!" << endl;
  }
};

class Secretary : public Employee
{
public:
  virtual void work()
  {
    cout << "Secretary is chatting now!" << endl;
  }
  void prepare()
  {
    work();
  }
};

void gfunc(Employee *ptr)
{
  ptr->work();
}

int main()
{ 
  Driver myDriver;
  gfunc(&myDriver);

  Secretary s;

  gfunc(&s);

  s.prepare();
  return 0;
}

/// Virtual keyword
///////////////////////////////////////////////////
///////////////////////////////////////////////////
