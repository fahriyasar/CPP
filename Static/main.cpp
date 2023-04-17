/////////////////////////////////////////////////////////
/// Static ex1

/*

#include <iostream>

using namespace std;

class MyClass
{
private:

public:
   static int x;

};

int MyClass::x = 5;

int main()
{
    MyClass m1;
    //m1.x = 6;
    cout << m1.x << endl;


    return 0;
}*/

//////////////////////////////////////////////////////
// Static Doktor ex2

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Doctor
{
private:
   std::string mName;
   int mAge;
   static std::list<Doctor *> msAddrList;
public:
   std::string getName() const;
   int getAge() const;
   void display() const;
   Doctor(const std::string &nrame, int age);
   ~Doctor();
   Doctor(const Doctor &r);
};

list<Doctor *> Doctor::msAddrList; 

Doctor::Doctor(const std::string &name, int age): mName(name), mAge(age)
{
    Doctor::msAddrList.push_back(this);
}

std::string Doctor::getName() const
{
    return mName;
}

int Doctor::getAge() const
{
    return mAge;
}

void Doctor::display() const
{
   cout << "I am a doctor " << mName << " " << mAge << " years old" << endl;

   for(list<Doctor *>::const_iterator iter = msAddrList.begin(); iter != msAddrList.end();iter++)
   {
    if(*iter != this)
    {
        cout << (*iter)->getName() << endl;
    }
   }
}

Doctor::~Doctor()
{
    Doctor::msAddrList.remove(this);
}

Doctor::Doctor(const Doctor &r): mName(r.mName), mAge(r.mAge)
{
    Doctor::msAddrList.push_back(this);
}




int main()
{
    Doctor d1("Mehmet",29);
    Doctor d2("Baran", 24);
    Doctor d3("Alper",22);

    d1.display();


    return 0;
}