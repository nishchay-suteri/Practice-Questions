#include "solution.h"
#include<iostream>

int main()
{
    int test_cases;
    std::cin>>test_cases;
    Solution* solution;
    int ** m = new int*[MAX_N];
    for(int i=0;i<MAX_N;i++)
    {
        m[i] = new int[MAX_N];
    }
    int n;
    while(test_cases--)
    {
        std::cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                std::cin>>m[i][j];
            }
        }
        std::cout<<"Normal solution:-\n";
        solution = new NormalSolution(m,n);
        solution->solve();
        delete solution;
    }
    return 0;
}