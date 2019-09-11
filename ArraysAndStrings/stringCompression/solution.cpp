#include "solution.h"
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<bitset>

/*
* Note: for this problem, our BCR(Best Conceivable Time) is O(N) since we have to traverse every value
*/
// Base Class
Solution::Solution(std::string& s){
    input = s;
}


// Solution 1
/*
* Time Complexity : O(n)
* Space Complexity: O(1)
*/

NormalSolution::NormalSolution(std::string& s):
Solution(s)
{
}

std::string NormalSolution::stringCompression(){
    std::string result = "";
    int i=0,j=0,count = 0;
    char current;
    int n = input.size();
    while(i<n){
        current = input[i];
        result.push_back(current);
        j = i;
        count = 0;
        while(j<n && input[j] == input[i]){
            j++;
            count++;
        }
        result +=std::to_string(count);
        i = j;
    }
    if(n <= result.size())
    {
        return input;
    }
    else
    {
        return result;
    }
        
}

void NormalSolution::solve()
{
    std::string s = stringCompression();
    std::cout<<s<<"\n";
}

