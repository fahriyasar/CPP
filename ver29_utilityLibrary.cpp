////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//// c++ utility library / container template design


/*

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>

using namespace std;

typedef list<string> Container;

// declerations
void Randomize(); 
void delay(double);
void cfill(Container,int);
void cdisplay(Container);
ostream &s1(ostream &);   // not using namespace std;
string srandom();    // random string 

// for related templates

template<class Scon>
void cfill(const Scon &con,int size)
{
    generate_n(inserter(con,con.begin()),size,srandom);
}

template<class Scon>
void cdisplay(const Scon &con)
{
    //displaying all names stored in con
    // =,!=, ++ operator overloading
    for(typename Scon::const_iterator iter = con.begin(); iter != con.end; ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}


int main()
{
    Container c;
    Randomize();  // random number -> random string
   
   cout << "starting..." << endl;

   delay(2.0);

   cfill(c,10);

   cdisplay(c);
   return 0;
}

void Randomize()
{
    srand(static_cast<unsigned>(time(0)));
}

ostream &s1(ostream &os)
{
    return os << "\n****.****" << endl;
}

void delay(double sec)
{
    cout << "Delay is start for a " << sec << "seconds!" << endl;

    clock_t start = clock();

    while(static_cast<double>(clock()-start)/CLOCKS_PER_SEC < sec);

}

str ing srandom()
{
    static const char * const pnames[] = {"mehmet",
                                          "ali",
                                          "burak",
                                          "gözde",
                                          "halil",
                                          "baran",
                                          "selçuk",
                                          "kamuran"};

    size_t size =sizeof(pnames)/sizeof(*pnames);

    return pnames[rand()%size];
}

*/
//// c++ utility library / container template design
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
