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
/*

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
*/

/////////////////////////////////////////////////
//// Ex2

/*

#include <iostream>
#include <list>
#include <string>
using namespace std;

template<class Iter>
void display(Iter beg,Iter end)  // iter is the type list<T>::iterator overloaded !
{
    while(beg!= end)
    {
        cout << *beg++ << " ";
    }
    cout << endl;
}


int main()
{
    list<string> sList;  // template , default constructor
    
    sList.push_back("Mehmet");  // internal variable is used as string, list posses sList feature
    sList.push_back("Fahri");
     
    // Lİst, string, iterator class!

    list<string>::iterator iter;  // iterator class has a default contructor

    for(auto iter = sList.begin(); iter != sList.end();iter++)
    {
        cout << *iter << endl;  //  << operator overloaded
    }
    display(sList.begin(),sList.end());


    list<int> iList;

    iList.push_back(5);
    iList.push_back(110);

    display(iList.begin(),iList.end());

    return 0;
}
*/



///////////////////////////////////////
// Ex3 
/*
#include <iostream>
#include <list>
#include <string>
using namespace std;

template<class Iter>     // adress 
void display(Iter beg,Iter end)  // iter is the type list<T>::iterator overloaded !
{
    while(beg!= end)
    {
        cout << *beg++ << " ";
    }
    cout << endl;
}

template<class Container>
void display(Container &r)     // object, copy, reference 
{ 
    typename Container::iterator iter ;
    for(iter = r.begin();iter != r.end(); iter++)
    {
        // Container is a dependent scope, we must add typename before it!
        cout << *iter << " ";
        // this is not an efficiency way to use STL, this process the whole class
    }
    cout << endl;
    
}


int main()
{
    list<string> sList;  // template , default constructor
    
    sList.push_back("Mehmet");  // internal variable is used as string, list posses sList feature
    sList.push_back("Fahri");
     
    // Lİst, string, iterator class!

    list<string>::iterator iter;  // iterator class has a default contructor

    for(auto iter = sList.begin(); iter != sList.end();iter++)
    {
        cout << *iter << endl;  //  << operator overloaded
    }
    display(sList.begin(),sList.end());


    list<int> iList;

    iList.push_back(5);
    iList.push_back(110);

    display(iList);

    return 0;
}

*/

////////////////////////////////////
/// EX3

/*

#include <iostream>
#include <set>
#include <list>

using namespace std;

template<class iter>
void display(iter beg,iter end)   // powerful tool, type doesnt important
{
    while(beg!=end)
    {
        cout << *beg++ << endl;
    }
    cout << endl;
}

template<typename inIter,typename OutIter>
OutIter MyCopy(inIter beg,inIter end,OutIter destbeg)
{
    while(beg!=end)
    {
        *destbeg++ = *beg++;
    }
    return destbeg;
}


int main()
{
   set<string> MySet;

   MySet.insert("Fahri");
   MySet.insert("Kadir");
   MySet.insert("Zeynep");
   MySet.insert("Yaşar");

   display(MySet.begin(),MySet.end());
    
   list<string> MyList(4);

   MyCopy(MySet.begin(),MySet.end(),MyList.begin());

   display(MyList.begin(),MyList.end());

    return 0;
}
*/


////////////////////////////////////////////////
//// EX4


/*

nORMALLY, WE HAVE THİS KİND OF TEMPLATE FORMAT SUCH AS 

template<
typename Cat,                  => category
typename T,                    => STORAGE TYPE
typename Diff = ptr_diff_t     => being different type of iterator address
typename Ptr = T&              => reference value of T
>

with the structure of

struct Iterator
{
   typedef Cat iterator_category;
   typedef T value_type;
   typedef Diff distance_type;
   typedef Ptr pointer;
   typedef Ref reference;
};

*/

/////////////////////////////////////////////////////
// Example iterator 
/*
#include <iostream>
#include <list>
using namespace std;

template<class iter>
void func(iter beg,iter end)
{
    typename iter::value_type x;
    typename iter::iterator_category y;
    typename iter::pointer z;

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;
}


class MyClass
{};


int main()
{
    list<int> slist;
    list<MyClass> slist2;
    func(slist.begin(),slist.end());
    func(slist2.begin(),slist2.end());


   

    return 0;
}
*/

/////////////////////////////////////////////////////
//// Ex6

/*

class List
{
  class Iterator
  {
    // overloading 
  };
};


iterator category = >
input iterator => only reading operation
output iterator => reading, writing operation
forward iterator => reading, writing ,forward operation
bidirectional iterators => reading, writing, forward/backward operation
random-access iterators => random access including the statements given above(STL)

*/

//////////////////////////////////////////////
// Ex6

