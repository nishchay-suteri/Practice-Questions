#include "solution.h"
#include<iostream>
int main()
{
    int test_cases;
    std::string input;
    std::cin>>test_cases;
    Solution* solution;
    while(test_cases--)
    {
        std::cin>>input;
        std::cout<<"Brute Force solution:-\n";
        solution = new BruteForceSolution(input);
        solution->solve();
        delete solution;
        std::cout<<"Sorting solution:-\n";
        solution = new SortSolution(input);
        solution->solve();
        delete solution;

    }
    return 0;
}