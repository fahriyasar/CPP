////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
/// Linked list



/*

linked list -> baglı liste

int a[10];

Memory   dynamic memory (malloc)
a[0]     -> 0x00
a[1]     -> 0x04
a[2]     -> 0x08
...
...
a[9]     -> 0x36


Restrictions
- limited memory
- long term records


How to do this ??

C/C++

C -> pointer
C++ -> list, set, map, class vector!


int a;

aptr = &a

int b;

bptr = &b;

STRUCTURE design

struct Node
{
  int a;
  int b;
  double c;

  int *aPtr;
  int *bPtr;
};

Linked List DESİGN

struct Node 
{
    struct Node a;
    struct Node *next;
}

struct Node a;
struct Node b;


a.data = 100;
a.next = &b;

Formal Structure for LL

struct Node
{
    double data;
    int key;

    struct Node *next;
}


a1.data;
&a2 = a1.next;
&a3 = a2.next;



*/

///////////////////////////////////////////////////////
/// Ex1

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdbool>


using namespace std;

struct node
{
   int data;
   int key;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;


// display list
void printList()
{
    struct node *ptr = head;

    //loop fot ptr iteration
    while(ptr != NULL)
    {
        printf("(%d,%d)\n",ptr->key,ptr->data);
        ptr = ptr->next;
    }
}

//insert
void insertElement(int key,int data)
{
   // create a link/element
   struct node *link = (struct node *)malloc(sizeof(struct node)); // dynamic memory
   
   link->data = data;
   link->key = key;

   // point it to old node
   link->next = head;   // null if it is the first element

   head = link;         // it is link if it is the first element
}

//delete element

/*
a3 -> head
a2 -> head->next
a1 -> head->next->next

*/

struct node *deleteElement()
{
    struct node *templink = head; //a3

    head = head->next;            //a2
    
    return templink;              //a3
}

// standard comparison tool
bool isEmpty()
{
    if (head==NULL)
    {
        printf("Linked list is empty\n");
        return true;
    }
    else{
        printf("Linked list is not empty\n");
        return false;
    }
}
int length()
{ 
    int len=0;
    struct node *temp;

    for(temp = head;temp != NULL; temp = temp->next)
    {
         len++;
    }
    return len;
}

// finding an element
struct node *find(int key)
{
    // local variable : current
   struct node *current = head;

   if (head==NULL)
   {
    return NULL;
   } 

  while(current->key != key)   // control for whether key is found or not!
  {
    if(current->next == NULL)
    {
        return NULL;
    }
    else
    {
       current = current->next;
    }
  }
 
  printf ( "Key : %d, Address : %p, Data : %d\n" ,current->key,current,current->data);

  return current;    // key matched!, return the current link
}

//delete a link with a given key
struct node *deleteFunc(int key)
{
    struct node *current = head;
    struct node *previous = NULL;

    if(head == NULL)
    {
        return NULL;
    }
    while(current->key != key)
    {
        if(current->next == NULL)
        { 
            return NULL;
        }
        else
        {
            previous = current;   // previous stores link
            current = current->next;  // link to be deleted
        }
    }

    if(current == head)
    {
        head = head->next;
    }
    else
    {
        previous->next = current->next;   // bypass deleted link
    }
   
   printf ( "Key : %d, Address : %p, Data : %d\n" ,current->key,current,current->data);
   
   return current;


}

//////  Example 1

/*

int main()
{
    insertElement(0,10);
    insertElement(1,20);

    printList();

    printf("Size of LL : %d\n",length());

    deleteElement();

    isEmpty();
    printList();
    printf("Size of LL : %d\n",length());


    return 0;
}

*/

//////  Example 2

int main()
{
     
    for(int i=0;i<10;i++)
    {
        insertElement(i,i*i-5);
    }

    

    find(5);

    deleteFunc(4);

    printList();
    return 0;
}





//// Linked list
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////