////////////////////////////////////////////////////
////////////////////////////////////////////////////
/// special int



#include <iostream>
#include <iosfwd>

using namespace std;

class sint
{
private:
   int mVal;

public:
   bool operator<(const sint &r) const;
   bool operator<=(const sint &r) const;
   bool operator>(const sint &r) const;
   bool operator>=(const sint &r) const;
   bool operator==(const sint &r) const;
   bool operator!=(const sint &r) const;

   sint operator=(const sint &r) const;
   sint operator*(const sint &r) const;
   sint operator-(const sint &r) const;
   sint operator+(const sint &r) const;
   sint operator/(const sint &r) const;
   sint operator%(const sint &r) const;

   sint(int val=0);

   void display() const;

   friend std::ostream& operator<<(std::ostream &os, const sint &r);
   friend std::istream& operator>>(std::istream &os, sint &r);

   sint &operator-=(const sint &r);
   sint &operator+=(const sint &r);
   sint &operator*=(const sint &r);
   sint &operator%=(const sint &r);
   sint &operator/=(const sint &r);

   operator int() const        // -> integer
   {
     return mVal;
   }
   
   // operator int => sint -> int

   // int operator int() const;   //syntax error

};

sint::sint(int val) : mVal(val)
{
}

std::ostream& operator<<(std::ostream &os, const sint &r)
{
   return os << "(" << r.mVal << ")" ;
}

std::istream &operator>>(std::istream &is,sint &r)
{ 
    return is >> r.mVal;
}

bool sint::operator<(const sint &r) const // if (a<b) a.operator(b)
{
    return mVal < r.mVal ;
}
bool sint::operator>(const sint &r) const
{
    return r < *this;       // conversion constructor
    // return r.mVal < this->mVal 
}

bool sint::operator<=(const sint &r) const  //if(x<=y) -> x.operator<=(y)
{  
    return mVal <= r.mVal ;
}
bool sint::operator>=(const sint &r) const
{
     return !(r <= *this);
     //  return r.mVal >= this->mVal
}
bool sint::operator==(const sint &r) const
{
    return !(*this < r ) && !(r < *this);
}
bool sint::operator!=(const sint &r) const
{
      return (*this < r ) || (r < *this);
}


sint sint::operator+(const sint &r) const
{
    
   // c = (a+b) -> a.operator(b)
    
   return mVal + r.mVal; // conversion constructor
}
sint sint::operator-(const sint &r) const
{
    
   // c = (a+b) -> a.operator(b)
    
   return mVal - r.mVal; // conversion constructor
}

sint sint::operator/(const sint &r) const
{
    return sint(mVal/r.mVal);
}

sint sint::operator*(const sint &r) const
{
    return sint(this->mVal*r.mVal);
}

sint sint::operator%(const sint &r) const
{
    return sint(this->mVal%r.mVal);
}
sint sint::operator=(const sint &r) const     // a = b ;   a.operator=(b) 
{   
    sint z ;
    z.mVal = r.mVal;
    return z;
}

sint &sint::operator+=(const sint &r)  // x += t => x = x + y; x.operator(y) => this -> x , r -> y 
{
    mVal += r.mVal;
   return *this;
}

sint &sint::operator-=(const sint &r)  
{
    mVal -= r.mVal;
   return *this;
}

sint &sint::operator*=(const sint &r)  
{
    mVal *= r.mVal;
   return *this;
}

sint &sint::operator/=(const sint &r)   
{
    mVal /= r.mVal;
   return *this;
}

sint &sint::operator%=(const sint &r)  
{
    mVal %= r.mVal;
   return *this;
}
/*

*/



int main()
{
    sint x(30),y(20);

   cout << x << y << endl;

/*
   if( x > y)
   {
    cout << "x is bigger than y!"<< endl;
   }
    if( y < x)
   {
    cout << "y is smaller than y!"<< endl;
   }
   if(x==y)
   {
      cout << "x is equal to y! " << endl;
   }
   else{
    cout << "x is not equal to y! " << endl;
   }*/

  sint z(10);
  
  z += y;
   
  // z = x + y;
  

  cout << "z : " << z << endl;
  cout << "fahri " << endl;
  return 0;
}









/// special int
////////////////////////////////////////////////////
////////////////////////////////////////////////////