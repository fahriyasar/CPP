//////////////////////////////////////////////////
//////////////////////////////////////////////////
////// MULTITREADING STRUCTURE

/*

(1) What is the thread?

-thread => "iş parcaciği"

starting point/adress => "main"
another starting point/adress => "thread" , "interrupt"

compile -> executable file (main.exe)

up to down rule!

RAM memory

0x0000000 -
0x0400000 - main

 - "Hello World"    1  3  5   7
..
0x0600000 - endl

0x0600001 - thread  2  4  6   8

0x0700000 - "CPP"
--
0X0800000 - endl

0xFFFFFFF -

(2) What is the purpose of the usage of threads?

- concurrency -> multible program run at the same time   (URLs response)
- calling periodic functional/fuctions (reading ADC data, communication)


(3)  What is cocurrency?

- c++11 includes / memory model, threads, mutexes and locks, thread local data,

condition variablesi tasks

* in C++17 , we have parallel STL! (standard template library)

parallelisim => running multiple program at the same time but proccessing
differenet data(different task)


*/

////////////////////////////////////////////////////////////
/// Ex1

/*

#include <iostream>
#include <thread>

using namespace std;

void myThread() // myThread -> address!
{
    cout << "myThread function is calling" << endl;
}

int main()
{
    thread t(&myThread); // myThread executed!
    t.join();

    cout << "Hello Guys" << endl;

    return 0;
}
*/



///////////////////////////////////////////////////
/// Ex2

/*

#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>

using namespace std;

void myThread() 
{
    for(;;)
    {
       cout << "myThread function is calling\n";
       this_thread::sleep_for(chrono::milliseconds(1000));
    }
}

int main()
{
    thread t(&myThread); 

    for(;;)
    {
       cout << "Hello Guys\n";
       this_thread::sleep_for(chrono::milliseconds(1000));
    }
    t.join();
    return 0;
}

*/


//////////////////////////////////////////////////////
// Ex3 
/*
#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>

using namespace std;

void myThread1() 
{
    for(;;)
    {
       cout << "myThread1 function is calling\n";
       this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void myThread2() 
{
    for(;;)
    {
       cout << "myThread2 function is calling\n";
       this_thread::sleep_for(chrono::milliseconds(1000));
    }
}


int main()
{
    thread t1(&myThread1); 
    thread t2(&myThread2);

    for(;;)
    {
       cout << "Hello Guys\n";
       this_thread::sleep_for(chrono::milliseconds(1000));
    }

    t1.join();
    t2.join();

    return 0;
}

*/
/////////////////////////////////////////////////////
/// Ex4 
/*

#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>

using namespace std;

void myClacFirst(int i,int finalValue)
{
   int sum = 0;
   for(int j=i; j < finalValue; j++)
   {
    cout << "First j : " << j << endl;
    sum = sum + j;
   }

   cout << "Total value : " << sum << endl;
}

void myClacSecond(int i,int finalValue)
{
   int sum = 0;
   for(int j=i; j < finalValue; j++)
   {
    cout << "Second j : " << j << endl;
    sum = sum+j;
   }
   cout << "Total value : " << sum << endl; 
}


int main()
{

    thread t1(&myClacFirst,1,10);
    thread t2(&myClacSecond,1,10);
    

    t1.join();
    t2.join();

    return 0;
}
*/


/////////////////////////////////////////////////////
/// Ex5
/*

#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>

using namespace std;

void myThread1()
{
    for(;;)
    {
       cout << "myThread1 is calling" << endl;
       this_thread::sleep_for(chrono::milliseconds(1000));
    }

}

void myThread2()
{
    for(;;)
    {
       cout << "myThread2 is calling" << endl;
       this_thread::sleep_for(chrono::milliseconds(1000));
    }

}

class myFuncObject
{
public:
    void operator()()
    {   
        thread t1(&myThread1);
        thread t2(&myThread2);
        int counter = 0;
        for(;;)
        {
            counter++;
            cout << "MyFuncObject is calling" << endl;
            mySummation(counter);
            myNegation(counter);
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
        
    }

    void mySummation(int value)
    {
        int sum=0;
        for(int i=0;i<value;i++)
        {
            sum = sum + i;
        }
        cout << "Sum : " << sum << endl;
    } 
    void myNegation(int value)
    {
        int sum=0;
        for(int i=0;i<value;i++)
        {
            sum = sum - i;
        }
        cout << "Negation : " << sum << endl;
    } 

 
private: 

};

int main()
{
    myFuncObject fObject;

    //fObject();

    thread t(fObject);
     
     for(;;)
     {
        cout << "main is calling!" << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
     }


    t.join();    

    return 0;
}
*/


///////////////////////////////////////////////////////
//// Ex6

/*
#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>
#include <string>

using namespace std;

void myThreadFunction(string s)    // call by value
{
    cout << "MyThreadFunction is calling!" << endl;
    cout << "it is : " << s << endl;
}

int main()
{  
    string s = "Hello Guys!";
    thread t(&myThreadFunction,s);
    
    cout << "MainFunctuin is calling!" << endl;
    cout << s << endl;

    t.join(); 

    return 0;
}
*/

///////////////////////////////////////////////////////
//// Ex7

/*
#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>
#include <string>

using namespace std;

void myThreadFunction(string &s)    
{
    cout << "MyThreadFunction is calling!" << endl;
     s = "Fahri";
    cout << "it is : " << s << endl;
   
}

int main()
{  
    string s = "Hello Guys!";
    thread t(&myThreadFunction,ref(s));
    
    cout << "MainFunctuin is calling!" << endl;


    t.join(); 

    cout << s << endl;

    return 0;
}
*/


///////////////////////////////////////////////////////
//// Ex8

/*
#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>
#include <string>

using namespace std;

void myIncrement()
{
    cout << "Increment" << endl;
}

class A
{
public:
   A()
   {
    cout << "constructor" << endl;
   }
   ~A()
   {
    cout << "destructor" << endl;
   }
   A(const A &p)
   {
    cout << "copy constructor" << endl;
   }
};


int main()
{  
    thread t(&myIncrement);

    //A a1;
    //A a2 = a1;

    thread t2 = move(t);     //move function for copy thread

    t2.join(); 

    return 0;
}
*/

////////////////////////////////////////////////////////
/// Ex9

#include <iostream>
#include <thread>
#include <cstdlib>
#include <chrono>
#include <string>

using namespace std;

void myFunc()
{
   // cout << "myFunc" << endl;
}



int main()
{  
    thread t(&myFunc);
    thread t1(&myFunc);

    cout << "main Thread id : " << this_thread::get_id()<< endl;
    cout << "Thread t id : " << t.get_id()<< endl;
    cout << "Thread t1 id : " << t1.get_id() << endl;


    t.join();
    t1.join();

    return 0;
}*/


////// MULTITREADING STRUCTURE
//////////////////////////////////////////////////
//////////////////////////////////////////////////
