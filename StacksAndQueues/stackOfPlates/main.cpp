#include "solution.h"
#include<iostream>
int main()
{
    int test_cases,t;
    std::cin>>test_cases;
    Solution* solution;
    while(test_cases--)
    {
        std::cout<<"Optimal solution:-\n";
        std::cout<<"Threshold: ";
        std::cin>>t;
        solution = new OptimalSolution(t);
        solution->solve();
        delete solution;
    }
    return 0;
}