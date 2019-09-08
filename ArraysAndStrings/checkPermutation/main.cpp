#include "solution.h"
#include<iostream>
int main()
{
    int test_cases;
    std::string input1,input2;
    std::cin>>test_cases;
    Solution* solution;
    while(test_cases--)
    {
        std::cin>>input1>>input2;
        std::cout<<"Sorting solution:-\n";
        solution = new SortSolution(input1,input2);
        solution->solve();
        delete solution;
        std::cout<<"HashMap solution NOT Optimised:-\n";
        solution = new HashMapSolutionNotOptimised(input1,input2);
        solution->solve();
        delete solution;
        std::cout<<"HashMap solution Optimised:-\n";
        solution = new HashMapSolutionSpaceOptimised(input1,input2);
        solution->solve();
        delete solution;
    }
    return 0;
}