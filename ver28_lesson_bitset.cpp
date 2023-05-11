////////////////////////////////////////////////
///// Bitset

//////////////////////////////////////////////////
//// Ex1

/*

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    bitset<5> x;  // defining bits with the size of 5

    cout << x << endl;

    // x++ -> not overloaded!

    for(int i =0; i<5;i++)
         x[i] = 1;

    
    cout << "type : " << typeid(x).name() << " " << x << endl;
    cout << "type : " << typeid(x.to_ulong()).name() << " " << x .to_ulong()<< endl;
    cout << "type : " << typeid(x.to_string()).name() << " " << x.to_string() << endl;

    return 0;
}
*/

///////////////////////////////////////////////////////
/// Ex2

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    bitset<4> x;
    bitset<4> y;
    
    x |= 8;
    
    cout << x << endl;
    cout << x.to_ulong() << endl;

    y |= 4;

    x.operator|=(y);  // x |= y;   
    
    cout << x << endl;
    cout << x.to_ulong() << endl;

    return 0;
}

///// Bitset
////////////////////////////////////////////////
