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
        std::cin>>n;
        std::cout<<"Brute Force solution:-\n";
        solution = new BruteForceSolution();
        solution->solve(n);
        delete solution;
        std::cout<<"Sorting solution:-\n";
        solution = new SortSolution();
        solution->solve(n);
        delete solution;
        std::cout<<"HashMap solution:-\n";
        solution = new HashMapSolution();
        solution->solve(n);
        delete solution;
        std::cout<<"BitSet solution:-\n";
        solution = new BitSetSolution();
        solution->solve(n);
        delete solution;
    }
    return 0;
}