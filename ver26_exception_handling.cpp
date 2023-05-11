/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
///// Exception handling


/*

what happens if an error occurs in real time/run time,
what would I do?

compile time error -> syntax error

run time error     -> 
1.example
int a = 1;
int b = 0;

int c = a/b;   // logical rule must be obeyed!

2.example

int a[5];

a[10] -> the program does not reach *(a+10), (0xFE+10*4)

EXCEPTİON HANDLİNG => RUN TİME ERRORS CAN BE CATCHED!

exception class -> control to the run time errors! (C++)

In C => if ( b == 0)
{
    printf("you cannot give zero to the b variable, because ... ")
}

Syntax structure... 

try
{
    A a = new A;
    int a;
    int b;

    int c = a/b;
}
catch(int x)
{
    cout << .... << endl;
    delete a;
}


*/

////////////////////////////////////////////
/// Ex1

/*

#include <iostream>

using namespace std;

class Ex
{
};

void f1()
{
    cout << "f1 is being started!" << endl;
    throw new Ex;
    cout << "f1 have been done!" << endl;
}

int main()
{
    cout << "main is being started!" << endl;

    try
    {
        f1();
        cout << "main try block!" << endl;
    }
    catch(int)
    {
        cout << "error : int" << endl;
    }
    catch(double)
    {
        cout << "error : double " << endl;
    }
    catch(...)
    {
        cout << " error : default catch " << endl;
    }
    
   cout << "main is being started!" << endl;

    return 0;
}*/

////////////////////////////////////////////////////////
//// Ex2
/*

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec(10);

    try
    {
      ivec.at(20);
    }
    catch(exception &r)
    {
        cout << "Error in vector operation : " << r.what() << endl;
    }

    return 0;
}
*/

///////////////////////////////////////////
/// Ex3


/*

#include <iostream>

using namespace std;

class Ex: public exception
{
    int mVal;
public:
    Ex(int val): mVal(val)
    {}
    int get() const
    {
        return mVal;
    }
    void set(int val)
    {
        mVal = val;
    }
};

void f2()
{
    try
    {
        throw Ex(10);
    }
    catch(Ex &r)
    {
        cout << "Error in Ex class : " << r.what() << " " << r.get() << endl;
        r.set(r.get()+1);
        cout << r.get() << endl;
        throw r;            // rethrow
    }
    catch(...)
    {
        cout << "default catch " << endl;
    }
    
}

int main()
{
    f2();
    return 0;
}
*/

////////////////////////////////////////////////////////////
//// Ex4

/*

#include <iostream>

using namespace std;

double division(int a,int b)
{
    if(b==0)
    {
        throw "Division by zero condition!";
    }
    return (a/b);
}


int main()
{
    int a = 1;
    int b = 0;
    int c;
     try
     {
        division(a,b);    //program is stopped!
     }
     catch(const char *msg)
     {
        cout << "default exception : " << msg <<  endl;
     }
    return 0;
}

*/


////////////////////////////////////////////////////////
/// Ex5

#include <iostream>

using namespace std;

int main()
{
    try
    {
        try
        {
        throw 20;
        }
        catch(int n)
        {
          cout << "internal throw error" << endl;
          throw;
        }

    }
    catch(...)
    {
        cout << "Default exception!" << endl;
    }

    cout << "main is ended" << endl;
    


    return 0;
}




///////  Exception handling
///////////////////////////////////////////////////////
///////////////////////////////////////////////////////