/*

#include <iostream>
#include <vector>

using namespace std;

template<class Container>
void display(Container &r)
{
    for(typename Container:: iterator iter = r.begin();iter!=r.end(); iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

int main()
{   
    vector<int> vec={1,2,3};

    vector<int>::iterator i;

    int j = 0;
    
    for(i=vec.begin();i!=vec.end();++i)
    {
        //we can easily insert an element to the vector!
        if(i==vec.begin())
        {
            i= vec.insert(i,5);
        }
    }
    for(i=vec.begin();i!=vec.end();++i)
    {
       // we can easily insert an element to the vector!
        if(i==vec.begin()+1)
        {
            i= vec.erase(i);
        }
    }
     
    
    display(vec);

    return 0;
}

*/
///////////////////////////////////////////////////
////// Ex7 

// iterator_traits concept => iter types is given in here
/*
#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<class Iter>
void func(Iter beg,Iter end)
{
    //typename Iter::value_type x;    // this case cannot be implemented by natural type(int,double,.....)
    //cout << typeid(x).name() << endl;

    typename iterator_traits<Iter>::value_type y; // partical specialization,
    cout << typeid(y).name() << endl;
    // this can be applied in natural type!
    // class object(STL), iterator_trails main body
}

int main()
{ 
    //int a[100] = {0};    // Burası class olmadığı için bu yapılamaz.  // error for x typeid
    //func(a,a+100);    

   //list<int *> MyList;
   //func(MyList.begin(),MyList.end()); 

   double b[100] = {0.0};
   func(b,b+100);

    return 0;
}
*/

////////////////////////////////////////////////
//// Ex8
/*
#include <iostream>
#include <iterator>
#include <vector>
#include <list>

using namespace std;

template<class Iter>
void myReverse(Iter beg,Iter end)
{
    typename iterator_traits<Iter>::difference_type n = distance(beg,end);
    --n;
    while(n>0)
    {
        typename iterator_traits<Iter>::value_type tmp = *beg;
        *beg++ = *--end;
        *end = tmp;
        n = n-2;
    }

}

int main()
{
    vector<int> vec = {1,2,3,4,55};
    myReverse(vec.begin(),vec.end());
    
    vector<int>::iterator i;

    for(i=vec.begin(); i!= vec.end();i++)
    {
      cout << *i << " ";
    }
    cout << endl;
    return 0;
}*/


///////////////////////////////////////////////
///// Ex10

// how can we use a template for a given specific either
// function and class
// _if => doing on some works which is specific

/*

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

template<class Iter>
void display(Iter beg,Iter end)
{
    for(auto iter =beg;iter!=end;iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;

}

template<class Container,int size>
void generate(Container &r)
{
    for(int k=0; k<size;k++)
    {
        r[k] = rand() % 5 ; 
    }
}

bool myPred(int val)
{
    return val % 2 == 0;
}

template<class Iter,class UnPred>
typename iterator_traits<Iter>::difference_type count_if(Iter beg,Iter end,UnPred pred)   // natural type
{
    int counter = 0;

    while(beg!= end)
    {
        if(pred(*beg))
        {
            ++counter;
        }
        beg++;
    }
   return counter;
}

int main()
{
    vector<int> ivec(10);

    srand(time(0));

    generate<vector<int>,10>(ivec);
   
   display(ivec.begin(),ivec.end());

   cout << count_if(ivec.begin(),ivec.end(),&myPred);
   cout << "times elements can be divided bytwo with results of zero remaining terms" <<endl;
    

    return 0;
}

*/


//////////////////////////////////////////////////////
/// EX11

/*

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename InIter,class OutIter,typename T>
OutIter RemoveCopy(InIter beg,InIter end,OutIter destbeg, const T &rVal)
{
     while(beg!=end)
     {
        if(*beg != rVal)
        {
          *destbeg++ = *beg;
        }
        beg++;
     }
     return destbeg;
}


int main()
{
    vector<int> ivec1;
    vector<int> ivec2(10);
    
    cout << endl;
    cout << "İvec1" << endl;

    
    for(int i=0;i<10;i++)
    {
        ivec1.push_back(i);
        cout << ivec1[i] << " " ;
    }
    cout << endl;
    cout << endl;
    cout << "İvec2" << endl;

    RemoveCopy(ivec1.begin(),ivec1.end(),ivec2.begin(),5);

    for(auto i=ivec2.begin();i!=ivec2.end();i++)
    {
        cout << *i << " " ;
    }
    cout << endl;


    list<int> ilist(10);

    RemoveCopy(ivec1.begin(),ivec1.end(),ilist.begin(),5);
    
    cout << endl;
    cout << "Ilist" << endl;

    for(auto i=ilist.begin();i!=ilist.end();i++)
    {
        cout << *i << " " ;
    }
    cout << endl;


    return 0;
}*/

//////////////////////////////////////////////////////
/// EX12

#include <iostream>
#include <vector>
#include <list>

using namespace std;



int main()
{
    vector<int> ivec;

    
    return 0;
}

// C++ STL
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
