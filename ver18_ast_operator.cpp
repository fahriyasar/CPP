////////////////////////
/// ex3

/*

* , ->   : pointer
class object can be used as pointer (smart pointer)

*/
/*
#include <iostream>
#include <list>
#include <set>

using namespace std;

typedef list<int>::iterator listIter;
typedef set<int>::iterator setIter;

int main()
{
   list<int> ilist;
   
   for(int k=0;k<20;k++)
   {
     ilist.push_back(k*k);
   }
    
    listIter ptr = ilist.begin();         // İki şekilde tanımlanır.   or
    //list<int>::iterator ptr = ilist.begin();
   
   while(ptr != ilist.end())
   {
    cout << *ptr++ << " " ;         // or
    //ptr++;
    // cout << ptr.operator++().operator*() << " ";  // Yukardaki ile aynı sanılmasın çünkü 
   }
   cout << endl;

   set<int> iset;

   for(int k=0;k<20;k++)
   {
    iset.insert(k);
   }

   setIter ptr2 = iset.begin();

   while(ptr2 != iset.end())
   {
    cout << *ptr2++ << " " ;
   }


    return 0;
}

*/

/////////////////////////////////
/// ex4

// -> ,*


// Constructor Overloading yapıyoruz.
// Burda öyle bir munipule ediyoruz ki ptr objesini pointer operatorlerine sahip olabiliyor.
// Pdr address değil sadece address olarak görünüyor. 


/*
#include <iostream>

using namespace std;

class MyClass
{
private:
   int mVal;
public:
   MyClass(int val):mVal(val) 
   {
    cout << "MyClass Constructor" << endl;
   }
  void display() const
  {
    cout<< "(" << mVal << ")" << endl;
  }
  int set(int val)
  {
    mVal = val;
  } 
  int get() const
  {
     return mVal;
  }
  ~MyClass()
  {
    cout << "Destructor" <<endl;
  }
};

class MyClassPtr
{
private:
   MyClass *mp;
public:
     MyClassPtr(MyClass *p): mp(p)
     {
      cout << "MyClass* Constructor" << endl;
     }
     MyClass &operator*()
     {
      cout << "Operator * " <<endl;
      return *mp;
     }
     MyClass *operator->()
     {
      cout << "Operator -> " << endl;
      return mp;
     }

     ~MyClassPtr()
     {
      cout << "MyClass * Destructor" << endl;
      delete mp;
     } 
};

void func()
{
    MyClass *ptr = new MyClass(45);   // adress of object    //New MyClassın 45 olan değerle başlatıldığını ve bu pointer değeriyle adresinin okunabileceğini söylüyor.
    MyClass x(10);  // object
    
    ptr->display();    // adress olduğu için -> ulaşılabiliyor.
    *ptr = x;
    ptr->display();              // İçeriğine ulaşmış oluyoruz.
    ptr->set(20);
    ptr->display();
    delete ptr;          // ptr dinamik bir hafıza olduğu için geri vermemiz gerekiyor.
}

int main()
{
    //func();
    
    MyClassPtr ptr = new MyClass(45);     //ptr object, not address
     
    MyClass x(18); 
    *ptr = x;
    ptr->display();        // same        // operator overloading
    ptr.operator->()->display();   // same   // object " . " usage

    return 0;
}

*/

////////////////////////////////////////////////////////////////
// ex5


#include <iostream>
#include <string>

using namespace std;

class MyClass
{
private:
   int mVal;
public:
   MyClass(int val):mVal(val) 
   {
    cout << "MyClass Constructor" << endl;
   }
  void display() const
  {
    cout<< "(" << mVal << ")" << endl;
  }
  int set(int val)
  {
    mVal = val;
  } 
  int get() const
  {
     return mVal;
  }
  ~MyClass()
  {
    cout << "Destructor" <<endl;
  }
};
/*

template -> class   (object class) -> Basic fuctures of class


template<Ttypename T>
class vector
{
     T *mp;
     public: 
     push_back(const T &r)
};

*/


template <typename T>
class SmartPtr
{
private:
    T *mp;
public:
    SmartPtr(T *p): mp(p)
    {
      cout << "T constructor" << endl;
    }
    ~SmartPtr()
    {
      cout << "T destructor" << endl;
      delete mp;
    }
    T &operator*()
    {
      return *mp;
    }
    T *operator->()
    {
      return mp;
    }

};

int main()
{
   SmartPtr<MyClass> ptr = new MyClass(99);
   //SmartPtr<string> intPtr = new int;

   ptr->set(987);
   ptr->display();

   SmartPtr<string> p = new string("Mehmet İscan");

   cout << "length : " << p->size() <<endl;
  
   
   return 0;
}


// 129 kaldım..

/// Array Class
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////