/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// operator overloading


/*

() operator

func(), func->name(starting address of function), () -> run

func.operator()()

* return type is free!
*the number of parameters is not restricted!
*operator()(intidouble)        overloading!

*/


/////////////////////////////////////////////////////////////
/// ex1

#include <iostream>

using namespace std;

class MyClass
{
private:
     int mVal;
public:
    MyClass(int val): mVal(val)
    {

    }
    ~MyClass()
    {

    }
    void operator()()
    {
        cout << "operator() is calling" << endl; 
        
        for(int i=0;i<mVal;i++)
        {
          cout << i*i << endl ;
        }
        cout << endl;
    
    }

    void operator()(int a,int b)
    {
        cout << "operator(int, int) is calling" << endl; 
        cout << a << " " << b <<  endl;
    }
    void run()
    {
        cout << "process is started!" << endl;
    }
};

int main()
{
    MyClass m(10);

    m();
    m.operator()();
    
    m(5,5);


    return 0;
}
// 130 video
// operator overloading
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////