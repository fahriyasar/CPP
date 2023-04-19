///////////////////////////////////////
///////////////////////////////////////
/// Vector structure

/*

vector -> linked list

its functions, its structure 

STL (standard template library) -> no example

*/


////////////////////////////////////////////
/// Ex1

/*

#include <iostream>
#include <vector>

using namespace std;




int main()
{
    vector<int> v1;

    for(int i=0;i<=5;i++)
    {
        v1.push_back(i*i);  // Değeri içeriğe bastı
    }

    for(auto i = v1.begin();i!=v1.end();i++)    // auto verilerin karşıdan gelen veriye göre kendini düzenleyebiliyor.
    {
        cout << *i << " " ;
    }
    cout << endl;
    for(auto i = v1.end();i!=v1.begin();)    // auto verilerin karşıdan gelen veriye göre kendini düzenleyebiliyor.
    {
        cout << *(--i) << " " ;
    }
    cout << endl;

    for(auto i = v1.rbegin(); i != v1.rend(); ++i)
    {
        cout << *i << " " ;
    }
    cout << endl;

    for(auto i = v1.cbegin();i!=v1.cend();i++)   // constatnt değer oluyor Sadece okuyabiliyoruz. Değiştiremiiyoruz.
    {
        cout << *i << " " ;
    }
    cout << endl;

    for(auto i = v1.crbegin(); i != v1.crend(); ++i)
    {
        cout << *i << " " ;
    }
    cout << endl;
    return 0;
}

*/

///////////////////////////////////////
/// Ex2

/*

#include <iostream>
#include <vector>

using namespace std;

void AddListVariable(vector<int> &g1)
{
    for(int i=0;i<=5;i++)
    {
        g1.push_back(i*i);  // Değeri içeriğe bastı
    }
}

void displayForward(vector<int> &g1)
{
    for(auto i = g1.begin();i!=g1.end();i++)    
    {
        cout << *i << " " ;
    }
    cout << endl;    
}

void displayBackward(vector<int> &g1)
{
    for(auto i = g1.rbegin(); i != g1.rend(); ++i)
    {
        cout << *i << " " ;
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    AddListVariable(v1);
    displayForward(v1);
    displayBackward(v1);


}
*/

//////////////////////////////////////
// Ex3 

/*


#include <iostream>
#include <vector>

using namespace std;

void AddListVariable(vector<int> &g1)
{
    for(int i=0;i<=100;i++)
    {
        g1.push_back(i*i);  // Değeri içeriğe bastı
    }
}

void displayForward(vector<int> &g1)
{
    for(auto i = g1.begin();i!=g1.end();i++)    
    {
        cout << *i << " " ;
    }
    cout << endl;    
}

void InfoVector(vector<int> &g1)
{
    cout << "Size of Vector : " << g1.size() << endl;
    cout << "Capacity of Vector : " << g1.capacity() << endl;
    cout << "Max_size of Vector : " << g1.max_size() << endl; 
}



int main()
{
    vector<int> v1;
    AddListVariable(v1);
    displayForward(v1);
    InfoVector(v1);

    v1.resize(5);
    displayForward(v1);
    InfoVector(v1);

    if (v1.empty()== true)
    {
        cout << "V1 vector is empty " << endl;
    }
    else
    {
       cout << "V1 vector is not emty " << endl;
    }
    
    v1.shrink_to_fit();   // capacity azaltıyor.  size = capacity!

    InfoVector(v1);

}

*/



///////////////////////////////////////////
//// ex5
/*

#include <iostream>
#include <vector>

using namespace std;

int main()
{ 
    vector<int> v1;

    for(int i=0;i<5;i++)
    {
        v1.push_back(i);
    }

    for(auto i=v1.begin();i!=v1.end();i++)
    {
        cout << *i <<" " ;
    }
    cout << endl;

    cout << "Second element of V1 : " << v1.at(1) << endl;
    cout << "Second element of V1 : " << v1[1] << endl;

    cout << "First element of V1 : " << v1.front() << endl;
    cout << "End element of V1 : " << v1.back() << endl;


    return 0;
}

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
    string mName;
    int mIdNo;
public:
   static int numberofStudents;
   static double sumPoint;
   static double numberofAverage;
   Student(string name,int idNo): mName(name),mIdNo(idNo)
   {
    numberofStudents++;
   }
   Student(string name,int idNo,double point): mName(name),mIdNo(idNo)
   {
    numberofStudents++;
    sumPoint = sumPoint + point;
    numberofAverage = sumPoint / numberofStudents;
   }
   
   ~Student()
   {

   }
   void display() const
   {
    cout << "Name : " << mName << endl;
    cout << "Id No : " << mIdNo << endl;
   }
   static void InfoAverage()
   {
    cout << "Average of Students : " << numberofAverage << endl;
   }
};

int Student::numberofStudents = 0;
double Student::sumPoint = 0.0;
double Student::numberofAverage = 0.0;

int main()
{
    vector<Student> stuList;

    stuList.push_back(Student("Sule",1,85));
    stuList.push_back(Student("Ali",2,85));
    stuList.push_back(Student("Fahri",3,85));
    stuList.push_back(Student("Şinasi",4,80));
    stuList.push_back(Student("Beyza",5,80));
    
    for(int i=0;i<stuList.size();i++)
    {
        // stuList[i].display(); // or
        stuList.operator[](i).display();
    }

    Student::InfoAverage();


    return 0;
}

/// Vector structure
///////////////////////////////////////
///////////////////////////////////////


