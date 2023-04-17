//////////////////////////////////////////////////////
/////// ex6 

/*

#include <iostream>

using namespace std;

class MyClass
{
  private:
  int x;
  public:
  MyClass()
  {
    cout << "default constructor !" <<endl;
  }
  MyClass(int a)
  {
    x = a;
    cout << "int constructor" << endl;
  }
  MyClass(int a,int b)
  {
    x = a;
    cout << "int int constructor" << endl;
  }
  MyClass(double a,double b)
  {
    x = a;
    cout << "double double constructor" << endl;
  }

  MyClass(int a,double b)
  {
    x = a;
    cout << "int double constructor" << endl;
  }

  protected:

};


int main()
 { 
    MyClass m1(5);
    MyClass m2 = 5;
    MyClass m3;
    MyClass m4(5,5);
    MyClass m5(3.3,4.3);
    MyClass m6(4,4.5);


    return 0;
 }

*/

//////////////////////////////////////////////////
//////////////////////////////////////////////////
/// DESTRUCTOR
/*

Destructor -> delete object, end of main, end of block

~MyClass();

Rules

(1) no return types
(2) no overload
(3) no parametric structure, variable MyClass()
(4) destructor may be in privite, no necessary
(5) can be called by its name

*/

//////////////////////////////////////////////////
// ex7

/*
#include <iostream>

using namespace std;

class MyClass
{
  private:
  int x;
  public:
  MyClass()
  {
    cout << "default constructor" << endl;
  }
  ~MyClass()
  {
    cout << "destructor" << endl;
  }
  
  void func()
  {
    cout << "Func " << endl;
  }


};

void func()
{
    cout << "global func" << endl;
}

int main()
{
   
    MyClass m1;
    m1.~MyClass();   // Elle destructor çağırsak bile bu nesneyi yok ettiğimiz anlamına gelmiyor.
    m1.func();
    func();
    MyClass m2;
    cout << "main start" << endl;

    return 0;
}
*/

//////////////////////////////////////////////////
// ex7  dinamik bir hafıza urettiğimizde destructor calışması için bu dinamik hafızanın silinmesi gerekir.

/*
#include <iostream>

using namespace std;

class MyClass
{
  private:
  int x;
  public:
  MyClass()
  {
    cout << "default constructor" << endl;
  }
  ~MyClass()
  {
    cout << "destructor" << endl;
  }
};


int main()
{
    MyClass *p = new MyClass;    // only constructor called
    delete p;                    // both constructor - destructor

    return 0;
}
*/


//////////////////////////////////////////////////
// ex8  
/*
#include <iostream>

using namespace std;

class MyClass
{
  private:
  int x;
  public:
  MyClass()
  {
    cout << "default constructor" << endl;
  }
  ~MyClass()
  {
    cout << "destructor" << endl;
  }
};


int main()
{
    MyClass *pd = new MyClass[5];   // only array constructor called
    delete[] pd;                    // array both constructor + destructor

    return 0;
}
*/

//////////////////////////////////////////////////
// ex8  

/*

#include <iostream>

using namespace std;

class MyClass
{
  private:
  int x;
  public:
  MyClass()
  {
    cout << "default constructor" << endl;
  }
  ~MyClass()
  {
    cout << "destructor" << endl;
  }
};

void func()
{
    // static MyClass m;   // destructor main functionun sonunda gelir.
    // MyClass m;    // Burada ise descructor func dosyasının sonunda gelir.
    MyClass *p = new MyClass;
    delete p;
}


int main()
{
    cout << "main start :" << endl;
    func();
    cout << "main end :" << endl;

    return 0;
}
*/

//////////////////////////////////////////////////
// ex9     

/*

#include <iostream>

using namespace std;

class MyClass
{
  private:
  int x;
  public:
  MyClass()
  {
    cout << "default constructor" << endl;
  }
  ~MyClass()
  {
    cout << "destructor" << endl;
  }
};

void func(MyClass x)     // copy constructor   // Bir constructor 2 adet destructor cağrılıyor.
{
    
}


int main()
{   
    MyClass m;
    func(m);
    

    return 0;
}*/