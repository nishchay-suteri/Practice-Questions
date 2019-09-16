#include "solution.h"
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<bitset>

// Base Class
Solution::Solution(std::string& i,std::string& t){
    input = i;
    test = t;
}


// Solution 1
/*
* Time Complexity : O(n)
* Space Complexity: O(1)
*/

NormalSolution::NormalSolution(std::string& i, std::string& t):
Solution(i,t)
{
    countToSubstr = 0;
}

bool NormalSolution::isSubstr(std::string& s)
{
    countToSubstr++;
    size_t pos = s.find(test);
    if(pos != std::string::npos)
    {
        return true;
    }
    return false;
}

bool NormalSolution::stringRotation(){
    std::string temp = input+input;
    return isSubstr(temp);
}

void NormalSolution::solve()
{
    bool r= stringRotation();
    if(r && countToSubstr==1)
    {
        std::cout<<"YES\n";
    }
    else
    {
        std::cout<<"NO\n";
    }
    
}

