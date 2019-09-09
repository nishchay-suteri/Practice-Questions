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
        std::cout<<"HashMap solution:-\n";
        solution = new HashMapSolution(input);
        solution->solve();
        delete solution;
        std::cout<<"BitSet Solution:-\n";
        solution = new BitSetSolution(input);
        solution->solve();
        delete solution;
    }
    return 0;
}