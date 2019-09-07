#include "solution.h"
#include<iostream>

BruteForceSolution::BruteForceSolution(std::string& s)
{
    input = s;
}

/*
* Time Complexity : O(n^2)
* Space Complexity: O(1)
*/

bool BruteForceSolution::isUnique(){
    for(int i=0;i<input.size()-1;i++)
    {
        for(int j=i+1;j<input.size();j++)
        {
            if(input[i] == input[j]){
                return false;
            }
        }
    }
    return true;
}

void BruteForceSolution::solve()
{
    if(isUnique())
    {
        std::cout<<"Yes\n";
    }
    else
    {
        std::cout<<"No\n";
    }
    
}