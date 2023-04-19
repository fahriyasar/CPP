/////////////////////////////////////////
/////////////////////////////////////////
/// vector class linked list

#include <iostream>
#include <vector>

using namespace std;

class List
{
private:
    class Node
    {
    private:
        int mVal;
        int mKey;
    public:
       friend class List;
       Node *pNext;
       Node(int val, int key);
       friend ostream &operator<<(ostream &os, const Node &r)
       {
        return os << r.mVal;
       }
    };
    
    Node *mpStart;
    Node *mpEndNull;
    Node *mpEndFinal;
    size_t mSize;
 


public:
   List();
   void pushFront(int val,int key);
   size_t getSize() const;
   void display() const;

   /////////////////////////////////////
   //// Standart vector functions
   
   Node *begin();
   Node *cbegin() const;

   Node *end();
   Node *cend() const;

   Node *endlast();
   Node *cendlast() const;

   Node &at(int index);
   Node &front();
   Node &back();

   // Operating overloading

   int operator[](int i);

   //// Standart vector functions
   /////////////////////////////////////

};

////////////////////////////////////////
// Main code


int main()
{
    List myList;

    myList.pushFront(1,1000);
    myList.pushFront(2,2000);
    myList.pushFront(3,3000);
    myList.pushFront(4,4000);

    myList.display();

    cout << "Size : " << myList.getSize()<< endl;

    cout << "Second value of List : " << myList[1] << endl;

    cout << "MyList[2] : " << myList.at(1) << endl; 

    return 0;
}


// Main code
////////////////////////////////////////


/////////////////////////////////////////
// source code - function definition/implementation

List::Node::Node(int val,int key) : mVal(val), mKey(key),pNext(0)
{
}

List::List() : mpStart(0),mpEndFinal(0),mpEndNull(0),mSize(0)
{
}

void List::pushFront(int val, int key)
{
    Node *pNewNode = new Node(val,key);

    if(mpStart == NULL)
    {
        mpEndNull = pNewNode->pNext;
        mpEndFinal = pNewNode;
    }
    pNewNode->pNext =mpStart;
    mpStart = pNewNode;

    mSize++;
}

void List::display() const
{
   Node *p = mpStart;

   while (p != mpEndNull)
   {
    cout << p->mKey << " " << p->mVal ;
    cout << endl;
    p = p->pNext ;
   }
   cout << endl;
}

size_t List::getSize() const
{
    return mSize;
}

List::Node *List::begin()
{
   return mpStart;
}

List::Node *List::cbegin() const
{
    return mpStart;
}

List::Node *List::end()
{
    return mpEndNull;
}

List::Node *List::cend() const
{
    return mpEndNull;
}

List::Node *List::endlast()
{
    return mpEndFinal;
}

List::Node *List::cendlast() const
{
    return mpEndFinal;
}

int List::operator[](int index)
{
    Node *p = mpStart;

    int i=0;

    while(p != mpEndNull && index != i)
    {
        i++;
        p = p->pNext;
    }

    return (p->mVal);
}

List::Node &List::at(int index)
{
    Node *p = mpStart;
    int i=0;

    while(p != mpEndNull && index != i)
    {
        i++;
        p= p->pNext;
    }
    return *p;
}

List::Node &List::front()
{
    return *mpStart;
}

List::Node &List::back()
{
    return *mpEndFinal;
}

/// vector class linked list
/////////////////////////////////////////
/////////////////////////////////////////
