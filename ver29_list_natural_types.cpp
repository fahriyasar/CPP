////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//// C++ List CONTAİNER Natural types


#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

////////////////////////////////////////
void Randomize()
{
    srand(static_cast<unsigned>(time(0)));
}


template<class Gcon>
void cdisplay(const Gcon &con)
{
    for(typename Gcon::const_iterator iter = con.begin();iter!=con.end(); ++iter)
    {
        cout << *iter <<" " ;
    }
    cout << endl;
}

template<class T>
T naturalRandom(T minValue,T maxValue)
{
    double value = static_cast<double>(rand())/RAND_MAX;
    T returnValue = static_cast<T>(minValue+value*(maxValue-minValue));
    return returnValue;
}

template<class T,class Gcon>
void cfill(Gcon &con, int size,T minValue, T maxValue)
{
   for(int i =0; i<size; i++)
   {
     con.push_back(naturalRandom(minValue,maxValue));
   }
}                        

template<class T>
auto cSum(T beg, T end)
{
    // T-> lis<int>::iterator , T* -> int
    auto sumValue = *beg - *beg;      // type detection related to the internal variable(int,double)
    
    for(auto iter = beg; iter != end; iter++)
    {
        sumValue = sumValue + *iter ;
    }

    return sumValue;
}

template<class T>
auto cMean(T beg,T end)
{
    auto sulValue = *beg - *beg;
    int counter = 0;
    
    for(auto iter= beg; iter != end ; iter++)
    {
        sulValue += *iter;
        counter++;
    }

    auto result = static_cast<double>(sulValue)/counter;
    return result;
}

template<class T,class Gcon>
void cSumTwoList(T beg1,T end1,T beg2,T end2,Gcon &con)
{
    auto iter1 = beg1;
    auto iter2 = beg2;

    while(iter1!=end1 && iter2!=end2)
    {
        con.push_back(*iter1+*iter2);
        iter1++;
        iter2++;
    }
}

template<class T>
void cSumTwoListIt(T beg1,T end1,T beg2,T end2,T beg3,T end3)
{
    auto iter1 = beg1;
    auto iter2 = beg2;
    auto iter3 = beg3;

    while(iter1!=end1 && iter2!=end2 && iter3!=end3)
    {
        *iter3 = (*iter1+*iter2);
        iter1++;
        iter2++;
        iter3++;
    }
}

///////////////////////////////////////////////////////
/// Swap iterator

template<class T>
void swap(T &x,T &y)
{
    T temp;
    temp =  x;
    x = y;
    y = temp;
}

template<typename T,class U>
void swapListElementListIt(T beg1,T end1,U beg2,U end2)
{
      auto iter1 = beg1;
      auto iter2 = beg2;
      auto defaultValue = *beg1-*beg1;

      while(iter1!=end1 && iter2!=end2)
      {
        //swap(*iter1,*iter2);

        defaultValue = *iter1;
        *iter1 = *iter2;
        *iter2 = defaultValue;

        iter1++;
        iter2++;
      }
}

////////////////////////////////////////////////////
/// swap container

template<class Gcon>
void swapListElement(Gcon &con1 , Gcon &con2)
{
    auto iter1 = con1.begin();
    auto iter2 = con2.begin();
    auto defaultValue = *iter1-*iter1;

    for(;iter1!=con1.end()&&iter2!=con2.end();defaultValue = *iter1,*iter1 = *iter2,*iter2 = defaultValue,*iter2++,iter1++)
      ;
    
}

template<class T,class U>
void reverseSwapIsElement(T beg1,T end1,U beg2,U end2)
{
   auto iter1 = beg1;
   auto iter2 = beg2;
   auto defaultValue = *beg1 - *beg1;
   while(iter1 != end1 && iter2 != end2)
   {
      defaultValue = *iter1;
      *iter1 = *iter2;
      *iter2 = defaultValue;

      iter1++;
      iter2++;
   }
}

template<class Gcon1,class Gcon2>
void reverseSwapIsElementCon(Gcon1 &c1,Gcon2 &c2)
{
   typename Gcon1::iterator iter1 = c1.begin();
   typename Gcon2::reverse_iterator iter2 = c2.rbegin();
   auto defaultValue = *iter1 - *iter1;

   for(;iter1!=c1.end()&& iter2 != c2.rend();iter1++,iter2++)
   {
      defaultValue = *iter1;
      *iter1 = *iter2;
      *iter2 = defaultValue;
   }
}

