//////////////////////////////////////////////////
//////////////////////////////////////////////////
/// composition implementatiion

/*

#include <iostream>

using namespace std;

class firstClass
{
private:
    int a;
public:
    firstClass()
    {
        cout << "FirstClass constructor " << endl;
    }
    ~firstClass()
    {
        cout << "FirstClass destructor " << endl;
    }
};

class secondClass
{
private:
     int b;
     firstClass A;
public:
     secondClass()
     {
        cout << "SecondClass Constructor " << endl;
     }
     ~secondClass()
     {
        cout << "SecondClass Constructor " << endl;
     }
};


int main()
{
    secondClass c;
  

    return 0;
}
*/

////////////////////////////////////////////////////////////7
///////// Ex2

// 2. CLASSTA 1. classa nesne oluşturduğumuzda tüm özelliklerinin public olması gerekiyor. Bu ise hiç istemediğimiz bir şey
// Default constructorını overload ettiğimizde hata veriyor. onuda yazmamız gerekiyor.
/*

#include <iostream>

using namespace std;

class Engine
{
private:
   
public:
   Engine()
   {
     cout << "Default constructor" << endl;
   }
   Engine(int x)
   {
    cout << "Default constructor int" << endl;
   }
   int swicther;
   void run()
   {
     cout << "Engine started - > Engine Class " << endl;
   }

};

class Car
{
private:
   Engine itsEngine;
public:
    void run()
    {
      itsEngine.swicther = 5;
      itsEngine.run();
    }
};



int main()
{
    Car b;
    b.run();

    return 0;
}
*/
/////////////////////////////////////////////////////
//// ex3
/*

#include <iostream>

using namespace std;

class Member
{
private:

public:
    Member()
    {
        cout << "Member default constructor" << endl;
    }
    Member(int a)
    {
        cout << "Member int constructor" << endl;
    }
    ~Member()
    {
        cout << "Member default destructor" << endl;
    }
};

class Owner
{
private:
    Member m;
public:
    Owner(): m(0)
    {
        cout << "Owner default Constructor" << endl;
    }
    ~Owner()
    {
        cout << "Owner default destructor" << endl;
    }
};


int main()
{
    Owner x;



    return 0;
}
*/

////////////////////////////////////////7//////
/// ex4 
/*
#include <iostream>
#include <string>

using namespace std;


class Person
{
  string name;
  int age;
public:
   Person():age(20)
   {

   }
    Person(const char *p,int mAge): age(mAge),name(p) 
   {

   }
   void display() const
   {
      cout << "name : (" << this->name << ")" << endl;
      cout << "age : (" << this->age << ")" << endl;
   }
};

int main()
{
    Person per;
    Person per2("Mehmet",29);
    per2.display();


    return 0;
}
*/


//////////////////////////////////////////
//// ex6

/*

#include <iostream>

using namespace std;

class Member
{
private:

public:
    Member()
    {
        cout << "Member default constructor" << endl;
    }
    Member(int a)
    {
        cout << "Member int constructor" << endl;
    }
    Member(const Member &r)
    {
        cout << "Member copy constructor" << endl;
    }
    ~Member()
    {
        cout << "Member default destructor" << endl;
    }
};

class Owner
{
private:
    Member m;
public:
    Owner()
    {
        cout << "Owner default Constructor" << endl;
    }
    Owner(const Owner &r) :m(r.m)
    {
        cout << "Copy constructor " << endl;
    }
    ~Owner()
    {
        cout << "Owner default destructor" << endl;
    }
};


int main()
{
    Owner x;

    Owner y = x;
    


    return 0;
}

*/

/////////////////////////////////////////////////////
/// ex7

#include <iostream>

using namespace std;

class Member
{
private:

public:
    Member()
    {
        cout << "Member default constructor" << endl;
    }
    ~Member()
    {
        cout << "Member default destructor" << endl;
    }
    Member &operator=(const Member &r)
    {
        cout << "Member operator= is calling" << endl;
    
        return *this;        
    }
    Member(const Member &r)
    {
        cout << "Member copy constructor" << endl;
    }
};

class Owner
{
private:
    Member m;
public:
    Owner()
    {
        cout << "Owner default Constructor" << endl;
    }
    ~Owner()
    {
        cout << "Owner default destructor" << endl;
    }
    Owner &operator=(const Owner &r)
    {
        m=r.m; 
        cout << "Owner operator= is calling" << endl;
        
        return *this;
    }
    Owner(const Owner &r) :m(r.m)     // m.(r.m) yazarsak member copy constructor gelmesi için
    {
        cout << "Copy constructor " << endl;
    }
};


int main()
{
    Owner x,y;

    y = x;    // y.operator=(x);

    Owner z = x;    // copy constructor
    
    return 0;
}

//134 kaldım..

/// composition implementatiion
//////////////////////////////////////////////////
//////////////////////////////////////////////////
