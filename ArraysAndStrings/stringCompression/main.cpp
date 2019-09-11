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
        std::cout<<"Normal solution:-\n";
        solution = new NormalSolution(input);
        solution->solve();
        delete solution;
    }
    return 0;
}