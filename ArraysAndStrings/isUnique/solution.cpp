#include "solution.h"
#include<iostream>
#include<algorithm>
#include<unordered_map>

/*
* Note: for this problem, our BCR(Best Conceivable Time) is O(N) since we have to traverse every value
*/

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

HashMapSolution::HashMapSolution(std::string& s)
{
    input = s;
}

/*
* Time Complexity : O(N)
* Space Complexity: O(N)
*/

bool HashMapSolution::isUnique(){
    std::unordered_map<char,bool> m;
    for(int i=0;i<input.size();i++)
    {
        if(m.find(input[i]) != m.end())
        {
            return false;
        }
        m[input[i]] = true;
    }
    return true;
}

void HashMapSolution::solve()
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