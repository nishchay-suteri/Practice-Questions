#include "solution.h"
#include<iostream>
int main()
{
    int test_cases;
    std::string input,test;
    std::cin>>test_cases;
    Solution* solution;
    while(test_cases--)
    {
        std::cin>>input>>test;
        std::cout<<"Normal solution:-\n";
        solution = new NormalSolution(input,test);
        solution->solve();
        delete solution;
    }
    return 0;
}