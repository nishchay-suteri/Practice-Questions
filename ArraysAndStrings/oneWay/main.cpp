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
        std::cout<<"Normal solution:-\n";
        solution = new NormalSolution(input1,input2);
        solution->solve();
        delete solution;
    }
    return 0;
}