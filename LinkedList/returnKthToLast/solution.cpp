#include "solution.h"

/*
* Note: for this problem, our BCR(Best Conceivable Time) is O(N) since we have to traverse every value
*/

void Solution::take_input(int n){
    int input;
    for(int i=0;i<n;i++){
        std::cin>>input;
        list.push_back(input);
    }
}


/*
* Time Complexity : O(n)
* Space Complexity: O(1)
*/

BruteForceSolution::BruteForceSolution()
{
}

SinglyListNode<int>* BruteForceSolution::returnKthToLast(SinglyListNode<int>* node,int k){
    int n = 0;
    SinglyListNode<int>* itr = list.get_head();
    while(itr)
    {
        n++;
        itr = itr->get_next();
    }
    if(k>n)
    {
        return NULL;
    }
    itr = list.get_head();
    for(int i=0;i<n-k;i++)
    {
        itr = itr->get_next();
    }
    return itr;
}

void BruteForceSolution::solve(int n,int k)
{
   take_input(n);
   SinglyListNode<int>* node = returnKthToLast(list.get_head(),k);
   if(node == NULL)
   {
       std::cout<<"Invalid K\n";
   }
   else
   {
       std::cout<<node->get_data()<<"\n";
   }
}



/*
* Time Complexity : O(n)
* Space Complexity: O(n)
*/
RecursiveSolution::RecursiveSolution()
{
    index= 0;
}

SinglyListNode<int>* RecursiveSolution::returnKthToLast(SinglyListNode<int>* node,int k){
    if(node == NULL)
    {
        return NULL;
    }
    SinglyListNode<int>* n = returnKthToLast(node->get_next(),k);
    index++;
    if(index == k)
    {
        return node;
    }
    else
    {
        return n;
    }
    
}

void RecursiveSolution::solve(int n,int k)
{
    take_input(n);
    SinglyListNode<int>* node = returnKthToLast(list.get_head(),k);
    if(node == NULL)
    {
        std::cout<<"Invalid K\n";
    }
    else
    {
        std::cout<<node->get_data()<<"\n";
    }
}


/*
* Time Complexity : O(N)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
}

SinglyListNode<int>* OptimalSolution::returnKthToLast(SinglyListNode<int>* node,int k){
    SinglyListNode<int>* frwd_ptr = list.get_head();
    int count = 0;
    while (frwd_ptr)
    {
        frwd_ptr = frwd_ptr->get_next();
        count++;
        if(count == k)
        {
            break;
        }
    }
    if(count!=k)
    {
        return NULL;
    }
    SinglyListNode<int>* bkwd_ptr = list.get_head();
    while(frwd_ptr)
    {
        frwd_ptr = frwd_ptr->get_next();
        bkwd_ptr = bkwd_ptr->get_next();
    }
    return bkwd_ptr;
    
}

void OptimalSolution::solve(int n,int k)
{
    take_input(n);
    SinglyListNode<int>* node = returnKthToLast(list.get_head(),k);
    if(node == NULL)
    {
        std::cout<<"Invalid K\n";
    }
    else
    {
        std::cout<<node->get_data()<<"\n";
    }
}