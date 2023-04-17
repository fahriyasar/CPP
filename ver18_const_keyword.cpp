/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/// const keyword revisted

/*

class MyClass
{
    public :
     void func const; // not changing in object
};

(1) class object cannot be changed in const func()
(2) mutable

class MyClass
{
    mutable int mx;
}


*/

//////////////////////////////////////////////////
// ex1
/*
// const func içinde atama yapabilmesini ağlıyor.

#include <iostream>

using namespace std;

class MyClass
{
private:
   mutable int mx;     
public:
   void accessor() const;   // erişimci
};

void MyClass::accessor() const
{
    mx = 0;
}

int main()
{
    MyClass a;
    a.accessor();
    return 0;
}

*/

///////////////////////////////////////////////////////////
/// Ex2

// Eğer bir const yapıyorsak bu değeri veya fonksiyonu sadece okuyorumdur. Display ediyorumdur.

// const MyClass x;
// (1) const does not provide which is non constant

// member initializing list 

/*

#include <iostream>

using namespace std;

class MyClass
{
private:
   int mx;
   const int a;   // const bir variable tanımladığımızda derleyici not initialized sorunuyla karşılaşıyoruz.  
public:
   MyClass() : a(4),mx(3)
   {
    cout << "default constructor" << endl;
   }
   ~MyClass()
   {
    cout << "Destructor" << endl;
   }
   void display() const
   {
    cout << "mx : " << mx << endl;
    // mx = 5 ;  // syntax error
    // a= 5;     // syntax error
    cout << "a : " << a << endl;
   }
   
};


int main()
{
    MyClass m1;
    m1.display();

    return 0;
}

*/

/////////////////////////////////////////////////////
// ex4

// fonksiyonun yanına : koyup bir şeyler eşitlemek sizin ilk değer atamalarınız doğru olacağını garanti eder.

#include <iostream>
#include <cstring>

#define ASSIGN_VAR len(strlen(pStr)), pd(new char[len+1]),number(numAssign())

using namespace std;

class FName
{
private:
   char *pd;
   int len;
   int number;
public:
   FName(const char *p);
};

int numAssign()
{
    return 5;
}

FName::FName(const char *pStr) : ASSIGN_VAR 
{
  strcpy(pd,pStr);
  cout << "Name : " << pd << endl;
  cout << "number : " << number << endl;
}

int main()
{
    FName("Mehmet");
    cout << "main start" << endl;
    return 0;
}

/// const keyword revisted
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
