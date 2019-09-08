#include "solution.h"
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<bitset>

/*
* Note: for this problem, our BCR(Best Conceivable Time) is O(N) since we have to traverse every value
*/
// Base Class
Solution::Solution(std::string& s1, std::string& s2){
    input1 = s1;
    input2 = s2;
}


// Solution 1
/*
* Time Complexity : O(nlog2(n))
* Space Complexity: O(1)
*/

SortSolution::SortSolution(std::string& s1, std::string& s2):
Solution(s1,s2)
{
}

bool SortSolution::checkPermutation(){
    if(input1.size() != input2.size())
    {
        return false;
    }
    std::sort(input1.begin(),input1.end()); // this is the Bottleneck
    std::sort(input2.begin(),input2.end()); // this is the Bottleneck

    for(int i=0;i<input1.size();i++)
    {
        if(input1[i] != input2[i]){
            return false;
        }
    }
    return true;
}

void SortSolution::solve()
{
    if(checkPermutation())
    {
        std::cout<<"Yes\n";
    }
    else
    {
        std::cout<<"No\n";
    }
    
}

// Solution 2
/*
* Time Complexity : O(N)
* Space Complexity: O(1)(since we'll use constant space according to the character set)
*/

HashMapSolutionNotOptimised::HashMapSolutionNotOptimised(std::string& s1, std::string& s2):
Solution(s1,s2)
{
    for(int i=0;i<MAX_N;i++)
    {
        hMapA[i] = 0;
        hMapB[i] = 0;
    }
}

bool HashMapSolutionNotOptimised::checkPermutation(){
    if(input1.size() != input2.size())
    {
        return false;
    }
    for(int i=0;i<input1.size();i++)
    {
        hMapA[(int)(input1[i])] += 1;
    }
    for(int i=0;i<input2.size();i++)
    {
        hMapB[(int)(input2[i])] += 1;
    }
    for(int i=0;i<MAX_N;i++)
    {
        if(hMapA[i] != hMapB[i])
        {
            return false;
        }
    }
    return true;
}

void HashMapSolutionNotOptimised::solve()
{
    if(checkPermutation())
    {
        std::cout<<"Yes\n";
    }
    else
    {
        std::cout<<"No\n";
    }
    
}


// Solution 2.1
/*
* Time Complexity : O(N)
* Space Complexity: O(1)(BUT, it'll be half as compared to Solution 2)
*/

HashMapSolutionSpaceOptimised::HashMapSolutionSpaceOptimised(std::string& s1, std::string& s2):
Solution(s1,s2)
{
    for(int i=0;i<MAX_N;i++)
    {
        hMap[i] = 0;
    }
}

bool HashMapSolutionSpaceOptimised::checkPermutation(){
    if(input1.size() != input2.size())
    {
        return false;
    }
    for(int i=0;i<input1.size();i++)
    {
        hMap[(int)(input1[i])] += 1;
    }
    for(int i=0;i<input2.size();i++)
    {
        hMap[(int)(input2[i])] -= 1;
        if(hMap[(int)(input2[i])] < 0){
            return false;
        }
    }
    return true;
}

void HashMapSolutionSpaceOptimised::solve()
{
    if(checkPermutation())
    {
        std::cout<<"Yes\n";
    }
    else
    {
        std::cout<<"No\n";
    }
    
}




