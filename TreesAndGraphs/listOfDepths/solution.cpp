#include "solution.h"
#include<iostream>
#include<assert.h>

using namespace std;
/*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
    this->bst = new BinarySearchTree<int>();   
}
OptimalSolution::~OptimalSolution()
{
    delete this->bst;
}

void OptimalSolution::solve()
{
    int t,val;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>val;
        bst->insert(val);
    }
    bst->listOfDepths();
}