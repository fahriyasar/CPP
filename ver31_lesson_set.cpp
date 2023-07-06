///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
// Associative containers + set container

/*

- operators should be found in order to functions!
- comparison operators includes equivalance, not equality!
- the find function search for data, not key in the set class!
- also, we have a function removing data with the data, not key!

*/

///////////////////////////////////////////////////////////
// Include files

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <deque>
#include <string>
#include <iterator>
#include <functional>
#include <ctime>
#include <cstdlib>

using namespace std;


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
    for(size_t k=0;k<size;k++)
    {
        con.insert(srandom());
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


template<class T,class U>
bool myFind(T beg1,T end1,U value)
{
    auto iter1=beg1;

    for(;iter1!=end1;iter1++)
    {
        if(*iter1 == value)
        {
            return true;
        }
    }
    return false;
}

template<class T>
int myDistance(T first,T end)
{
    int value = 0;
    auto iter = first;
    for(;iter != end ; iter++)
    {
        value++;
    } 
    return value;
}

template<class T,class U,typename Gcon>
void mysetIntersection(T beg1,T end1,U beg2,U end2,Gcon &con)
{
    auto iter1 = beg1;
    auto iter2 = beg2;

    while(beg1!=end1 && beg2!=end2)
    {
        if(*beg1<*beg2)
        {
            ++beg1;
        }
        else
        {
            if(*beg2<*beg1)
            {
                ++beg2;
            }
            else{
                con.push_back(*beg1);
                ++beg1;
                ++beg2;
            }
        }
    }
}

template<class T,class U,class Gcon>
void mysetUnion(T first1,T last1,U first2,U last2,Gcon &con)
{
   while(first1 != last1 && first2 != last2)
   {
    if(*first1 < *first2)
    {
        con.push_back(*first1);
        ++first1;
    }
    else
    {
    if(*first2 < *first1)
    {
        con.push_back(*first2);
        ++first2;
    }
    else
    {
        con.push_back(*first1);
        ++first1;
        ++first2;
    }
    }
   }
}


////////////////////////////////////////////////////////////
/// Ex1 

/*
int main()
{
   set<string> myset;

   // set<type,functionalOperand, allocator> myset;

   Randomize();

   cfill(myset,10);

   cdisplay(myset);

    return 0;
}

*/

/////////////////////////////////////////////////
// Ex2
/*
int main()
{
   set<string> myset;

   // set<type,functionalOperand, allocator> myset;

   Randomize();

   cfill(myset,10);

   cdisplay(myset);

   string s;

   cout << "The name needs to be found : " ;
   cin >> s ;

   auto pos = myFind(myset.begin(),myset.end(),s);

   cout << boolalpha << pos << endl; 
   return 0;
}
*/

/////////////////////////////////////////////////////////////
// Ex3

/*

int main()
{
   set<string> sSet1;
   multiset<string> sSet2;
   // the names could be same, normal set only contains unique elements!

   cfill(sSet1,100);  // set unique names
   cfill(sSet2,100);  // set not need to be unique
   
   cout << endl << "SET" << endl << endl;
   cdisplay(sSet1);

   cout << endl << "MULTİ_SET" << endl << endl;
   cdisplay(sSet2);

   return 0;
}
*/

/////////////////////////////////////////
// ex4

/*

int main()
{

   multiset<string> sSet1;

   cfill(sSet1,100);  
   cdisplay(sSet1);

   string s;
   
   cout << "The name needs to be found : ";
   cin >> s;
   
   multiset<string>::iterator iter1 = sSet1.lower_bound(s);
   multiset<string>::iterator iter2 = sSet1.upper_bound(s);

   cout << *iter1 << " " << *iter2 << endl;
   
   // distance -> calculates the number of elements between the first and last

   cout << distance(iter1,iter2) << endl;


   return 0;
}
*/

///////////////////////////////////////////////////////////////////
/// Ex5

/*

int main()
{

   multiset<string> sSet1;

   cfill(sSet1,100);  
   cdisplay(sSet1);

   string s;
   
   cout << "The name needs to be found : ";
   cin >> s;
   
   multiset<string>::iterator iter1 = sSet1.lower_bound(s);
   multiset<string>::iterator iter2 = sSet1.upper_bound(s);

   cout << s << " is included in this set with the number of " << myDistance(iter1,iter2) << endl;


   return 0;
}
*/

///////////////////////////////////////////////////////////////////
/// Ex6

/*

int main()
{

   multiset<string> sSet1;

   cfill(sSet1,100);  
   cdisplay(sSet1);

   string s;
   
   cout << "The name needs to be found : ";
   cin >> s;
   
   pair<multiset<string>::const_iterator,multiset<string>::const_iterator> ip = sSet1.equal_range(s);

   cout << s << " is included in this set with the number of " << myDistance(ip.first,ip.second) << endl;


   return 0;
}

*/

///////////////////////////////////////////////////////////////////
/// Ex7

/*

int main()
{

   set<string> sSet1;
   set<string> sSet2;

   vector<string> sVec;

   cfill(sSet1,10); 
   cfill(sSet2,10); 

   cdisplay(sSet1);
   cdisplay(sSet2);
   
   //set_intersection(sSet1.begin(),sSet1.end(),sSet2.begin(),sSet2.end(),back_inserter(sVec));

   cdisplay(sVec);
  

   return 0;
}

*/


///////////////////////////////////////////////////////////////////
/// Ex8

/*

int main()
{

   set<string> s1;
   set<string> s2;
   vector<string> sVec;

   cfill(s1,10); 
   cfill(s2,10); 

   cdisplay(s1);
   cdisplay(s2);
   
   mysetIntersection(s1.begin(),s1.end(),s2.begin(),s2.end(),sVec);

   cdisplay(sVec);
  

   return 0;
}

*/

///////////////////////////////////////////////////////////////////
/// Ex9

int main()
{

   set<string> s1;
   set<string> s2;
   vector<string> sVec;
   Randomize();
   cfill(s1,10); 
   cfill(s2,10); 

   cdisplay(s1);
   cdisplay(s2);
   
   mysetUnion(s1.begin(),s1.end(),s2.begin(),s2.end(),sVec);

   cdisplay(sVec);
  

   return 0;
}


// Associative containers + set container