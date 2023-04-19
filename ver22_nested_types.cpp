/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
/// nested types


/*

for()
  for{

     }

there are there types

class MyClass 
   typedef int word;  (1)

   Class Inner    (2)
   {
    int mx,my,mz;
   }
   enum Color{White,Black}; (3)


*/


/////////////////////////////////////////////
// ex1

/*

#include <iostream>

using namespace std;

class MyClass
{


  public:
  MyClass()
  {
  cout << "MyClass constructor" << endl;
  }
  ~MyClass()
  {
  cout << "MyClass destructor" << endl;
  }

  typedef int Word;
   
  enum Color
  {
    White,
    Black
  };
  

  class Inner
  {
    public:
    int mx,my;
    Inner()
    {
      cout << "MyClass Inner constructor" << endl;
    }
    ~Inner()
    {
      cout << "MyClass Inner destructor" << endl;
    }
  };
  
  void func()
  {
    Inner n1;
  }
};

typedef MyClass::Inner InnerClassStructure;

int main()
{
  MyClass m1;
  m1.func();
  
  InnerClassStructure  c1;
   
      
  return 0;
}

*/

////////////////////////////////////////////
//// Ex2

#include <iostream>

using namespace std;

class Shape
{
private:
   

public:
  Shape()
  {
    cout <<"Shape Constructor" << endl;
  }
  ~Shape()
  {
    cout << "Shape Destructor" << endl;
  }
  class Rectangle
  {
  public:
   double width , height;
   void claculateArea()
   {
    double result = height * width;
    cout << "Area of rectangle : " << result << endl;
   }
  };
  class Circle
  {

  };
  class Square
  {

  };

  // type definition

  typedef Shape::Rectangle Rectdef;

  void ObtainRectArea(double w, double h)
  {
    Rectangle r1;
    r1.width = w;
    r1.height = h;
    r1.claculateArea();
  }

};



int main()
{
  
  Shape s1;

  s1.ObtainRectArea(5.0,4.0);

  Shape::Rectangle rec1;

  rec1.height = 5.0;
  rec1.width = 5.0;
  
  rec1.claculateArea();

  Shape::Rectdef rec2;
  rec2.height = 5;
  rec2.width =4.5;
  rec2.claculateArea();
  return 0;
}




/// nested types
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
