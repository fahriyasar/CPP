///////////////////////////////////////////////////
///////////////////////////////////////////////////
/// associative containers + special functions



/*

Associative containers:

- binary tree search structure
- algorithmic cost for adding or removing data
- set posses one key + one data
- multiset posses many keys + one data
- they have sorted container structure which means that default less functor is applied on class!
- set is used for searching whether there is a key or not, it is applied on data found via key
- map posses pair so one key + one data

first -> key 
second -> data

*/

////////////////////////////////////////////////////////
/// Libraries

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <functional>
#include <deque>

using namespace std;

//////////////////////////////////////////
//// decleration

void Randomize();
string srandom();

template<class Scon>
void cfill(Scon &con,int size);

template<class Scon>
void cdisplay(Scon &con);

template<class T>
bool myGreater(const T &r1,const T &r2);

template<class T>
bool mySmaller(const T &r1,const T &r2);


template<typename T>
class AddConCat
{
private:
     char mc = '1';
     int size;
     T ms;
     
public:
   AddConCat(char c, int s) : mc(c), size(s) {}
   AddConCat(T value) : ms(value) {}

   void operator()(T &r)
   {
    if(mc != '1')
    {
    for(int i=0; i<size ; i++)
     {
       r += mc;
     }
    }
    else
    {
        r += ms;
    }


   }   
};


template<class T>
T myplus(T &r1,T &r2)
{
   return (r1+r2);
}

template<class T,class Gcon,class Pre>
void myTransform(T beg1,T end1,T beg2,Gcon &con,Pre predicate)
{
   T iter1 = beg1;
   T iter2 = beg2;

   for(;iter1 != end1;iter1++,iter2++)
   {
    con.push_back(predicate(*iter1,*iter2));
   }
}



////////////////////////////////////////////////////
// ex1

/*

int main()
{   
    
   vector<string> vector1;
   Randomize();
   cfill(vector1,10);
   cdisplay(vector1);

   sort(vector1.begin(),vector1.end(),greater<string>());
   cdisplay(vector1);
  
    
    return 0;
}
*/

//////////////////////////////////////////////////////
/// Ex2

/*
int main()
{   
    
   vector<string> vector1;
   Randomize();
   cfill(vector1,10);
   cdisplay(vector1);

   sort(vector1.begin(),vector1.end(),myGreater<string>);
   cdisplay(vector1);
  
    
    return 0;
}
*/

////////////////////////////////////////////////////
/////// Ex3 
/*
int main()
{   
    
   vector<string> vector1;
   Randomize();
   cfill(vector1,10);
   cdisplay(vector1);

   sort(vector1.begin(),vector1.end(),mySmaller<string>);
   cdisplay(vector1);
  
    
    return 0;
}
*/


////////////////////////////////////////////////////
/////// Ex3 


/*
int main()
{   
    
   vector<string> vector1;
   Randomize();
   cfill(vector1,10);
  cdisplay(vector1);
   
   // for_each(vector1.begin(),vector1.end(),AddConCat<string>('a',2));
   for_each(vector1.begin(),vector1.end(),AddConCat<string>("Selam"));

 
   cdisplay(vector1);
  
    
    return 0;
}*/


////////////////////////////////////////////////////////
/// Ex4

int main()
{
    list<int> ilist;
    vector<int> ivec;
    deque<int> dq1;

    for(int i=0;i<10;i++)
    {
      ilist.push_back(rand()%20);
      ivec.push_back(rand()%20);
    }

    cdisplay(ilist);
    cdisplay(ivec);

    //transform(ilist.begin(),ilist.end(),ivec.begin(),back_inserter(dq1),plus<int>());

    myTransform(ilist.begin(),ilist.end(),ivec.begin(),dq1,myplus<int>);
    cdisplay(dq1);
 
    return 0;
}


//////////////////////////////////////////////////////
/// DEfinition

void Randomize()
{
    srand(static_cast<unsigned>(time(0)));
}
string srandom()
{
    static const char *const pnames[] = { "fatma",
                                          "hatice",
                                          "kamuran",
                                          "yesim",
                                          "ali",
                                          "burak",
                                          "mehmet",
                                          "nazif",
                                          "goktug",
                                          "baran",
                                          "berkem",
                                          "ozenc",
                                          "ammar",
                                          "gozde",
                                          "urgan"};

    size_t size = sizeof(pnames)/sizeof(*pnames);
    return pnames[rand()%size];
}


template<class Scon>
void cfill(Scon &con,int size)
{
    //generates random name for a given srandom function
    //generate_n(inserter(con,con.begin()),size,srandom);
    for(int k=0;k<size;k++)
    {
        con.push_back(srandom());
    }
}

template<class Scon>
void cdisplay(Scon &con)
{
    //displaying naems stored in container 
    for(typename Scon::const_iterator iter = con.begin();iter != con.end();++iter)
    {
       cout << *iter << " "; 
    }
    cout << endl;
}

template<class T>
bool myGreater(const T &r1,const T &r2)
{
    return r1.size() < r2.size();
}

template<class T>
bool mySmaller(const T &r1,const T &r2)
{
    return r1.size() > r2.size();
}



/// associative containers + special functions
///////////////////////////////////////////////////
///////////////////////////////////////////////////
