///////////////////////////////////////////
///////////////////////////////////////////
// run time type information



/*

int main()
{
    int a; // integer -> compile time type
}

malloc, calloc, new, inheritance dynamic type (base-derived)

what is type of object in real time /run time application

There are two kinds of information

- typeid  -> operator   (outside information)
- dynamic_cast -> operator  (inheritance)


*/

////////////////////////////////////////////
// Ex1

/*

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    int a ;
    int b;
    char c;
    
    // Dışardan gelen ve türünü bilmediğimiz değişkenlerin türünü öğrenmek için kullanılabilir.

    const type_info &ti1 = typeid(a);
    const type_info &ti2 = typeid(b); 
    const type_info &ti3 = typeid(c);

    if(ti1==ti2)
    {
        cout << "Ti1 is equal to ti2" << endl;
    }

    
    return 0;
}

*/

////////////////////////////////////////////////
/// Ex2

/*

#include <iostream>
#include <typeinfo>

using namespace std;

int main()
{
    int **a ;
    int b;
    char *c;
    
    // Dışardan gelen ve türünü bilmediğimiz değişkenlerin türünü öğrenmek için kullanılabilir.

    const type_info &ti1 = typeid(a);
    const type_info &ti2 = typeid(b); 
    const type_info &ti3 = typeid(c);

    cout << "Type of ti1 : " << ti1.name() << endl;
    cout << "Type of ti2 : " << ti2.name() << endl;
    cout << "Type of ti3 : " << ti3.name() << endl;
    
    return 0;
}

*/



/////////////////////////////////////////////////////
/// Ex3


//  dynamic_cast -> intheritance, type is defined in run time


#include <iostream>

using namespace std;

class Car
{
public:
 virtual void start()
 {

 }
};

class Audi: public Car
{
public:
};


int main()
{
    Car *c = new Audi;

    Audi *a = dynamic_cast<Audi *>(c);

    if(a != NULL)
    {
        cout << "it works" << endl;
    }
    else
    {
        cout << "cannot convert Car* to Audi*" << endl; 
    }


    return 0;
}

// run time type information 
///////////////////////////////////////////
///////////////////////////////////////////
