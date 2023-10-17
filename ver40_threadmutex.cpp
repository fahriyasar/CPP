///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
//// Threads with shared memory and mutex


/////////////////////////////////////////////////////////
//// Ex1

/*
#include <iostream>
#include <thread>

using namespace std;

void callFunc()
{
    cout << "callFunc function thread" << endl;
}


int main()
{
    thread t(&callFunc);

    cout << "Main thread\n";

    t.join(); 

    return 0;
}

*/

///////////////////////////////////////////////
/// Ex2


#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mu;

void callFunc()
{
    for(int i=0;i<10;i++)
    {
       mu.lock();
       cout << "call Func : " << i << endl;
       mu.unlock();
       this_thread::sleep_for(chrono::milliseconds(1000));
    }

}


int main()
{
    thread t(&callFunc);

    for(int i=-10;i<0;i++)
    {
       mu.lock();
       cout << "main Func : " << i << endl;
       mu.unlock();
       this_thread::sleep_for(chrono::milliseconds(1000));
    }

    t.join(); 

    return 0;
}



//// Threads with shared memory and mutex
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
