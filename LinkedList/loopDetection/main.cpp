#include "solution.h"
#include<iostream>
int main()
{
    int test_cases;
    int n;
    std::cin>>test_cases;
    Solution* solution;
    while(test_cases--)
    {
        std::cout<<"Optimal solution:-\n";
        solution = new OptimalSolution();
        solution->solve();
        delete solution;
    }
    return 0;
}