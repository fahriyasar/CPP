/////////////////////////////////////////////////
/////////////////////////////////////////////////
/// Linked list -> system Dynamics -> time response of system


/*

dt -> 0.001 

linked list -> x[i+1](next), x[i](prev)


*/



/////////////////////////////////////////////////////
//// Ex1

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


typedef struct systemParameters
{
   double dt;
   double t_initial;
   double t_final;
   double x0;
   double firstParam;
   double secondParam;

   // xdot = a(firstParam)*x + b(secondParam)*u;
   // x[i+1] = x[i] + dt*(a(firstParam)*x + b(secondParam)*u)

}SYSTEM_PARAMETERS;

typedef struct node
{
    double data;
    int key;

    struct node *next;
}LL_SYS_PARAM;    // linked link system paramaters

typedef LL_SYS_PARAM *LL_SYS_PARAM_PTR;     // Türü struct node * oluyor.

//solver design

void forwardDifferenceSolver(SYSTEM_PARAMETERS sys);
void backwardDifferenceSolver(SYSTEM_PARAMETERS sys);


// linked list design

// Display elements
void printList();

// add element
void insertElement(int key, double data);

// erase element
LL_SYS_PARAM_PTR deleteElement(); // Geri dönüş address cinsinden

//comparision section
bool isEmpty();
int length();

//finding a specific element
LL_SYS_PARAM_PTR find(int key);

// delete a link
LL_SYS_PARAM_PTR deleteFunc(int key);




int main()
{ 
    SYSTEM_PARAMETERS sys1;
    
    sys1.dt = 0.01;
    sys1.firstParam = -1;
    sys1.secondParam = 1;
    sys1.t_final = 5.0;
    sys1.t_initial = 0.0;
    sys1.x0 = 0.0;

    backwardDifferenceSolver(sys1);

    return 0;
}

///////////////////////////////////////////////
//// Definition of Functions

LL_SYS_PARAM_PTR head = NULL;
LL_SYS_PARAM_PTR current = NULL;    // global current

// Display elements

void printList()
{
  LL_SYS_PARAM_PTR ptr = head;   
  
  printf("\n");
  while(ptr != NULL)
  {
     printf("(%d,%lf)\n",ptr->key,ptr->data);
     ptr = ptr->next;                   // Linked link sıralı olduğundan emin olmadığımızdan ptr++ kullanmıyoruz.
  }
   

}

// add element
void insertElement(int key, double data)
{
    LL_SYS_PARAM_PTR link = (LL_SYS_PARAM_PTR)malloc(sizeof(LL_SYS_PARAM));
    
    link->key = key;
    link->data = data;
    
    link->next = head;    // Burada linkin nexttine head ı atıyoruz.

    head = link;          // Burada ise heade linkin adresini atıyoruz.
}

/*
a1->next = null;
a2->next = a1;
a1->next = NULL
*/

// erase element
LL_SYS_PARAM_PTR deleteElement()
{
   LL_SYS_PARAM_PTR tempLink = head;

   head = head->next;

   return tempLink;    // erased element


}

//comparision section
bool isEmpty()
{
    return head == NULL;
}
int length()
{
    int len = 0;
    LL_SYS_PARAM_PTR current;     // local current

    for(current = head; current != NULL; current = current->next)
    {
        len++;
    }
    return len;
}


//finding a specific element
LL_SYS_PARAM_PTR find(int key)
{
    LL_SYS_PARAM_PTR current = head;

    while(current->key != key)
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
   return current;
}


// delete a link
LL_SYS_PARAM_PTR deleteFunc(int key)
{
     LL_SYS_PARAM_PTR current = head;
     LL_SYS_PARAM_PTR previous = NULL;
    
     if(head==NULL)
     {
        return NULL;
     }

     // finding the adress of element needs to be deleted
     while (current->key != key)
     {
        if(current->next == NULL)
        {
            return NULL;
        }
        else
        {
            previous = current;
            current = current->next;
        }
     }
     
     // delete address
     if(current == head)
     {
       head = head->next;
     }
     else
     {
         previous->next = current->next; // previous 2 , pn 3, current 3 cn 4 -> current is deleted!
     }

     return current;
}

void forwardDifferenceSolver(SYSTEM_PARAMETERS sys)
{
    const int SIZE = (sys.t_final - sys.t_initial)/sys.dt;
    double state = sys.x0;
    double input = 10;

    // giving initial condition to the state
    insertElement(0,state);

    for(int i=0; i<SIZE; i++)
    {
        // x[i+1] = x[i] +dt*(a*x[i] + b*u[i]);
        // state = x[i+1], preState->data = x[i];
        
        LL_SYS_PARAM_PTR prevState = find(i);
        state = prevState->data + sys.dt*(sys.firstParam*prevState->data + sys.secondParam*input);

        insertElement(i+1,state);

        printf("Key and value - (%1f,%1f)\n", (double)(i*sys.dt),prevState->data);
    }
}

void backwardDifferenceSolver(SYSTEM_PARAMETERS sys)
{
    const int SIZE = (sys.t_final-sys.t_initial)/sys.dt;
    double state = sys.x0;
    double input = 10;
    
    insertElement(0,state);
    
    // x[i] = x[i-1] + dt*(a*x[i-1]+b*input);
    
    for(int i=1;i<=SIZE;i++)
    {
        LL_SYS_PARAM_PTR prevState = find(i-1);

        state = prevState->data + sys.dt*(sys.firstParam*prevState->data+sys.secondParam*input);
        
        insertElement(i,state);
        printf("key and value- %d , %1f\n" ,i-1,prevState->data);
    }
}   


/// Linked list -> system Dynamics -> time response of system
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////


