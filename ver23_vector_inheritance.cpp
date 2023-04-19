//////////////////////////////////////////////
//////////////////////////////////////////////
/// inheritance in vector class


#include <iostream>
#include <vector>

using namespace std;

class Base
{
public:
protected:
 Base()
 { 
   cout << "Base constructor" << endl;
 }
 ~Base()
 {
    cout << "Base Destructor" << endl;
 }
 Base(const Base &r)
 {
    cout << "Base copy constructor" << endl;
 }
};
class Der: public Base
{
public:
  Der()
  {
    cout << "Der constructor" << endl;
  }
  ~Der()
  {
    cout << "Der destructor" << endl;
  }
  Der(const Der &r)
  {
    cout << "Der copy constructor" <<endl;
  }
};


int main()
{
    //vector<Der> d;

    // Der d1;

    // d.push_back(d1);   // copy constructor

    //d.push_back(Der()); // copy constructor
 
    //vector<Base> d;  object cannot be created even in vector class!

    // Base *ptr; // it could be used!

    //Base b1; // syntax error
    
    vector<Base *> c1;
    
    
    return 0;
}






/// inheritance in vector class
//////////////////////////////////////////////
//////////////////////////////////////////////
