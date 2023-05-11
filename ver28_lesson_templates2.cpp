/////////////////////////////////////////
/////////////////////////////////////////
/// Template Examples


//////////////////////////////////////////
//// Ex1

/*

#include <iostream>
#include <typeinfo>
#include <string>


using namespace std;

class MyClass
{
private:
     int mval;
public:
    MyClass(int val): mval(val)
     {
       cout << "Default constructor" << endl;   
     }
    ~MyClass()
    {
      cout << "Destructor" << endl;
    }
    int get() const
    {
        return mval;
    }
    int display() const
    {
        cout << "(" << mval << ")" << endl;
    }
    void set(int val)
    {
        mval = val;
    }
};

template<typename T>
class SmartPtr
{
private:
    T *mp;  
public:
    SmartPtr(T *p): mp(p)
    { 
      cout << typeid(T).name() <<" Constructor" <<endl;
    }
    ~SmartPtr()
    {
      cout << typeid(T).name() <<" Destructor" <<endl;
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
    SmartPtr<MyClass> ptr = new MyClass(29);

    //SmartPtr<int> intPtr = new int; 
    
    ptr->set(25);
    ptr->display();

    SmartPtr<string> p = new string("Mehmet Iscan");

    cout << "length : " << p->length() << endl;
              
    return 0;
}

*/
//////////////////////////////////////////
//// Ex2


#include <iostream>
#include <typeinfo>
#include <string>


using namespace std;

template<class U>
class MyClass
{
private:
     U mval;
public:
    MyClass(U val): mval(val)
     {
       cout << "Default constructor" << endl;   
     }
    ~MyClass()
    {
      cout << "Destructor" << endl;
    }
    int get() const
    {
        return mval;
    }
    int display() const
    {
        cout << "(" << mval << ")" << endl;
    }
    void set(U val)
    {
        mval = val;
    }
};

template<typename T>
class SmartPtr
{
private:
    T *mp;  
public:
    SmartPtr(T *p): mp(p)
    { 
      cout << typeid(T).name() <<" Constructor" <<endl;
    }
    ~SmartPtr()
    {
      cout << typeid(T).name() <<" Destructor" <<endl;
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

// Aşağıda smart pointer oluşturmuş oluyoruz.
// Nedeni ise SmartPtr donuşu bir adresi değeri olduğu için öyle kullanılıyor.

int main()
{
    // MyClass<double> m1(5.1);  m1.display();

    SmartPtr<MyClass<double>> ptr = new MyClass<double>(99.9);   

    ptr->display();



              
    return 0;
}



/// Template Examples
/////////////////////////////////////////
/////////////////////////////////////////
