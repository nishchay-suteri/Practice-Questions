#include "solution.h"
#include<iostream>

int main()
{
    int test_cases;
    std::cin>>test_cases;
    Solution* solution;
    int ** mat = new int*[MAX_N];
    for(int i=0;i<MAX_N;i++)
    {
        mat[i] = new int[MAX_N];
    }
    int m,n;
    while(test_cases--)
    {
        std::cin>>m>>n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                std::cin>>mat[i][j];
            }
        }
        std::cout<<"Normal solution:-\n";
        solution = new BruteForceSolution(mat,m,n);
        solution->solve();
        delete solution;

        std::cout<<"BitSet solution:-\n";
        solution = new BitSetSolution(mat,m,n);
        solution->solve();
        delete solution;

        std::cout<<"Optimal solution:-\n";
        solution = new OptimalSolution(mat,m,n);
        solution->solve();
        delete solution;
    }
    return 0;
}