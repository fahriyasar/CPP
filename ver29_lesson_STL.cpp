///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
// C++ STL

/*

STL(standard template library)
template -> independent oof type in c++
library -> usage of some  source code
standard -> c++ posses it!

STL has

vector  // these are sequence container
deque
List
string


(these are associative container)
set    // binary search tree
multiset    
map    // one name one identifier number
multimap

*/


/*

In STL, iterators are like pointer!

template<class T>
class List
{
    T var1;
public:
   class iterator
   {
      T *vPtr;
   };
}


*/

//////////////////////////////////////////////////////
/// Ex0
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vecInt;

    vector<int> *vecIntPtr = &vecInt;

    vecInt.push_back(5);

    cout << vecInt[0] << endl;
    cout << (*vecIntPtr)[0] << endl;

    return 0;
}
*/

/////////////////////////////////////////////////////
//// Ex1

// example of simple iterator


#include <iostream>

using namespace std;

namespace myStd
{

template<class T>
class List
{
public:
   class iterator
   {

   };     
};

}

int main()
{
    myStd::List<int>::iterator iter;
   
    return 0;
}



// C++ STL
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
