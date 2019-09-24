#include "solution.h"
#include<iostream>
int main()
{
    int test_cases;
    int n,p;
    std::cin>>test_cases;
    Solution* solution;
    while(test_cases--)
    {
        std::cin>>n>>p;
        std::cout<<"Optimal solution:-\n";
        solution = new OptimalSolution();
        solution->solve(n,p);
        delete solution;
    }
    return 0;
}