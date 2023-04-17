////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
/// Operator overloading in C++

// Fonksiyonları kullanarak uyarıları verebiliyoruz. Örnek height değerine negatif değer atayamassınız.
// Yada constructor öyle bir yazarız ki yine  öyle bir değer gelemez.
// Bir classla başka bir classı asla karşılaştıramassınız. Fakat operator overloading yaparak istenilen her şeyi yapabilirsiniz.

//////////////////////////////////////////////////////////////
/// ex1

/*
#include <iostream>

using namespace std;

class Box
{
private:
  double length;
  double width;
  double height;

public:
  Box()
  {
    cout << "Box Constructor" << endl;
  }
  Box(double l, double w, double h )
  {
    length = l;
    width = w;
    height = h;
    cout << "Box Constructor overloading " << endl;
    cout << "Box Volume = " << (l*w*h) << endl;

  }
  ~Box()
  {
    cout << "Box Destroctor" << endl;
  }
  double getVolume()
  {
     return length*width*height;
  }

  void setlength(double len)
  {
    if(len<0)
    {
         cout << "len must be greater than zero!" << endl;
    }
    else
    {
        length = len;
    }
    
  }
  void setwidth(double w)
  {
    if(w < 0)
    {
        cout << "weight must be greater than zero!" << endl;
    }
    else{
       width = w;
    }
    
  }
  void setheight(double h)

  {
    if(h < 0)
    {
        cout << "height must be greater than zero!" << endl;
    }
    else{
       height = h;
    }
    
  }
  void display() const
  {
    cout << "Length/width/height " << endl;
    cout << " " << length << " " << width << " " << height << endl;
  }
  /////////////////////////////////////////////////
  /// Operators

  Box &operator=(const Box &r)
  {
    // box1(this) = box2(r);
    this->length = r.length;
    this->height = r.height;
    this->width = r.width;
    cout << "Operating is calling " << endl;
    
    return *this;   // return this diyemeyiz Çünkü bu adress değeri. Biz Box referans donduğumuz *this dememiz gerekiyor.
  }

  Box operator+(const Box &r)   // Box& dondurunce box1 ve box3 eşitleniyor. Bu istediğimiz bir şey değil.Bu yüzden kodu değiştiriyoruz.
  {
    Box BoxInt;
    BoxInt.length = this->length + r.length;
    BoxInt.width = this->width + r.width;
    BoxInt.height = this->height + r.height;
    return BoxInt;
  }

  bool operator==(const Box &r)
  { 
    double thisVolume = (this->length * this->height * this->width);
    double rVolume = (r.length * r.height * r.width);
    if(thisVolume == rVolume)
    {
      cout << "This volume is equal to reference volume! " << endl;
      return true;
    }
    else
    {
      cout << "This volume is not equal to reference volume! " << endl;
      return false;
    }
     
  }

  /// Operators
  /////////////////////////////////////////////////

};

int main()
{
    Box box1;
    Box box2(1.2,2.2,3);
    cout << "Box2 volume = " << box2.getVolume() << endl;
    box2.setlength(10);
    box2.setwidth(5);
    box2.setheight(10);
    cout << "Box2 volume = " << box2.getVolume() << endl;

    box1 = box2;

    cout << "Box1 volume = " << box1.getVolume() << endl;

    Box box3;

    box3 = box1 + box2;
    cout << "Box3 volume = " << box3.getVolume() << endl;
    box1.display();
    box2.display();
    box3.display();

    box1 = box3 + box2;
    cout << "Box3 volume = " << box3.getVolume() << endl;
    box1.display();
    box2.display();
    box3.display();

    return 0;
}

*/

////////////////////////////////////////////////////////////
// ex2
#include <iostream>

using namespace std;

class Box
{
private:
  double length;
  double width;
  double height;

public:
  Box()
  {
    cout << "Box Constructor" << endl;
  }
  Box(double l, double w, double h )
  {
    length = l;
    width = w;
    height = h;
    cout << "Box Constructor overloading " << endl;
    cout << "Box Volume = " << (l*w*h) << endl;

  }
  ~Box()
  {
    cout << "Box Destroctor" << endl;
  }
  double getVolume()
  {
     return length*width*height;
  }

  void setlength(double len)
  {
    if(len<0)
    {
         cout << "len must be greater than zero!" << endl;
    }
    else
    {
        length = len;
    }
    
  }
  void setwidth(double w)
  {
    if(w < 0)
    {
        cout << "weight must be greater than zero!" << endl;
    }
    else{
       width = w;
    }
    
  }
  void setheight(double h)

  {
    if(h < 0)
    {
        cout << "height must be greater than zero!" << endl;
    }
    else{
       height = h;
    }
    
  }
  void display() const
  {
    cout << "Length/width/height " << endl;
    cout << " " << length << " " << width << " " << height << endl;
  }
  /////////////////////////////////////////////////
  /// Operators

  Box &operator=(const Box &r)
  {
    // box1(this) = box2(r);
    this->length = r.length;
    this->height = r.height;
    this->width = r.width;
    cout << "Operating is calling " << endl;
    
    return *this;   // return this diyemeyiz Çünkü bu adress değeri. Biz Box referans donduğumuz *this dememiz gerekiyor.
  }

  Box operator+(const Box &r)   // Box& dondurunce box1 ve box3 eşitleniyor. Bu istediğimiz bir şey değil.Bu yüzden kodu değiştiriyoruz.
  {
    Box BoxInt;
    BoxInt.length = this->length + r.length;
    BoxInt.width = this->width + r.width;
    BoxInt.height = this->height + r.height;
    return BoxInt;
  }

  bool operator==(const Box &r)
  { 
    double thisVolume = (this->length * this->height * this->width);
    double rVolume = (r.length * r.height * r.width);
    if(thisVolume == rVolume)
    {
      cout << "This volume is equal to reference volume! " << endl;
      return true;
    }
    else
    {
      cout << "This volume is not equal to reference volume! " << endl;
      return false;
    }
     
  }
  bool operator<(const Box &r)
  { 
    double thisVolume = (this->length * this->height * this->width);
    double rVolume = (r.length * r.height * r.width);
    if(thisVolume < rVolume)
    {
      cout << "This volume is smaller to reference volume! " << endl;
      return true;
    }
    else
    {
      cout << "This volume is greater to reference volume! " << endl;
      return false;
    }
     
  }
  bool operator>(const Box &r)
  { 
    double thisVolume = (this->length * this->height * this->width);
    double rVolume = (r.length * r.height * r.width);
    if(thisVolume > rVolume)
    {
      cout << "This volume is greater to reference volume! " << endl;
      return true;
    }
    else
    {
      cout << "This volume is smaller to reference volume! " << endl;
      return false;
    }
  }


  
  /// Operators
  /////////////////////////////////////////////////

};

int main()
{
    Box box1(4,3,2);
    Box box2(3,3,2);

    // box2 = box1;
    
    if(box1 == box2)    // box1.operator==(box2)
    {
        cout << "Box1 is equal to Box2" << endl;
    }
    else
    {
        cout << "Box1 is not equal to Box2" << endl;
    }
    
    if(box1 > box2)    // box1.operator==(box2)
    {
        cout << "Box1 is greater to Box2" << endl;
    }
    else
    {
        cout << "Box1 is smaller to Box2" << endl;
    }


    return 0;
}

/// Operator overloading in C++
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
