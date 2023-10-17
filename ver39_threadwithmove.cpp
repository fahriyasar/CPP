///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
//// Thread With Move Semantics


/*


move semantic is used to transfer the thread mechanism from the one created to another
list or vector space with memory optimization!


*/

////////////////////////////////////////////////
// Example 1

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


int main()
{
    vector<thread> workers;

    for(int i=0;i<5;i++)
    {
        auto t = thread(
            [i]()
            {
                cout << "thread function : " << i << "\n";
            }
        );

        workers.push_back(move(t));
    }
    
/*
    for_each(workers.begin(),workers.end(),
     [](thread &t)
     {
       assert(t.joinable());
       t.join();
     });
*/


    for(auto iter = workers.begin();iter != workers.end();iter++)
    {
        assert(iter->joinable());
        iter->join();
    }

    return 0;
}










//// Thread With Move Semantics
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
