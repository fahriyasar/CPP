////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
// searching functining for list continer


////////////////////////////////////////////////////////////////
// Ex1

// null pointer -> can be obtained by using end() in c++

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iterator>
#include <vector>

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

template<class InIter,class T>
InIter myFind(InIter beg,InIter end,const T &mVal)
{
    while(beg!=end)
    {
        if(mVal== *beg )
        {
            return beg;
        }
        beg++;
    }
    return beg;
}


bool predicateFunc(const std::string &r1,const std::string &r2)
{
    return r1.size() == r2.size();
}

template<class InIter,class UnPred>
InIter myFindIf(InIter beg,InIter end,UnPred pred)
{
    auto initer = beg;
    while(beg !=end && !pred(*beg,*++initer))
    {
      beg++;                                                                                                                                                                                                                                                                   beg++;
    }
    return beg;
}







/////////////////////////////////////////////////
/// ex1

/*
int main()
{
   list<string> slist;

   Randomize();

   cfill(slist,10);
 
   cdisplay(slist);

   string s;

   cout << "The name needs to be found" << endl;
   cin >> s;

   list<string>::iterator iter = slist.begin();

   iter = myFind(slist.begin(),slist.end(),s);

   cout << "Searching value : " << *iter << endl;

   if(iter != slist.end())
   {
    slist.erase(iter);
   }
   cdisplay(slist);

   return 0;
}
*/


////////////////////////////////////////////////////////////////
/// Ex2

/*
#include <iostream>

using namespace std;

int main()
{
   list<string> slist;

   Randomize();

   cfill(slist,10);

   cdisplay(slist);

   string s;

   cout << "The name needs to be found" << endl;
   cin >> s;

   list<string>::iterator iter = slist.begin();

   while(iter != slist.end())
   {
      iter = myFind(slist.begin(),slist.end(),s);
      if(iter != slist.end())
      {
        slist.erase(iter);
      }
      cdisplay(slist);
      cout << endl;

   }



    return 0;
}
*/

/////////////////////////////////////////////////////////////////
/// Ex3 

/*
int main()
{
    list<string> slist;

    Randomize();

    cfill(slist,10);

    cdisplay(slist);

    list<string>::iterator iter = slist.begin();

    cout << "Deleting process is started" << endl;

    while(iter!=slist.end())
    {
        iter = myFindIf(slist.begin(),slist.end(),&predicateFunc);

        if(iter!=slist.end())
        {
            slist.erase(iter);
        }
        cdisplay(slist);
        cout << endl;
    }

    cout << "Deleting process is ended" << endl;
}

*/


///////////////////////////////////////////////////////////////
/// EX4

// assign function

/*

int main()
{
     vector<string> sVec;

     cfill(sVec,10);
     cdisplay(sVec);

     list<string> sList;

     cfill(sList,10);
     cdisplay(sList);
     
     //sList = sVec ;  // iterator cannot be used in assignment!
     // sList.operator=(sVec);

     sList.assign(sVec.begin(),sVec.end());
     cdisplay(sList);

    return 0;
}

*/


///////////////////////////////////////////////////
// Ex5

// resize function

/*


int main()
{
   list<string> sList;

   cfill(sList,10);   // PUSH BACK

   cdisplay(sList);

   cout << sList.size() << endl;

   sList.resize(20 ,"ammar" );   // copy constructor

   cdisplay(sList);

   cout << sList.size() << endl;



    return 0;
}

*/
///////////////////////////////////////////////////
// ex6
/*

int main()
{
   const char *p[5] = {"x","y","z","a","b"};

   list<string> sList;

   Randomize();

   cfill(sList,10);
   cdisplay(sList);

   sList.insert(sList.begin(),"first");
   sList.insert(++sList.begin(),"SECOND");
   cdisplay(sList);
   /*for(auto iter = sList.begin();iter!=sList.end();iter)
   {
    sList.insert(sList.begin(),"first") ;
   }

    sList.insert(++sList.begin(),5,"555");
    cdisplay(sList);

    sList.insert(sList.begin(),p,p+5);
    cdisplay(sList);



    return 0;
}
*/

