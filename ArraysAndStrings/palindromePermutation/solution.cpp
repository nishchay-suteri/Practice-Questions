#include "solution.h"
#include<iostream>

/*
* Note: for this problem, our BCR(Best Conceivable Time) is O(N) since we have to traverse every value
*/
// Base Class
Solution::Solution(std::string& s1){
    input = s1;
}



// Solution 1
/*
* Time Complexity : O(N)
* Space Complexity: O(1)(since we'll use constant space according to the character set)
*/

HashMapSolution::HashMapSolution(std::string& s1):
Solution(s1)
{
    for(int i=0;i<MAX_N;i++)
    {
        hMap[i] = 0;
    }
}

bool HashMapSolution::checkPalindromePermutation(){
    for(int i=0;i<input.size();i++)
    {
        hMap[(int)(input[i])] = (hMap[(int)(input[i])]+1)%2;
    }
    int countOfOdd = 0;
    for(int i=0;i<MAX_N;i++)
    {
        if(hMap[i] == 1)
        {
            countOfOdd++;
            if(countOfOdd > 1)
            {
                return false;
            }
        }
    }
    return true;
}

void HashMapSolution::solve()
{
    if(checkPalindromePermutation())
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
* Space Complexity: O(1)(BUT, it'll be eight times less as compared to Solution 2)
*/

BitSetSolution::BitSetSolution(std::string& s1):
Solution(s1)
{
}

bool BitSetSolution::isSingleBitSet(){
    if(bSet.count() == 1){
        return true;
    }
    return false;
}

bool BitSetSolution::checkPalindromePermutation(){
    int n = input.size();
    for(int i=0;i<n;i++)
    {
        int bitPos = (int)(input[i]);
        if(bSet.test(bitPos)){
            bSet.set(bitPos,0);
        }
        else{
            bSet.set(bitPos);
        }
    }
    if(bSet == 0 || isSingleBitSet())
    {
        return true;
    }
    return false;
}

void BitSetSolution::solve()
{
    if(checkPalindromePermutation())
    {
        std::cout<<"Yes\n";
    }
    else
    {
        std::cout<<"No\n";
    }
    
}




