#include "solution.h"
#include<iostream>
#include<algorithm>
#include<unordered_map>

/*
* Note: for this problem, our BCR(Best Conceivable Time) is O(N) since we have to traverse every value
*/
// Base Class
void Solution::display(){
    for(int i=0;i<maxRow;i++)
    {
        for(int j = 0;j<maxCol;j++)
        {
            std::cout<<mat[i][j]<<" ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

void Solution::make_row_zero(int m[MAX_M][MAX_N],int row)
{
    for(int c=0;c<maxCol;c++)
    {
        m[row][c] = 0;
    }
}

void Solution::make_col_zero(int m[MAX_M][MAX_N],int col)
{
    for(int r=0;r<maxRow;r++)
    {
        m[r][col] = 0;
    }
}

// Solution 1
/*
* Time Complexity : O(m*n*(m+n))
* Space Complexity: O(m*n)
*/

BruteForceSolution::BruteForceSolution(int** matr,int m,int n)
{
    maxRow = m;
    maxCol = n;
    for(int i=0;i<maxRow;i++)
    {
        for(int j=0;j<maxCol;j++)
        {
            mat[i][j] = matr[i][j];
            this->mat_copy[i][j] = -1;
        }
    }
}

void BruteForceSolution::zeroMatrix(){
    for(int i=0;i<maxRow;i++)
    {
        for(int j=0;j<maxCol;j++)
        {
            if(mat[i][j] == 0)
            {
                mat_copy[i][j] = 0;
            }
        }
    }
    for(int i=0;i<maxRow;i++)
    {
        for(int j=0;j<maxCol;j++)
        {
            if(mat_copy[i][j] == 0)
            {
                make_row_zero(mat,i);
                make_col_zero(mat,j);
            }
        }
    }
}

void BruteForceSolution::solve()
{
    std::cout<<"Before Solving:-\n";
    display();
    zeroMatrix();
    std::cout<<"After Solving:-\n";
    display();
    
}



// Solution 2
/*
* Time Complexity : O(m*n)
* Space Complexity: O(m+n)
*/

BitSetSolution::BitSetSolution(int** matr,int m,int n)
{
    maxRow = m;
    maxCol = n;
    for(int i=0;i<maxRow;i++)
    {
        for(int j=0;j<maxCol;j++)
        {
            mat[i][j] = matr[i][j];
        }
    }
}

void BitSetSolution::zeroMatrix(){
    for(int i=0;i<maxRow;i++)
    {
        for(int j=0;j<maxCol;j++)
        {
            if(mat[i][j] == 0)
            {
                r_b.set(i);
                c_b.set(j);
            }
        }
    }
    for(int i=0;i<maxRow;i++)
    {
        if(r_b.test(i))
        {
            make_row_zero(mat,i);
        }
    }

    for(int i=0;i<maxCol;i++)
    {
        if(c_b.test(i))
        {
            make_col_zero(mat,i);
        }
    }
}

void BitSetSolution::solve()
{
    std::cout<<"Before Solving:-\n";
    display();
    zeroMatrix();
    std::cout<<"After Solving:-\n";
    display();
    
}

// Solution 3
/*
* Time Complexity : O(m*n)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution(int** matr,int m,int n)
{
    maxRow = m;
    maxCol = n;
    for(int i=0;i<maxRow;i++)
    {
        for(int j=0;j<maxCol;j++)
        {
            mat[i][j] = matr[i][j];
        }
    }
}

bool OptimalSolution::check_zero_first_row(){
    for(int i=0;i<maxCol;i++)
    {
        if(mat[0][i] == 0)
        {
            return true;
        }
    }
    return false;
}

bool OptimalSolution::check_zero_first_col(){
    for(int i=0;i<maxRow;i++)
    {
        if(mat[i][0] == 0)
        {
            return true;
        }
    }
    return false;
}

void OptimalSolution::zeroMatrix(){
    bool rowHasZero = check_zero_first_row();
    bool colHasZero = check_zero_first_col();
    for(int i=1;i<maxRow;i++)
    {
        for(int j=1;j<maxCol;j++)
        {
            if(mat[i][j] == 0)
            {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }
    for(int i=1;i<maxRow;i++)
    {
        if(mat[i][0] == 0)
        {
            make_row_zero(mat,i);
        }
    }

    for(int i=1;i<maxCol;i++)
    {
        if(mat[0][i] == 0)
        {
            make_col_zero(mat,i);
        }
    }

    if(rowHasZero)
    {
        make_row_zero(mat,0);
    }
    if(colHasZero)
    {
        make_col_zero(mat,0);
    }

}

void OptimalSolution::solve()
{
    std::cout<<"Before Solving:-\n";
    display();
    zeroMatrix();
    std::cout<<"After Solving:-\n";
    display();
    
}
