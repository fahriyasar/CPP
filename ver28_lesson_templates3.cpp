////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
/// Template Devamı

/*

#include <iostream>

using namespace std;

// LOW VE HİGH DEĞERLERİNİ class ın içinde değiştiremezsin çünkü sen bunları set etmiş oluyosun.

template<int low,int high>    // this can be templated in the form of this
class Random
{
  public:
  int operator()()          // run time works!
  {
    // low = 500 77 this cannot assignmed to any number of type!
    return rand() % (high-low +1) +low;
  }

};


int main()
{ 
    Random<5,10> random1;

    for(int i = 0 ; i<10;i++)
    {
      cout << random1() << endl;
    }
    
    
   


    return 0;
}


*/

/////////////////////////////////////////////////////////////77
// Ex9
/*
#include <iostream>
using namespace std;

template<class T,T low,T high>
class Random
{
public:
   public:
   T operator()()
   {
    return (T)rand() % (high - low+1) +low; 
   }
};

int main()
{

  //Random<double,5.1,10.1> random1;  // this cannot bu used in this from floating form
  //Random<int,5,10> random2 ;
  //Random <int,'c','a'> random3 ;

  //cout << random3() << endl;   // char is interpreted as integer!
   
  // Random<char,'a','z'> random4;      // non-floating type
   //cout << random4() << endl;

   Random<string,'a','z'> random5; // non-type parameter cannot be used in template!
   return 0;
}

*/

//////////////////////////////////////////////////////////////////////
////// Ex10

/*
#include <iostream>

using namespace std;

template<const char *p>  // integer covers char type!
class MyClass
{
public:
   const char *func()
   {
    return p;
   }

};

char Str[100] = "Mehmet";   // türü const char * oluyor.

int main()
{
  //MyClass<"Mehmet"> m1;   // Mehmet -> string! error veriyor
  
  //MyClass<Str> m1;
  //cout << m1.func() << endl;


  return 0;
}
*/

//////////////////////////////////////////////////////////////////////
////// Ex11

#include <iostream>

using namespace std;

template<class T,T p>  // integer covers char type!
class MyClass
{
public:
   template<class U=T>     
   U func()      
   {
    cout << typeid(U).name() << endl;  // CONST CHAR * CAN BE RETURNED TO STRİNG!
    cout << "p: " << p << endl;
    return p;
   }

};

char Str[100] = "Mehmet";   // türü const char * oluyor.

int main()
{
  MyClass<const char *,Str> m1; 
  //  m1.func<string>();  //string permits the operation of conversion form const char * to string!

  // m1.func<char *>();    // izin yok

   m1.func<const char *>();   // Buna izin veriyor


  return 0;
}

/// Template Devamı
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


