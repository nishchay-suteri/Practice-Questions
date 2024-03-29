#include "solution.h"
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<bitset>

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


BitSetSolution::BitSetSolution(std::string& s)
{
    input = s;
}

/*
* Time Complexity : O(N)
* Space Complexity: O(N) // will be 8 times less than the UnOrdered Map Solution
* BUT, We've to assume that only lowercase letters will be there,
* since for using bitset, we have to know the number of bits we need to assign,
* and our assumption will help us to assign 26 bits.
*/

bool BitSetSolution::isUnique(){
    std::bitset<26> bSet;
    for(int i=0;i<input.size();i++)
    {
        int iBit = (int)(input[i])-(int)('a');
        if(bSet.test(iBit))
        {
            return false;
        }
        bSet.set(iBit);
    }
    return true;
}

void BitSetSolution::solve()
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