//////////////////////////////////////////
//////////////////////////////////////////
///  INHERITANCE 


/*

Inheritance -> a class derived other classes (has a, is a)

BMW  -> car (common features), motor, door ,.....
audi -> car

class car{}

class BMW -> based on car BMW is a car
class Audi based on car Audi is a car
class tofas -> based on car

derived class -> special features
base class -> common features

has a relation

class Member 
{

}

class A        // A class has a Member m;
{
    Member m;
}

*/


/////////////////////////////////////////////
///// Ex1
/*
#include <iostream>

using namespace std;

class Car   // common features
{
   public:
   void baseFunc1();
   void baseFunc2();
   void baseFunc3();
};

class Audi : public Car
{
    public:
    void derFoo1();
    void derFoo2();
    void derFoo3();
};


int main()
{
    Car car;
    Audi audi;

    car = audi;
    // Every audi is a car.
   
    audi = car; 
    // Every car is not a car.


    return 0;
}

*/

///////////////////////////////////7
//// ex2

/*

#include <iostream>

using namespace std;

class Base   // common features
{
   public:
   void baseFunc1();
   void baseFunc2();
   void baseFunc3();
};

class Der : public Base
{

};

int main()
{
    Der myder;   
    
    Base *ptr;   

    ptr = &myder; // no syntaax error

    Base &r = myder;  // no syntaax error
    
    Base mybase2;

    Der myder2;

    // myder2 = mybase2; // syntax error

    return 0;
}
*/

///////////////////////////////////7
//// ex3

/*

#include <iostream>

using namespace std;

class Car  
{
   public:
   void start()
   {
    cout << "Start " << endl;
   }
   void speedup()
   {
     cout << "SpeedUp " << endl;
   }
   void stop()
   {
     cout << "Stop " << endl;
   }
   void brake()
   {
     cout << "Brake " << endl;
   }

};

void CarGame(Car &r)
{
    r.start();
    r.speedup();
    r.brake();
    r.stop();
}

class BMW : public Car
{
    public:
 
};

class Hyundai : public Car
{
    public:
 
};

class Nissan : public Car
{
    public:
 
};

int main()
{
    BMW bmw;
    Nissan nissan;

    CarGame(bmw);
    CarGame(nissan);




    return 0;
}

*/

///////////////////////////////////////////
/// Ex4
/*

#include <iostream>

using namespace std;

// Türetilmiş ve türenen clasta aynı isimde iki function varsa kendi içindeki fonksiyon diğerini ezer.
// Fuction Overloading yapılamaz 
class Base
{
public:
void func()
{
    cout << "Base Func" << endl;
}
};

class Der : public Base
{
public:
void func(int a)
{
    cout << "Der func" << endl;
}
};


int main()
{
    Der myDer;
    myDer.func(5);

    myDer.Base::func();  // sadece böyle ulaşabiliriz.
    return 0;
}

*/


////////////////////////////////
// Ex5

/*

#include <iostream>

using namespace std;

class Base
{
 public:
 void func()
 {
    cout << "base func" << endl;
 }
 };

 class Der : public Base
{
private:
 void func()
 {
   cout << "Der private func"<< endl;
 }
public:

 };


int main()
{
    Der myder;

    //myder.func(); // syntax error

    myder.Base::func();
    
    return 0;
}
*/

//////////////////////////////////7
// ex6

/*

#include <iostream>

using namespace std;

class Base 
{
public:
static void func()
{
  cout << "Static base func" << endl;
}
};

class Der : public Base
{
public:
void func()
 {
    cout << "der func" << endl;
 }
};


int main()
{
    Der myDer;
    myDer.Base::func();
    myDer.func();

    Base::func(); // statik function çağrılabilir.
    //Der::func(); // fakat normal function böyle cağrılamaz.
    return 0;   // Der funcini sildiğimizde ama Base'ın functionını cıkarıyor.
} 
*/

/////////////////////////////
/// Ex7
// Protecte sadece türetilen class görebilir. Başka scopedan ulaşamayız.
/*
#include <iostream>

using namespace std;

class Base 
{
private:   // derived class cannot reach these variables!
   int x;  
   int pri;
public:
protected:
  int pt;
};

class Der : public Base
{
private:
  int a;
public:
   void func()
   {
    cout << "Der Func" << endl;
    a++;
    
    //x++;  // base private variable
    
  }

  void foo()
  {
    pt =0;   // base protected section can be used in derived class!
  }
};


int main()
{
    Der myder;
    //myDer.pt = 0; // protected variables cannot be reached in main function block!
   
   
    return 0;   
} 
*/

///////////////////////////////////
//// Ex8

/*

#include <iostream>

using namespace std;

class Base
{ 
public:
Base()
{
 cout << "Base default constructor" << endl;
}
Base(int a)
{
 cout << "Base int constructor" << endl;
}
~Base()
{
    cout << "Base destructor" << endl;
}
};

class Der : public Base
{
public:
 Der() : Base(0) // no requirement for default constructor
 {
    cout << "Der constructor" << endl;
 }
 ~Der()
 {
    cout << "Der destructor" <<endl;
 }
};

int main()
{
    Der myder;
    return 0;
}

*/


////////////////////////////////////////////
/// ex9

// protected sadece türetilen class ulaşabilir. Ana classın protectedına eğer constructor yazarsak 
// sadece türetilmiş classlar ana classa ulaşabilir.

/*

#include <iostream>

using namespace std;

class Base
{
public:

~Base()
{
  cout << "Base destructor" << endl;
}
Base(const Base &r)
{
  cout << "Base copy constructor" << endl;
}
protected:
Base()
{
  cout << "Base constructor" << endl;
}

};

class Der : public Base 
{
public:
Der()
{
    cout << "Der constructor" << endl;
}
~Der()
{
  cout << "Der destructor" << endl;
}
Der(const Der &r) : Base(r)
{
  cout << "Der copy constructor" << endl;
}

};

int main()
{
    Der myDer1;
    Der myDer2=myDer1;

    return 0;
}
*/

/////////////////////////////////////////////
/// Ex10

/*

#include <iostream>

using namespace std;

class Base
{
public:
void operator=(const Base &r)
{
  cout << "Base operator= is calling!"  << endl;
}
void func()
{
  cout << "fUNC" << endl;
}
};

class Der : public Base
{
public:
void operator=(const Der &r)
{
  // We must implement base assignment!
  //Base::operator=(r);
  //(*(Base *)this) =r;

  cout << "Der operating= is calling!" << endl;
}

};


int main()
{
  Der myder1,myder2;
  myder1 = myder2;
  
  Base *ptr;
  Der myder3;
  ptr = &myder3;   // adreslerini eşitlesek bile Der in içindeki func a ulaşamıyor.

 ptr->func();    


  return 0;
}
*/

//////////////////////////////////////


/*

class airplane
{

};

(1) interface, implementation
Interface => a class which is derived by airPlane can fly!
Implementation => a class which is derived by airplane can do something more!

(2) derived class has features of default base implementation (superclass)

(3) virtual keyword

*/





///  INHERITANCE
//////////////////////////////////////////
//////////////////////////////////////////
