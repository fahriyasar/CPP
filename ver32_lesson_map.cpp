////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// associative containers + map container

/*


map container

* binary search tree, one key + one data
* data can be changed!
*pair contaiiner is used to create this mechanism!
*map<int,string> ismap; (pair<int,string> is masked in here!)

*/


////////////////////////////////////////////////
// ex1

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <functional>
#include <set>
#include <map>
#include <string>

using namespace std;


void Randomize()
{
    srand(static_cast<unsigned>(time(0)));
}

int irandom()
{
    return static_cast<int>(rand()%1000);
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

//////////////////////////////////////////////////////////
// Template

template<class Gcon>
void cfill(Gcon &con,int size)
{
    // generates random key and number for given irandom and srandom function
    
    for(size_t i=0; i<size; i++)
    {
        con.insert(map<int,string>::value_type(irandom(),srandom()));
        // con.insert(make_pair(irandom(),srandom()));
    }  
}

template <class Scon>
void cdisplay(const Scon &con)
{
    // displaying all names and keys stored in con
    for(typename Scon::const_iterator iter = con.begin(); iter!=con.end();iter++)
    {
        cout << iter->first << " " << iter->second << endl; 
    }
}

template<class T>
class myless
{
private:

public:
    constexpr bool operator()(const T &left,const T &right)
    {
      return left < right;
    }
};
/*
template<class T,class U>
void eraseVal(map<T,U> &con,const U value)
{
   auto iter = con.begin();
   
   for(;iter =!con.end();iter++)
   {
    if(iter->second == value)
    {
        con.erase(iter);
    }
   }
}
*/


///////////////////////////////////////////////////////////////
//// Ex1

/*

int main()
{
   map<int,string> ismap; // int -> key, string -> data

   cout << "Value type of map : " << typeid(map<int,string>::value_type).name() << endl;
   cout << "Value type of map : " << typeid(map<int,string>::key_type).name() << endl; 
   cout << "Value type of map : " << typeid(map<int,string>::mapped_type).name() << endl;   

   return 0;
}
*/


///////////////////////////////////////////////////////////////
//// Ex2
/*

int main()
{  
    map<int,string,less<int>> ismap1;
    //map<string,string,less<int>> ismap2; // syntax error 

    map<int,string,less<char>> ismap3;
    map<char,string, less<int>> ismap4;   // char-> int (natural type)
    map<char,string,less<string>> ismap5; 



    return 0;
}

*/


///////////////////////////////////////////////////////////////
//// Ex3

/*

int main()
{
    map<int,string> ismap;
    
     ismap.insert(pair<int,string>(111,"mehmet")); // pair has constructor
     //ismap.insert(new pair<int,string>(112,"ali")); // pointer overload is not included!
     ismap.insert(*(new pair<int,string>(113,"fahri"))); //  asterisk can be used to perform "new" keyword!
     
     ismap.insert(map<int,string>::value_type(114,"hatice")); //value_type -> pair
     ismap.insert(make_pair(33,"kamil"));

     for(map<int,string>::iterator iter = ismap.begin(); iter != ismap.end(); ++iter)
     {
        //cout << *iter << endl; // pair does not have default asterisk operator!
        cout << iter->first << " " << iter->second << " " << endl;
     }


    return 0;
}

*/


/////////////////////////////////////////////////////7
// Ex4
/*
int main()
{
   Randomize();

   map<int,string> ismap;

   cfill(ismap,10);

   cdisplay(ismap);



    return 0;
}
*/

//////////////////////////////////////////////7
/// ex 4.1
/*
int main()
{
    Randomize();

    //map<int,string> ismap;  // unique container(with respect to key)

    //map<int,string, less<int>> ismap;

    map<int,string,greater<int>> ismap; 

    cfill(ismap,10);

    cdisplay(ismap);


    return 0;
}
*/

//////////////////////////////////////////////7
/// ex 4.2

/*
int main()
{
    Randomize();

    map<int,string,myless<int>> ismap; 

    cfill(ismap,10);

    cdisplay(ismap);


    return 0;
}*/

//////////////////////////////////////////////7
/// ex 5.3

/*

int main()
{
    Randomize();

    map<string,int> ismap; 
  
    for(int i=0;i<10;i++)
    {
        ismap.insert(make_pair(srandom(),irandom()));
    }

    cout << "Old Map : " << endl;
    cdisplay(ismap);
    int s;
    cin >> s;
    eraseVal(ismap,s);
    
    cout << "New map : " << endl;
    
    cdisplay(ismap);
    return 0;
}

*/

// associative containers + map container
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
