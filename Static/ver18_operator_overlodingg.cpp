//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
/// Array Class

/*

special operator functions

vector -> dynamic array class(linked list,malloc,calloc)

[] operator  -> a[k] -> *(a+k)

Ther are five conditions to be required for [] operator!

(1) vector (2) deque (3) string (4) bit set (5) map (binary search tree)

RULE

* it must be a function of class (member function!)

class
{
public:
  int &operator[](int, double,....)
 

};

*/


///////////////////////////////////////////////////////////////
// ex1


#include <iostream>

using namespace std;

class Array
{
private:
    int mSize;
    int *mpd;
public:
    const int &operator[](int index) const;
    int &operator[](int index);
    const int &at(int index) const;
    int &at(int index);
    Array(int n);
    ~Array();
    Array(const Array &r);
    void display() const;
   Array &operator=(const Array &r);
   int size() const
   {
    return mSize;
   }
};


Array::Array(int n) : mSize(n),mpd(new int[mSize])
{
    for(int k = 0; k < mSize; k++)
    {
        mpd[k] = k;
    }
}
Array::~Array()
{
    delete[] mpd;
}

Array::Array(const Array &other) : mSize(other.mSize),mpd(new int[mSize])
{
    for(int k=0;k<mSize;k++)
    {
        mpd[k] = other.mpd[k];
    }
}

void Array::display() const
{
    cout << "(";

    for(int k=0;k<mSize;k++)
    {
        if(k != mSize-1)
        {
            cout << mpd[k]<<" ";
        }
        else
        {
          cout << mpd[k] << ")" << endl;
        }
    }
}

////////////////////////////
// Assigment function

int &Array::at(int index)
{
    cout << "Unconst " <<endl;
    return mpd[index];
}

const int &Array::at(int index) const
{
    cout << "Const at" << endl;
    return mpd[index];
}




/////////////////////////////
/// Operators

Array &Array::operator=(const Array &other)
{

   cout << "Operator= " << endl;
   if(this == &other)
   {
    return *this;
   }
   delete[] mpd;
   this->mSize = other.mSize;

   this->mpd = new int[this->mSize];
   
   for(int k=0;k<mSize;k++)
   {
    this->mpd[k] = other.mpd[k];
   }
   return *this;
}

///////
////
/*

Error nedeni don't redeclare error alıyorum... 

int Array::&operator[](int index)  // a[5] writing
(
    return mpd[index];
)

const int &Array::operator[](int index) const   // reading
(
    return mpd[index];
)

*/

//////////////////////////
// Ex1

/*
int main()
{
   Array a(10);

   a.display();

    return 0;
}

*/

/////////////////////////
//eX2
/*
int main()
{
    Array a(10);
    const Array b(10); // İlk değerlerini ilk önce direk atıyor.
    
    a.display();
    b.display();

    for(int k=0;k < a.size();k++)
    {
        a.at(k) = k*k;
    }
    a.display();

    // b.at(4) = 9;   // b -> const,syntax error

    int x = a.at(6);        // x.operator(a.at(6)) görünmüyor. Çünkü x class türünden değil.
    

    

    return 0;
}
*/

//////////////////////////////////////
/// ex3
/*
int main()
{
    Array a(10);
    Array b(10); // İlk değerlerini ilk önce direk atıyor.
    
    a.display();
    b.display();

    for(int k=0;k < a.size();k++)
    {
        a.at(k) = k*k;
    }
    a.display();
     
    b = a;     // b.operator=(a) 
    
    b.display();
    
    const Array c(19);

    cout << c.at(5) << endl;
    

    return 0;
}

*/



