#include "solution.h"
#include<iostream>
int main()
{
    int test_cases;
    int n,k;
    std::cin>>test_cases;
    Solution* solution;
    while(test_cases--)
    {
        std::cin>>n>>k;
        std::cout<<"Brute Force solution:-\n";
        solution = new BruteForceSolution();
        solution->solve(n,k);
        delete solution;
        std::cout<<"Recurive solution:-\n";
        solution = new RecursiveSolution();
        solution->solve(n,k);
        delete solution;
        std::cout<<"Optimal solution:-\n";
        solution = new OptimalSolution();
        solution->solve(n,k);
        delete solution;
    }
    return 0;
}