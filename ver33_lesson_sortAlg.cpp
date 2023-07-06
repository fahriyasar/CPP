/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
//// Sort Algorithms



/*

- stable sort -> unique element!
- partial sort -> partial section is sorted!
- partial sort copy -> firstly, partical section is sorted but also copied!
- n th element : indicating direct position to be sorted!

*/
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

template<class T>
T numberRandom()
{
    if(string(typeid(T).name()) == "i")
        return static_cast<int>(rand())%100;

    return static_cast<T>(rand()) / RAND_MAX*100;
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
void cfillString(Gcon &con,int size)
{
    
    for(size_t i=0; i<size; i++)
    {
        con.push_back(srandom());
    }  
}

template<class Gcon>
void cfillNumbers(Gcon &con,int size)
{
    typename Gcon::iterator iter;

    for(size_t i=0; i<size; i++)
    {
        con.push_back(numberRandom<typename Gcon::value_type>());
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



/////////////////////////////////////////////////////////////
// Ex1

/*
int main()
{
    Randomize();

    vector<string> sVec;

    cfillString(sVec,10);

    cdisplay(sVec);

    vector<int> dVec;
    
    cfillNumbers(dVec,10);
    cdisplay(dVec);


    return 0;
}*/

/////////////////////////////////////////////////////////////////
///// 

int main()
{
    Randomize();

    vector<string> sVec;

    cfillString(sVec,10);

    cdisplay(sVec);

    sort(sVec.begin(),sVec.end());

    cout << "Sorted sVec is..." << endl;
    cdisplay(sVec);



    return 0;
}




//// Sort Algorithms
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