///////////////////////////////////////////////////
// ex7

/*

* In STL, an algorithm can achieve a deletion proccess.

* However ,STL contains only iterators indications specific address of it.

*In container approach, we cannot delete object physically, Only removing indicaterpointers is proceeded.

*/

////////////////////////////////////////////////////

/*
int main()
{ 
    vector<string> sVec;

    Randomize();

    cfill(sVec,10);

    cdisplay(sVec);
     
    string s;

    cout << "The name needs to be deleted : " ;
    cin>>s;

    remove(sVec.begin(),sVec.end(),s);
    
    // removing the whole string names
    // however the points is removed, not the string value


    cdisplay(sVec);


    return 0;
}
*/


//////////////////////////////////////////////////////////
///// Ex 7.1


/*
int main()
{
    vector<string> sVec;

    Randomize();

    cfill(sVec,10);

    cdisplay(sVec);
     
    string s;

    cout << "The name needs to be deleted : " ;
    cin>>s;

    remove(sVec.begin(),sVec.end(),s);
    
    cdisplay(sVec);


    return 0;
}

*/

//////////////////////////////////////////////////
//// Ex8
/*

int main()
{
    vector<string> sVec;

    Randomize();

    cfill(sVec,10);

    cdisplay(sVec);
     
    string s;

    cout << "The name needs to be deleted : " ;
    cin>>s;

    sVec.erase(remove(sVec.begin(),sVec.end(),s),sVec.end());
    
    cdisplay(sVec);


    return 0;
}

*/


///////////////////////////////////////////7
//// Ex10

/*

Comprison between Range and Container

- if iterator  is used to compare elements, any container can be applied to these algorithms

There are three algorithms

1-) Lexicographical compare algorithm
2-) equal algorithm
3-) mismatch algorithm
*/


// - Lexicographical compare algorithm 

/*

int main()
{
    vector<string> sVec(3);

    sVec[0] = "a";
    sVec[1] = "b";
    sVec[2] = "c";
    
    cout << "Displaying sVec... " << endl;

    cdisplay(sVec);

    list<string> sList(sVec.begin(),sVec.end());

    cout << "Displaying sList... " << endl;

    cdisplay(sList);

    sList.back() = "x";
    
    cdisplay(sList);
    
    cout << "Comprison for sList/sVec : " << endl;

    cout << boolalpha << lexicographical_compare(sVec.begin(),sVec.end(),sList.begin(),sList.end()) << endl;
    //lexicographical_compare only evaluate either one word is bigger than other string!

    return 0;
}

*/


/////////////////////////////////////////////////////////////
//// Ex11

// equal
/*
int main()
{
   vector<string> sVec(3);

   sVec[0] = "x";
   sVec[1] = "y";
   sVec[2] = "z";
  
   list<string> sList(sVec.begin(),sVec.end());

   cout << "Comparison is began!" <<endl;

   cout << boolalpha << equal(sVec.begin(),sVec.end(),sList.begin(),sList.end())<< endl;



    return 0;
}*/


//////////////////////////////////////////////////////
//// mismatch algorithm  = > pair


int main()
{
   vector<string> sVec(3);
   sVec[0] = "x" ;
   sVec[1] = "y" ;
   sVec[2] = "z" ;

   list<string>  sList(sVec.begin(),sVec.end());

   pair<vector<string>::iterator,list<string>::iterator> mispair;

   sList.front() = "Mehmet";
   sList.back() = "fahri" ;
    
   mispair = mismatch(sVec.begin(),sVec.end(),sList.begin(),sList.end());

   cout << *mispair.first << endl;
   cout << *mispair.second << endl;


    return 0;
}




// searching functining for list container
////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
