//////////////////////////////////////////////////
//////////////////////////////////////////////////
///  MOVE SEMANTIC

/*

* the rValue references and move semantic allows us to avoid unecessary copies
when working with temporary objects!

* the main usage of rValue references is to create a move contructor and
move assigment operator!

*main point is to avoid unnecessary copies when working temporary objects!

thread t(..);
thread t2 = move(t);

t2 -> is the temporary object

*/

//////////////////////////////////////////
/// Ex1

/*

#include <iostream>

using namespace std;

class A
{
public:
   int i;
   A(){cout << "Default Constructor!"<<endl;}
   ~A(){cout << "Destructor!"<<endl;}
   A(const A &other){cout << "Copy constructor!"<<endl;}
   A &operator=(const A &other){this->i = other.i;}
   
   /////////////////////////////////////////////////
   // move objects/methods

   A(A &&other){cout << "move constructor" << endl;}     // rValue

   void writeInteger(){cout << "i : " << this->i << endl;}
   
};

int main()
{
     A a;
     A b = a;
     
     a.i=5;
     b=a;
     a.writeInteger();
     b.writeInteger();
   


    return 0;
}

*/

//////////////////////////////////////////////////
/// Ex2

/*

#include <iostream>

using namespace std;

class A
{
public:
   int i;
   A(){cout << "Default Constructor!"<<endl;}
   ~A(){cout << "Destructor!"<<endl;}
   A(const A &other){cout << "Copy constructor!"<<endl;}
   A &operator=(const A &other){this->i = other.i;}
   
   /////////////////////////////////////////////////
   // move objects/methods

   A(A &&other){this->i = other.i;cout << "move constructor" << endl;}     // rValue

   void writeInteger(){cout << "i : " << this->i << endl;}
   
};

int main()
{
     A a;
     a.i=5;

     A b = move(a) ;
     a.writeInteger();
     b.writeInteger();
   


    return 0;
}
*/


//////////////////////////////////////////////
//// Ex3


#include <iostream>

using namespace std;

class A
{
private:

public:
     string s;
     
     A() : s("berkem")
     {
      cout << "A default constructor" << endl;
     }
     A(const A &other) : s(other.s)
     {
      cout << "A copy constructur" << endl;
     }
     ~A()
     {
      cout << "A destructor" << endl;
     }
     A(A &&other) : s(move(other.s))
     {
      cout << "A move constructor" <<endl;
     }
};


class B : public A
{
private:

public:
    B()
    {
      cout << "B default constructor" << endl;
    }
    ~B()
    {
      cout << "B destructor" << endl;
    }
    B(const B &other)
    {
      cout << "B copy constructor" << endl;
    }

    //////////////////////////////////////////////
    /// Move operations

    B(B &&other)
    {
       cout << "B move constructor" << endl;
    }
};


int main()
{
   B b;
   B b1 = b;

   return 0;
}





///  MOVE SEMANTIC
//////////////////////////////////////////////////
//////////////////////////////////////////////////
