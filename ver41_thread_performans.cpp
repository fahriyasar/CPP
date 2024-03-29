/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
//// Filling Vector Table


#include <iostream>
#include <vector>
#include <functional>
#include <thread>
#include <time.h>
#include <math.h>
#include <iomanip>


#define MULTI 2
#define SIZE 3000000

void fill(std::vector<unsigned long long int> &v,size_t n)
{
    int sum = 0;
    for(size_t i = 0; i<n; ++i)
    {
       for(size_t j = 0; j<100;++j)
       {
         sum += sqrt(i*j);
       }
    }
    v.push_back(sum);
}

void showPerformanceOperation(clock_t t,std::string s)
{
    std::cout << s << " result : " << std::setprecision(12) << (float)(t/CLOCKS_PER_SEC) <<std::endl;
}

int main()
{
    std::vector<unsigned long long int> v1,v2,v3,v4;
    v1.reserve(SIZE);
    v2.reserve(SIZE);
    v3.reserve(SIZE);
    v4.reserve(SIZE);

#if MULTI == 1
    // normal running mode
    clock_t t = clock();
    fill(v1,SIZE);
    fill(v2,SIZE);
    fill(v3,SIZE);
    fill(v4,SIZE);

    t = clock() - t;

    showPerformanceOperation(t,"Normal Operation");
#else
    // thread running mode
    
    clock_t t = clock();
    std::thread first(fill, std::ref(v1),SIZE);
    std::thread second(fill, std::ref(v2),SIZE);
    std::thread third(fill, std::ref(v3),SIZE);
    std::thread forth(fill, std::ref(v4),SIZE);


    first.join();
    second.join();
    third.join();
    forth.join();

    t = clock() - t;

    showPerformanceOperation(t,"Normal Operation");

#endif

    return 0;
}



//// Filling Vector Table
/////////////////////////////////////////////////////
/////////////////////////////////////////////////////
