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

void OptimalSolution::verify(int t)
{
    for(int i=0;i<t;i++)
    {
        assert(bst->search(arr[i]));
    }

    assert(arr[t-1] == bst->get_max());

    // inorder display
    std::cout<<"Inorder display:-\n";
    bst->inOrderDisplay();
    std::cout<<"\n";

    // remove
    
    int i=0;
    while(!bst->isEmpty())
    {
        assert(bst->remove(arr[i]) == true);
        i++;
    }
    assert(bst->get_size() == 0);
}

void OptimalSolution::solve()
{
    int t,val;
    cin>>t;
    arr = new int[t];
    for(int i=0;i<t;i++)
    {
        cin>>val;
        arr[i] = val;
    }
    try
    {
        bst->createMinimalTree(arr,t);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        assert(0);
    }

    verify(t);
    std::cout<<"Success\n";
}