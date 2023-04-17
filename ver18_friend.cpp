////////////////////////////////////////////
////////////////////////////////////////////
// Friend

/*

friend -> shared globally function


(1) global function can be utilized for friend member function!
(2) class A function -> class B function as friend
(3) class A -> class B as friend


*/

///////////////////////////////////////////////
/// ex1 

//  Not friend olan function heryerden görülebilir ve bu fonksiyonla private üyelere ulaşılabilir.

/*

#include <iostream>

using namespace std;

class MyClass
{
  private:  
  int a;
  public:
  friend void func(int);

};

void func(int val)
{
    MyClass m1;
    m1.a = 5;
    cout << "Valu : " << val << endl;
}


int main()
{
    MyClass m1;
    func(4);


    return 0;
}

*/
/////////////////////////////////////////////////////
/// ex2

/*

#include <iostream>

using namespace std;

// Bir classın private üyelerine friend fonksiyonlarıyla ulaşabiliriz.


class Box
{
private:
    double width;
public:
   friend void printWidth(Box box);
   void setWidth(double wid)
   {
    width = wid;
   }
};

void printWidth(Box box)
{
   cout << "Box width = " << box.width << endl;
}


int main()
{
    Box box;
    box.setWidth(5);
    printWidth(box);

    return 0;
}

*/
// Friend
////////////////////////////////////////////
////////////////////////////////////////////
