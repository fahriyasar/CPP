///////////////////////////////////////
///////////////////////////////////////
/// class Linked List


#include <iostream>

using namespace std;

class List
{
private:
   class Node
   {
   private:
   
    int mVal;
    Node *pNext;
   
   public:

    friend class List;
    Node(int val);     // no default constructor
   };
   
   Node *mpStart;
   size_t mSize;

public:
    List();    // default constructor
    void pushFront(int val);
    size_t getSize() const;
    void display() const;

};


int main()
{
    List myList;

    myList.pushFront(5);
    myList.pushFront(1);
    myList.pushFront(0);
    myList.pushFront(2);
    myList.pushFront(3);




    for(int i=0; i<10 ; i++)
    {
      myList.pushFront(i*i);
    }

    myList.display();
    cout << "Size of MyList : " <<  myList.getSize() << endl;;
    

    return 0;
}


List::Node::Node(int val) : mVal(val), pNext(0)
{
}
List::List() : mpStart(0),mSize(0)
{
}


void List::pushFront(int val)
{
    Node *pNewNode = new Node(val);
    pNewNode->pNext = mpStart;
    mpStart = pNewNode;
    mSize++;
}

void List::display() const
{
    Node *p = mpStart;

    while(p != 0)
    {
        cout << p->mVal << " ";
        p = p->pNext;
    }
    cout << endl;

}

size_t List::getSize() const
{
   return mSize;
}



/// class Linked List
///////////////////////////////////////
///////////////////////////////////////
