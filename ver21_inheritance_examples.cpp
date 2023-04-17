////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
//// Inheritance Examples

////////////////////////////////////////////////////
//// ex1

/*

#include <iostream>

using namespace std;

class Shape
{
public:
  void setWidth(double w)
  {
    width = w;
  }
  void setHeight(double h)
  {
    height = h;
  }

protected:
   double width;
   double height;
};

class Rectangle : public Shape
{
public:
  void getArea()
  {
    double result = width* height;
    cout <<"Result of Rectangle area : " << result << endl;
  }
  
};

int main()
{
    Rectangle rec1;

    rec1.setHeight(5.5);   // Shape function
    rec1.setWidth(5.0);    // Shape function
    rec1.getArea();        // Rectangle function
 

    return 0;
}

*/

///////////////////////////////////////////////////////////
// ex2

/*

#include <iostream>

using namespace std;

class Shape
{
public:
  void setWidth(double w)
  {
    width = w;
  }
  void setHeight(double h)
  {
    height = h;
  }
  void setSquareDim(double s)
  {
    aSquare = s;
  }
  void setCircle(double r)
  {
    radius = r;
  }

protected:
   double width;
   double height;
   double aSquare;
   double radius;
   int choiceConst;
   Shape(double shapeWidth,double shapeHeight):width(shapeWidth),height(shapeHeight)
   {}
   Shape(double shapeSquare,int choice):aSquare(shapeSquare),choiceConst(choice)
   {}
   Shape(double shapeCircle): radius(shapeCircle)
   {}

   Shape()
   {
       cout << "shape default constructor!" << endl;
   }
   ~Shape()
   {
      cout << "shape default destructor!" << endl;
   }

};

class Rectangle : public Shape
{
private:
  void getArea()
  {
    double result = width* height;
    cout <<"Result of Rectangle area : " << result << endl;
  }
public:
  Rectangle(double width,double height): Shape(width,height)
  {
  } 

  void operator()()
  {
    getArea();
  }
  void operator()(int selection)
  {
    if(selection == 0)
    {
    getArea();
    }
    else
    {
      if(selection == 1)
      {
        cout << "Selection is 1, you cannot reach result!" << endl; 
      }
    }
  }
  void operator=(const Rectangle &r) // rec2 = rec1 ;    rec2.operator=(rec1);   this = rec2  , r = rec1
  {
    *(Shape *)this = r;     // or
    //this->height = r.height;
    //this->width = r.width;
  }
  Rectangle operator+(const Rectangle &r)
  {
    Rectangle recReturn(0.0,0.0);
    recReturn.width = this->width + r.width ;
    recReturn.height = this->height + r.height;
    return recReturn; 
  }
  
};

class Square : public Shape
{
private:
    void getArea()
    {
        double result = aSquare* aSquare;

        cout << "Result of Square area : " << result << endl;
    }
public:
  Square(double squ,int cho): Shape(squ,cho)
  {
  } 
  void operator()()
  {
    getArea();
  }

};

class Circle : public Shape
{
private:
  void getArea()
  {
    double result = 3.14*radius*radius;
    cout << "Result of Circle Area : " << result << endl;
  }
public:
  Circle(double shapeCircle) : Shape(shapeCircle)
  {
   
  } 
  void operator()()
  {
    getArea();
  }
};

*/

//// ex1

/*

int main()
{
    Rectangle rec1;

    rec1.setHeight(5.5);   // Shape function
    rec1.setWidth(5.0);    // Shape function
    rec1.getArea();        // Rectangle function
    
    Square squ1;

    squ1.setSquareDim(5);
    squ1.getArea();

    Circle circ;
    circ.setCircle(2);
    circ.getArea();

    return 0;
}

*/

/////////////////////////////////////////////////////////
///// Ex2

/*

int main()
{
    Rectangle rec1(5.5,4.0);

    rec1.getArea();

    Square sq1(5.0,0);

    sq1.getArea();

    Circle crc1(3.0);

    crc1.getArea();

    return 0;
}

*/

//////////////////////////////////////////////////////
/// Ex3
/*

int main()
{ 
  Rectangle rec1(4.0,5.0);

  rec1();
  Rectangle rec2(10.0,10.0);
  rec2();

  Rectangle rec3(0.0,0.0);

  rec3 = rec1 + rec2;
  rec3();
  return 0;
}

*/


//////////////////////////////////////////////////////////
///// ex4

 // dynamic type => virtual keyword
/*
#include <iostream>

using namespace std;

class Employee
 {
public:
   virtual void work()
   {
    cout << "Employee is working now!" << endl;
   }
 };

 class Manager : public Employee
 {
  public:
  virtual void work()
  {
    cout << "Manager is working!" << endl;  
  }
 };

 class Administration : public Manager
 {
  public:
  virtual void work()
  {
    cout << "Administration is working!" << endl;  
  }
 };

 void gfunc(Employee *ptr)
 { 
  ptr->work();  // dynamic type correction!
 }

int main()
{

  Manager m;
  
  gfunc(&m);
  
  Administration a;

  gfunc(&a);

  return 0;
}
*/


////////////////////////////////////////////////////////
//// Ex6

#include <iostream>
#include <string>

using namespace std;

class Shape     // abstract  / decleration
{
public:
  virtual string getName() const=0;
  double virtual getArea() const=0;
  double virtual getCircum() const=0;
  virtual void displayInfo() const=0;
};

class Circle : public Shape
{
double mRadius;
public:
  Circle()
  {
  }
  ~Circle()
  {
  }
  Circle(double mRad) : mRadius(mRad)
  {
  }
  virtual string getName() const
  {
    return "Circle" ;
  }

  virtual double getArea() const
  {
    return 3.1459 * mRadius * mRadius ;
  }

  virtual double getCircum() const
  {
    return 2* 3.1459 * mRadius;
  }
  virtual void displayInfo() const
  {
    cout << "Shape : " << getName() << endl;
  }


};

  Shape *createRandomShape()
  {
    return new Circle((double)(rand()%5));
  }
  void func(Shape *ptr)
  {
    ptr->displayInfo();
    cout << "Area : " << ptr->getArea() << endl;
    cout << "Circum : " << ptr->getCircum() << endl;
  }

int main()
{
  Shape *a[100];

  for(int k=0;k<100;k++)
  {
    a[k] = createRandomShape();
  }
  for(int k=0;k<100;k++)
  {
    func(a[k]);
  }
  return 0;
}

//// Inheritance Examples
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
