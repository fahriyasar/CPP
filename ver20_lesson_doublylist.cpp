///////////////////////////////////////////////////
///////////////////////////////////////////////////
//// Doubly Linked List

#include <iostream>
#include <cstdio>
#include <cstdlib>



using namespace std;

struct node
{
  int key;
  int data;


  struct node *next;
  struct node *prev;
};

// global variable definition

struct node *head = NULL;
struct node *last = NULL;

struct node *current = NULL;


// function decleration

// comprasion 
bool isEmpty();
int length();


void displayForward();
void displayBackward();  // previous address

void insertFirstElement(int key,int data);
void insertLastElement(int key,int data);


struct node *deleteFirstElement();
struct node *deleteLastElement();
struct node *deleteFunc(int key);

int main()
{

    for(int i=0;i<10;i++)
    {
      insertFirstElement(i , i*i );
    }

    printf("Displaying forward elements!\n");
    displayForward();

    //printf("Displaying backward elements!\n");
    //displayBackward();

    deleteFirstElement();
    displayForward();
    deleteLastElement();
    displayForward();

    deleteFunc(4);
    displayForward();


    return 0;
}



/////////////////////////////////////////////////////
///// Function Definition


// comprasion

bool isEmpty()
{
   return (head == NULL);
}

int length() 
{
    int len = 0;
    struct node *current;

    for(current=head;current!=NULL; current =current->next )
    {
        len++;
    }
    return len;
}




/// Display Function

void displayForward()
{
    struct node *ptr = head;
    
    printf("\n");

    while(ptr != NULL)
    {
       printf("(%d,%d)",ptr->key,ptr->data);
       ptr = ptr->next;
    }
     
    printf("\n");
}
void displayBackward()  // previous address
{
    struct node *ptr = last;

    printf("\n");

    while(ptr != NULL)
    { 
        printf("(%d,%d)",ptr->key,ptr->data);

        if(ptr != head)
        {
    
            ptr = ptr->prev;
        }
        else
        {
            break;
        }
    }       
     printf("\n");
}

void insertFirstElement(int key,int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));

    link->key = key;
    link->data = data;

    if(isEmpty())
    {
        last = link;
    }
    else
    {
        head->prev = link;
    }
    link->next = head;

    head = link;
}

void insertLastElement(int key,int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));

    link->key = key;
    link->data = data;

    if(isEmpty())
    {
        head = link;
    }
    else{
        last->next = link;    // last a5, link a6
        link->prev =last;     
    }
    last = link;
}



struct node *deleteFirstElement()
{
    struct node *templink = head;
    
    if(head->next == NULL)
    {
        last = NULL;
    }
    else{
        head->next->prev = NULL;    // HEAD A1, NEXT A2 , PREV A1
    }
    head = head->next;

    return templink;
}
struct node *deleteLastElement()
{
    struct node *templink = (struct node *)malloc(sizeof(struct node));
    
    if(head->next ==NULL)
    {
        head = NULL;
    }
    else{
        last->prev->next = NULL;    // LAST A2 PREV A1 NEXT A2
    }
    last = last->prev;
    return templink  ;
    
}
struct node *deleteFunc(int key)
{
    struct node *current = head;
    struct node *previous = NULL;

    while(current->key != key)
    {
        if(current->next == NULL)
        {
            return NULL;
        }
        else{
            previous = current;
            current = current->next;
        }
    }
    if(current == head)
    {
        head = head->next;
    }
    else
    {
        current->prev->next = current->next; // a1 a2 a3 , current a2 , prev a1 , next a3;
    }
    if(current == last)
    {
        last = current->prev;
    }
    else
    {
        current->next->prev = current->prev;  // a1 a2 a3 , current a2 , prev a1 , next a3;
    }

    return current;
}











//// Doubly Linked List
///////////////////////////////////////////////////
///////////////////////////////////////////////////