template<class Gcon1,class Gcon2>
void reverseSwapIsElementCon2(Gcon1 &c1,Gcon2 &c2)
{
   typename Gcon1::iterator iter1 = c1.begin();
   typename Gcon2::reverse_iterator iter2 = --c2.end();
   auto defaultValue = *iter1 - *iter1;

   for(;iter1!=c1.end() && iter2 != --c2.begin();iter1++,iter2--)
   {
      defaultValue = *iter1;
      *iter1 = *iter2;
      *iter2 = defaultValue;
   }
}

template<typename T>
auto findMaxIt(T beg,T end)
{
   auto iter = beg;
   auto maxValue = *iter;

   for(;iter!=end;iter++)
   {
    if(*iter>maxValue)
    {
        maxValue = *iter; 
    }
   }

   return maxValue;
}

template<typename T>
auto findMinIt(T beg,T end)
{
   auto iter = beg;
   auto minValue = *iter;

   while(iter != end)
   {
     if(*iter < minValue)
     {
        minValue = *iter;
     }
     iter++;
   }

   return minValue;
}

template<class T >
bool predicateFuncBigger(const T &r1,const T &r2)
{
    return r1 > r2; 
}

template<class T>
bool predicateFuncSmaller(const T &r1, const T &r2)
{
    return r1<r2;
}


/////////////////////////////////////////
// Algorithms

template<class T>
void sortListIt(T beg,T end) // bubble sort
{
    auto sortBeg = beg ;
    auto sortEnd = end ;
    size_t size = 0;
    while(beg!=end)
    {
        size++;
        beg++;
    }

    for(size_t i=0;i<size-1;i++)
    {
        auto sortBegForward = sortBeg;
        for(size_t k=0;k<size-1-i;k++)
        {
          sortBegForward++;
          if(*sortBeg> *sortBegForward)
          {
            auto defaultValue = *sortBeg;
            *sortBeg = *sortBegForward;
            *sortBegForward = defaultValue;
          }
        }
     sortBeg++;
    }
}

////////////////////////////////////////////////
//// ex1
/*
int main()
{
    list<double> iList;

    Randomize();

    cfill(iList,10,0.0,10.0);

    cdisplay(iList);

    return 0;
}
*/


////////////////////////////////////////////////
//// ex2

/*

int main()
{
    list<int> iList;

    Randomize();

    cfill(iList,10,0,10);

    cdisplay(iList);

    auto resultSum = cSum(iList.begin(),iList.end());

    cout << resultSum << endl;

    return 0;
}


*/

/////////////////////////////////////////////////
/// Ex3

/*

int main()
{
   Randomize();

   list<double> iList;
   cfill(iList,10,0.0,10.0);

   cdisplay(iList);

   auto resultSum = cSum(iList.begin(),iList.end());

   cout << "Result of sum " << resultSum << endl;

   auto resultmean = cMean(iList.begin(),iList.end());

   cout << "Result of mean " << resultmean << endl;

   return 0;
}
*/

////////////////////////////////////////////////////
/// Ex4

/*

int main()
{
    list<int> list1;
    list<int> list2;
   
    Randomize();
    cfill(list1,10,0,10);
    cfill(list2,10,0,10);

    //list<int> list3;
    //cSumTwoList(list1.begin(),list1.end(),list2.begin(),list2.end(),list3);
    // push_back function is used!

    list<int> list3(10); // store 10 address pointrepresenting to list<int> nodes
    cSumTwoListIt(list1.begin(),list1.end(),list2.begin(),list2.end(),list3.begin(),list3.end());
    // iterator requires storage area in memory block!

    cdisplay(list1);
    cdisplay(list2);
    cdisplay(list3);
    return 0;
}

*/

//////////////////////////////////////////////////
/// Ex5

/*

int main()
{
   list<int> list1;
   list<int> list2;

   Randomize();

   cfill(list1,10,0,10);
   cfill(list2,10,0,10);

   cdisplay(list1);
   cdisplay(list2);

   //swapListElementListIt(list1.begin(),list1.end(),list2.begin(),list2.end());

   swapListElement(list1,list2);

   cdisplay(list1);
   cdisplay(list2);



    return 0;
}


*/


