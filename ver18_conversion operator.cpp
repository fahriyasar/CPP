///////////////////////////////////////////////
///////////////////////////////////////////////
/// type conversion operator


/*

C programming language

(int *)malloc(...)
int y = (int)x;

C++ 

static_cast
const_cast
reinterpret_cast
dynamic_cast    // C doesn't poss

static_cast<double>
const_cast<int *>(ciptr)
reinterpret_cast<char *>
reinterpret_cast<&MyData>

*/

//////////////////////////////////////////////////
/// Ex1

// Bu örneğin bir avantajı fakat classlarda kalıtımlarda kullandığımızda çok önemi var. Orda sınıfları dönüşüm edeceğiz.

/*

#include <iostream>

using namespace std;

int main()
{
    float x = 4.25;

    int y = x;   // C cast
    // int y = (int)y;     // some

    cout << "x : " << x <<endl;
    cout << "y : " << y <<endl;

    // C++ 

    int z = static_cast<int>(x);

    cout << "z : " << z << endl;



    return 0;
}

*/


/////////////////////////////////////////////
/// Ex2


#include <iostream>

using namespace std;

int main()
{
    const int x = 50;

   const int *y = &x;

   cout << "old value is " << *y << endl;

   int *z = const_cast<int *>(y);

   *z = 100;

   cout << "y value is " << *y << endl;
 


    return 0;
}




/// type conversion operator
///////////////////////////////////////////////
///////////////////////////////////////////////

