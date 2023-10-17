#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <time.h>
#include <math.h>
#include <iomanip>

using namespace std;


void showPerformanceOperation(clock_t t,string s)
{
    cout << s << " result : " << setprecision(12) << (float)t/CLOCKS_PER_SEC << endl;
}


void fill(int **arr,int row,int column, int processNumber)
{
    for(int i=0; i<row;i++)
    {
        for(int k=0; k<column ; k++)
        {
            int sum = 0;
            
            for(int j=0;j<processNumber;j++)
            {
                sum += i * k;
            }

            arr[i][k] = sum;
        }
    }
}


///////////////////////////////////////////////////////
/// Initialize dynamic memory 


int **initializeMatrices(int row, int column)
{
    int **arr = new int *[row];

    for(int i = 0; i<row;i++)
    {
        arr[i] = new int[column];
    }

    return arr;
}

// deleting dynamic memory

void deleteMemory(int **arr,int row,int column)
{

    for(int i=0;i<row;i++)
    {
        delete[] arr[i];
    }

    delete[] arr;
}


void display(int **arr,int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0; j<column;j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


#define MULTI 1
#define ROW 1920
#define COLUMN 1080
#define PROCESS_NUMBER 1000 

int main()
{
    int **ArrayMatrices;
    int **BrrayMatrices;
    int **CrrayMatrices;
    int **DrrayMatrices;
    int **ErrayMatrices;
    int **FrrayMatrices;
    int **GrrayMatrices;
    int **HrrayMatrices;
    int **IrrayMatrices;


    ArrayMatrices = initializeMatrices(ROW,COLUMN);
    BrrayMatrices = initializeMatrices(ROW,COLUMN);
    CrrayMatrices = initializeMatrices(ROW,COLUMN);
    DrrayMatrices = initializeMatrices(ROW,COLUMN);
    ErrayMatrices = initializeMatrices(ROW,COLUMN);
    FrrayMatrices = initializeMatrices(ROW,COLUMN);
    GrrayMatrices = initializeMatrices(ROW,COLUMN);
    HrrayMatrices = initializeMatrices(ROW,COLUMN);
    IrrayMatrices = initializeMatrices(ROW,COLUMN);


#if MULTI == 1
   
   clock_t t = clock();

   fill(ArrayMatrices,ROW,COLUMN,PROCESS_NUMBER);
   fill(BrrayMatrices,ROW,COLUMN,PROCESS_NUMBER);
   fill(CrrayMatrices,ROW,COLUMN,PROCESS_NUMBER);
   fill(DrrayMatrices,ROW,COLUMN,PROCESS_NUMBER);
   fill(ErrayMatrices,ROW,COLUMN,PROCESS_NUMBER);
   fill(FrrayMatrices,ROW,COLUMN,PROCESS_NUMBER);
   fill(GrrayMatrices,ROW,COLUMN,PROCESS_NUMBER);
   fill(HrrayMatrices,ROW,COLUMN,PROCESS_NUMBER);
   fill(IrrayMatrices,ROW,COLUMN,PROCESS_NUMBER);
   
   t = clock() -t ;

   showPerformanceOperation(t,"Normal Operation");

   deleteMemory(ArrayMatrices,ROW,COLUMN);
   deleteMemory(BrrayMatrices,ROW,COLUMN);
   deleteMemory(CrrayMatrices,ROW,COLUMN);
   deleteMemory(DrrayMatrices,ROW,COLUMN);
   deleteMemory(ErrayMatrices,ROW,COLUMN);
   deleteMemory(FrrayMatrices,ROW,COLUMN);
   deleteMemory(GrrayMatrices,ROW,COLUMN);
   deleteMemory(HrrayMatrices,ROW,COLUMN);
   deleteMemory(IrrayMatrices,ROW,COLUMN);
  
#else
   clock_t t = clock();


std::thread first([&]() { fill(ArrayMatrices, ROW, COLUMN, PROCESS_NUMBER); });
std::thread second([&]() { fill(BrrayMatrices, ROW, COLUMN, PROCESS_NUMBER); });
std::thread third([&]() { fill(CrrayMatrices, ROW, COLUMN, PROCESS_NUMBER); });
std::thread fourth([&]() { fill(DrrayMatrices, ROW, COLUMN, PROCESS_NUMBER); });
std::thread fifth([&]() { fill(ErrayMatrices, ROW, COLUMN, PROCESS_NUMBER); });
std::thread sixth([&]() { fill(FrrayMatrices, ROW, COLUMN, PROCESS_NUMBER); });
std::thread seventh([&]() { fill(GrrayMatrices, ROW, COLUMN, PROCESS_NUMBER); });
std::thread eighth([&]() { fill(HrrayMatrices, ROW, COLUMN, PROCESS_NUMBER); });
std::thread nineth([&]() { fill(IrrayMatrices, ROW, COLUMN, PROCESS_NUMBER); });

/*
  std::thread first(fill, ArrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
  std::thread second(fill, BrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
  std::thread third(fill, CrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
  std::thread fourth(fill, DrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
  std::thread fifth(fill, ErrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
  std::thread sixth(fill, FrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
  std::thread seventh(fill, GrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
  std::thread eighth(fill, HrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);
  std::thread nineth(fill, IrrayMatrices, ROW, COLUMN, PROCESS_NUMBER);

  */

   first.join();
   second.join();
   third.join();
   fourth.join();
   fifth.join();
   sixth.join();
   seventh.join();
   eighth.join();
   nineth.join();

   t = clock() - t;

   showPerformanceOperation(t, "Normal Operation");

   deleteMemory(ArrayMatrices,ROW,COLUMN);
   deleteMemory(BrrayMatrices,ROW,COLUMN);
   deleteMemory(CrrayMatrices,ROW,COLUMN);
   deleteMemory(DrrayMatrices,ROW,COLUMN);
   deleteMemory(ErrayMatrices,ROW,COLUMN);
   deleteMemory(FrrayMatrices,ROW,COLUMN);
   deleteMemory(GrrayMatrices,ROW,COLUMN);
   deleteMemory(HrrayMatrices,ROW,COLUMN);
   deleteMemory(IrrayMatrices,ROW,COLUMN);

#endif


    return 0;
}