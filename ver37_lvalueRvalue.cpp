///////////////////////////////////////////
///////////////////////////////////////////
/// R value and L value




/*

lvalue -> a value stored in memory (heap stack) and addressable
rvalue -> a value that's not lvalue (non modifiable, temporary)

if you can take its address, it is probably lvalue.

The main advantage is to take a free space! (unnecessary copy, memory optimization)


*/

//////////////////////////////////////
// Ex1
/*
#include <iostream>

using namespace std;

int main()
{
  int i = 16;  // i : lvalue , 16 : rvalue

  int k = i + 55;  // k: lvalue , (i+55) : rvalue


  return 0;
}

*/

/////////////////////////////////////////////
// Ex2

#include <iostream>

using namespace std;

int main()
{
    int x = 5; // prosessing address on RAM location
    int &r1 = x;

    r1++;
    r1++;

    cout << "R : " << r1 << endl;

    // int &r2 = 7 ; // error because reference need to both its value and its adress

    const int &r3 = 9;

    cout << "R3 address : " << &r3 << endl; 
    cout << "R3 value : " << *(&r3) << endl;

    return 0;
}




/// R value and L value
///////////////////////////////////////////
///////////////////////////////////////////
