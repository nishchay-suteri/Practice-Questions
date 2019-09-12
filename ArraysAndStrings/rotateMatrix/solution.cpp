#include "solution.h"
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<bitset>

/*
* Note: for this problem, our BCR(Best Conceivable Time) is O(N) since we have to traverse every value
*/
// Base Class
void Solution::display(){
    for(int i=0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            std::cout<<mat[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

// Solution 1
/*
* Time Complexity : O(nlog2(n))
* Space Complexity: O(1)
*/

NormalSolution::NormalSolution(int** m,int num)
{
    n = num;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            mat[i][j] = m[i][j];
        }
    }
}

void NormalSolution::rotatePoints(int r,int c)
{
    int prevValue = mat[r][c];
    int prevR = r;
    int prevC = c;
    int newVal,newR,newC;
    for(int i=0;i<4;i++)
    {
        newR = prevC;
        newC = n-prevR-1;
        // (r,c) -> (c,n-r-1)
        newVal = mat[newR][newC];
        mat[newR][newC] = prevValue;
        prevR = newR;
        prevC = newC;
        prevValue = newVal;
    }
}

void NormalSolution::rotateMatrix(){
    int newN = n;
    int startrow = 0;
    int startCol = 0;
    int r,c;
    while(newN>n/2)
    {
        r = startrow;
        c = startCol;
        while(c<newN-1)
        {
            rotatePoints(r,c);
            c++;
        }
        startCol++;
        startrow++;
        newN--;
    }
}

void NormalSolution::solve()
{
    std::cout<<"Before Rotation:-\n";
    display();
    rotateMatrix();
    std::cout<<"After Rotation:-\n";
    display();
    
}

