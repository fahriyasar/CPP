///////////////////////////////////////////
///////////////////////////////////////////
// Thread    --- Functor 


////////////////////////////////////////////
/// Ex1

/*

#include <iostream>
#include <thread>

using namespace std;

class myFuncObject
{
public:
   void operator()()
   {
    int counter=0;
    for(;;)
    {
       counter++;
       cout << "MyFuncObject" << endl;
       mySummation(counter);
       myNegation(counter);
       this_thread::sleep_for(chrono::milliseconds(1000));
    }

   }

   void mySummation(int value)
   {
     int sum = 0;
     for(int i=0;i<value;i++)
     {
        sum = sum + i;
     }

     cout << "Sum is : " << sum << endl;
   }
   void myNegation(int value)
   {
     int neg = 0;
     for(int i=0;i<value;i++)
     {
        neg = neg - i;
     }

     cout << "Negation is : " << neg << endl;
   }



};


int main()
{
    myFuncObject fObject;

    thread t(fObject);
    
    for(;;)
    {
       cout << "my main thread" << endl ;
       this_thread::sleep_for(chrono::milliseconds(1000));
    }


    t.join();
   

    return 0;
}

*/

////////////////////////////////////////////
/// Ex2


#include <iostream>
#include <thread>

using namespace std;


void myThreadFunc1()
{
    cout <<"mtThreadFunc1 is calling!\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
}
void myThreadFunc2()
{
    cout <<"mtThreadFunc2 is calling!\n";
    this_thread::sleep_for(chrono::milliseconds(1000));
}

class myFuncObject
{
public:
   void operator()()
   {
    thread t1(&myThreadFunc1);
    thread t2(&myThreadFunc2);


    int counter=0;
    for(;;)
    {
       counter++;
       cout << "MyFuncObject" << endl;
       mySummation(counter);
       myNegation(counter);
       this_thread::sleep_for(chrono::milliseconds(1000));
    }

    t1.join();
    t2.join();

   }

   void mySummation(int value)
   {
     int sum = 0;
     for(int i=0;i<value;i++)
     {
        sum = sum + i;
     }

     cout << "Sum is : " << sum << endl;
   }
   void myNegation(int value)
   {
     int neg = 0;
     for(int i=0;i<value;i++)
     {
        neg = neg - i;
     }

     cout << "Negation is : " << neg << endl;
   }



};





int main()
{
    myFuncObject fObject;

    thread t(fObject);
    
    for(;;)
    {
       cout << "my main thread" << endl ;           //1
       this_thread::sleep_for(chrono::milliseconds(1000));
    }


    t.join();
   

    return 0;
}