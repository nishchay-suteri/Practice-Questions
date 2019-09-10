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

NormalSolution::NormalSolution(std::string& s1, std::string& s2):
Solution(s1,s2)
{
}

int NormalSolution::abs(int num)
{
    if(num<0)
    {
        num = (-1)*num;
    }
    return num;
}

bool NormalSolution::replaceCase()
{
    bool unMatchedFound = false;
    for(int i=0;i<input1.size();i++)
    {
        if(input1[i] != input2[i])
        {
            if(unMatchedFound)
            {
                return false;
            }
            unMatchedFound = true;
        }
    }
    return true;
}

bool NormalSolution::removeCase(std::string& s1, std::string& s2)
{
    int i=0,j=0;
    while(i<s1.size() && j<s2.size())
    {
        if(s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            if(i!=j) // We can't have 2 unmatches in remove case
            {
                return false;
            }
            i++;
        }
    }
    return true;
}

bool NormalSolution::oneWay(){
    if(abs(input1.size() - input2.size()) > 1)
    {
        return false;
    }
    if(input1.size() == input2.size())
    {
        return replaceCase();
    }
    else
    {
        if(input1.size() > input2.size())
        {
            return removeCase(input1,input2);
        }
        else
        {
            return removeCase(input2,input1);
        }
        
    }
    return false;
}

void NormalSolution::solve()
{
    if(oneWay())
    {
        std::cout<<"Yes\n";
    }
    else
    {
        std::cout<<"No\n";
    }
    
}