/////////////////////////////////////////////////
///Ex6 
/*

int main()
{
   list<int> ilist1;
   vector<int> ivec1;
    
   Randomize();

   cfill(ilist1,10,0,10);
   cfill(ivec1,10,0,10);
   
   cout << "General structures are written..." << endl;

   cdisplay(ilist1);
   cdisplay(ivec1);

   swapListElementListIt(ilist1.begin(),ilist1.end(),ivec1.begin(),ivec1.end());


   cout << "General structures are written..." << endl;

   cdisplay(ilist1);
   cdisplay(ivec1);


    return 0;
}
*/

///////////////////////////////////////////////////////////////////////
//// Ex7 
/*
int main()
{
    list<int> ilist1;

    Randomize();

    cfill(ilist1,10,0.0,10.0);

    cdisplay(ilist1);

    vector<int> iVec;

    cfill(iVec,10,0.0,10.0);

    cdisplay(iVec);

    //Standard Template Library (STL) is the same way to accomplish swap operation
    reverseSwapIsElement(ilist1.begin(),ilist1.end(),iVec.rbegin(),iVec.rend());

    cout << "Transfered elements from list1 to list2 is ... " << endl;

    cdisplay(ilist1);
    cdisplay(iVec);
    return 0;
}
*/


///////////////////////////////////////////////////////////////////////
//// Ex8

/*

int main()
{
    list<int> ilist1;

    Randomize();

    cfill(ilist1,10,0.0,10.0);

    cdisplay(ilist1);

    vector<int> iVec;

    cfill(iVec,10,0.0,10.0);

    cdisplay(iVec);

    //Standard Template Library (STL) is the same way to accomplish swap operation
    reverseSwapIsElementCon(ilist1,iVec);

    cout << "Transfered elements from list1 to list2 is ... " << endl;

    cdisplay(ilist1);
    cdisplay(iVec);
    return 0;
}

*/


///////////////////////////////////////////////////////////////////
// Ex9

/* 

int main()
{
   Randomize();

   list<double> list1;
   list<double> list2;

   cfill(list1,10,0.0,1000.0);
   cfill(list2,10,0.0,1000.0);

   list1.sort();
   list2.sort();

   cdisplay(list1);
   cdisplay(list2);

   cout << "Max value of the listt1 : " << findMaxIt(list1.begin(),list1.end()) << endl;
   cout << "Max value of the listt2 : " << findMaxIt(list2.begin(),list2.end()) << endl;

   cout << "Min value of the listt1 : " << findMinIt(list1.begin(),list1.end()) << endl;
   cout << "Min value of the listt2 : " << findMinIt(list2.begin(),list2.end()) << endl;


    return 0;
}

*/


//////////////////////////////////////////////////////
/// EX 10

/*
int main()
{
   Randomize();

   list<int> list1;
   list<int> list2;

   cfill(list1,10,0,10);
   cfill(list2,10,0,10);
   
   cdisplay(list1);
   cdisplay(list2);

   cout << "Bigger" << endl;

   list1.sort(&predicateFuncBigger<int>);
   list2.sort(&predicateFuncBigger<int>);
   
   cdisplay(list1);
   cdisplay(list2);

   list1.sort(&predicateFuncSmaller<int>);
   list2.sort(&predicateFuncSmaller<int>);

   cout << "Smaller" << endl;
   
   cdisplay(list1);
   cdisplay(list2);
   



   return 0;
}
*/
///////////////////////////////////////////////
// Ex 11
/*

int main()
{
    Randomize();
    
    list<double> List1;

    cfill(List1,10,0.0,1000.0);

    cdisplay(List1);

    sortListIt(List1.begin(),List1.end());

    cdisplay(List1);


    return 0;
}

*/

//////////////////////////////////////////////////////////////
/// Ex12

// template copy function

int main()
{  
   Randomize();

   list<int> list1;

   cfill(list1,10,0.0,10.0);
   cdisplay(list1);

   list<int> list2;

   cfill(list2,10,0.0,10.0);
   cdisplay(list2);


 


    return 0;
}





//// C++ List CONTAİNER Natural types
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
