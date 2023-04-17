///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
// Complex Number 

/*

////////////////////////////////////////////////////////////
// ex1


#include <iostream>

using namespace std;

class ComplexNumber
{
private:
    double real,imag;
public:

    ComplexNumber(double r=10, double i=10)
    {
       real = r;
       imag = i;
      // cout << "r,i constructor" << endl;
    }
    ~ComplexNumber()
    {
        //cout << "Destructor" << endl;
    }
    void display() const
    {
        cout << real << " + j" << imag << endl;
    }

    // operator overloading
    
    ComplexNumber operator+(ComplexNumber const &r)
    {
        ComplexNumber com1;
        com1.imag = this->imag + r.imag;
        com1.real = this->real + r.real;
        return com1;
    }
    ComplexNumber &operator=(ComplexNumber const &r)
    {
       this->real = r.real;
       this->imag = r.imag;
       cout << "Operator= is calling " << endl;
       return *this;
    }
    ComplexNumber operator-(ComplexNumber const &r)
    {
       ComplexNumber com1;
       com1.real = this->real - r.real;
       com1.imag = this->imag - r.imag;
       return com1;
    }
    ComplexNumber operator*(int r)
    {
       ComplexNumber com1;
       com1.real = this->real * r;
       com1.imag = this->imag * r;
       return com1;
    }      
};

int main()
{
    ComplexNumber com1(3,4);
    ComplexNumber com2;
    
    com1.display();
    com2.display();

    ComplexNumber com3;

    com3 = com1 + com2;

    com3.display();
    
    com2 = com3 - com1*2;
    
    com2.display();

    return 0;
}

*/

////////////////////////////////////////////////////////////
/// Ex2

#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber
{
private:
    double real,imag;
public:

    ComplexNumber(double r=10, double i=10)
    {
       real = r;
       imag = i;
      // cout << "r,i constructor" << endl;
    }
    ~ComplexNumber()
    {
        //cout << "Destructor" << endl;
    }
    void display() const
    {
        cout << real << " + j" << imag << endl;
    }

    // operator overloading
    
    ComplexNumber operator+(ComplexNumber const &r)
    {
        ComplexNumber com1;
        com1.imag = this->imag + r.imag;
        com1.real = this->real + r.real;
        return com1;
    }
    ComplexNumber &operator=(ComplexNumber const &r)
    {
       this->real = r.real;
       this->imag = r.imag;
       cout << "Operator= is calling " << endl;
       return *this;
    }
    ComplexNumber operator-(ComplexNumber const &r)
    {
       ComplexNumber com1;
       com1.real = this->real - r.real;
       com1.imag = this->imag - r.imag;
       return com1;
    }
    ComplexNumber operator*(int r)
    {
       ComplexNumber com1;
       com1.real = this->real * r;
       com1.imag = this->imag * r;
       return com1;
    }      
    
    bool operator==(const ComplexNumber &r)
    {
       double absValueThis = sqrt(this->imag*this->imag + this->real*this->real);
       double absValueRef  = sqrt(r.imag*r.imag + r.real*r.real);
       if(absValueThis == absValueRef)
       {
        return true;
       }
       else
       {
        return false;
       }
    }

    bool operator>(const ComplexNumber &r)
    {
       double absValueThis = sqrt(this->imag*this->imag + this->real*this->real);
       double absValueRef  = sqrt(r.imag*r.imag + r.real*r.real);
       if(absValueThis > absValueRef)
       {
        return true;
       }
       else
       {
        return false;
       }
    }
    bool operator<(const ComplexNumber &r)
    {
       double absValueThis = sqrt(this->imag*this->imag + this->real*this->real);
       double absValueRef  = sqrt(r.imag*r.imag + r.real*r.real);
       if(absValueThis < absValueRef)
       {
        return true;
       }
       else
       {
        return false;
       }
    }

};

int main()
{
   ComplexNumber com1(3,4);
   ComplexNumber com2(5,3);
    
   // relational operator

   if(com1 == com2)
   {
     cout << "Com1 is equal to com2" << endl;
   }
   else
   { 
     cout << "Com1 is not equal to com2" << endl;
   }

   cout << (com1>com2) << endl;
   cout << (com1<com2) << endl;

   return 0;
}




// Complex Number
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////


// Complex Number
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
