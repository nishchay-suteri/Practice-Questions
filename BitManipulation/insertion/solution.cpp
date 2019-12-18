#include "solution.h"
#include<iostream>
#include<assert.h>

using namespace std;
/*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
}
OptimalSolution::~OptimalSolution()
{
}

void OptimalSolution::verify(int ans, int res)
{
    if(ans == res)
    {
        std::cout<<"Passed\n";
    }
    else
    {
        std::cout<<"FAILED\n";
        std::cout<<"Expected: "<<res<<std::endl;
        std::cout<<"Got: "<<ans<<std::endl;
    }
    
}

int OptimalSolution::solve_helper(int N,int M,int i,int j)
{
    int mask1 = 0;
    mask1 = (-1)<<(j+1);
    int mask2 = 0;
    mask2 = ~((-1)<<(i));
    int mask = 0;
    mask = mask1 | mask2;
    N = N & mask;
    M = M << i;
    N = N|M;
    return N;
}
#if DEBUG
void OptimalSolution::numOfSetBits()
{
    int num = -1;
    int count = 0;
    while(num)
    {
        num = num&(num-1);
        count++;
    }
    std::cout<<count<<std::endl;
}
#endif
void OptimalSolution::solve()
{
    #if !DEBUG
    int N,M,i,j,result;
    cin>>N>>M>>i>>j>>result;
    int ans = solve_helper(N,M,i,j);
    verify(ans,result);
    std::cout<<"Success\n";
    #else
        numOfSetBits();
    #endif
}