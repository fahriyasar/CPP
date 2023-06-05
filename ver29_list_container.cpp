////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
// c++ list container

/*

this is a standard doubly linked list!

*the advantage is that it has constant time cost if we know the position

if the the data structure is moduler, then we have what ?

* we dont need a constant memory block!
* pointer swapping(huge advantage for the cost)
* only pointer is added to the list when we want to add or to remove data
* STL has object semantic, copy constructor is nedded!
* Container membership function is used for the container! (main advantage)

*/



#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>

using namespace std;



template<class U>
void display(U beg,U end)
{
    for(auto iter = beg;iter != end ; iter++)
    {
        cout << *iter << " ";
    }
    cout << endl;
}

string srandom()
{
    static const char *const pnames[] = { "mehmet",
                                          "ali",
                                          "kamuran",
                                          "fahri",
                                          "sude",
                                          "recep",
                                          "yildiz",
                                          "selin",
                                          "sule",
                                          "celil",
                                          "beyza",
                                          "sinasi"};
    size_t size = sizeof(pnames)/sizeof(*pnames);
    
    return pnames[rand()%size];
}

template<class Scon>
void cfill(Scon &con,int size)
{
    //standard template library should need additional information!
    //generate_n(inserter(con,con.begin()),size,srandom);

    for(int k=0;k<size;k++)
    {
        con.push_back(srandom());
    }
}

void Randomize()
{
    srand(static_cast<unsigned>(time(0)));
}

template<class Scon>
void cdisplay(Scon &con)
{
    for(typename Scon::iterator iter = con.begin();iter!=con.end();++iter)
    {
        cout << *iter << " ";
    }
    cout << endl ;
}

///////////////////////////////////////////////////////
/// Ex1

/*


int main()
{ 
    list<string> slist1;
    list<string> slist2;

    Randomize();

    cfill(slist1,10);
    cfill(slist2,10);

    cdisplay(slist1);
    cdisplay(slist2);

    slist1.sort();
    slist2.sort();


    cdisplay(slist1);
    cdisplay(slist2);

    // merge operation -> copy all things stored in any container to another one
    slist1.merge(slist2);   // sequence order is preserved!      ex : strcat!


     cdisplay(slist1);

    return 0;
}
*/

///////////////////////////////////////////////////////
/// Ex2
/*

int main()
{ 
    list<string> slist1;
    list<string> slist2;

    Randomize();

    cfill(slist1,10);
    cfill(slist2,10);

    cdisplay(slist1);
    cdisplay(slist2);

    cout << "splice is coming!" <<endl;

    // adding slist2 to the begin of slist1

    slist1.splice(slist1.begin(),slist2);

    cdisplay(slist1);




    return 0;
}

*/
///////////////////////////////////////////////////////
/// Ex3


int main()
{ 
    list<string> slist1;
    Randomize();

    cfill(slist1,10);

    cdisplay(slist1);
  
   // slist1.erase(slist1.begin());
   
   slist1.erase(++slist1.begin(),--slist1.end());
   

    cdisplay(slist1);


    return 0;
}



// c++ list container
////////////////////////////////////////////////////////
///////////////////////////////////////////////////////
