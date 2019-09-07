#include "solution.h"
#include<iostream>
#include<algorithm>

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


SortSolution::SortSolution(std::string& s)
{
    input = s;
}

/*
* Time Complexity : O(nlog2(n))
* Space Complexity: O(1)
*/

bool SortSolution::isUnique(){
    std::sort(input.begin(),input.end()); // this is the Bottleneck
    for(int i=0;i<input.size()-1;i++)
    {
        if(input[i] == input[i+1]){
            return false;
        }
    }
    return true;
}

void SortSolution::solve()
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