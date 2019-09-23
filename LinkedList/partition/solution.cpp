#include "solution.h"

void Solution::take_input(int n){
    int input;
    for(int i=0;i<n;i++){
        std::cin>>input;
        list.push_back(input);
    }
}


/*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
}

void OptimalSolution::partition(int p)
{
    SinglyListNode<int>* prev = list.get_head();
    SinglyListNode<int>* curr = prev->get_next();
    SinglyListNode<int>* newNode = NULL;
    while(prev)
    {
        list.set_head(curr);
        prev->set_next(NULL);
        newNode = prev;
        prev = curr;
        if(curr)
        {
            curr = curr->get_next();
        }
        if(newNode->get_data()<p)
        {
            new_list.push_front(newNode);
        }
        else
        {
            new_list.push_back(newNode);
        }
        
    }
}

void OptimalSolution::solve(int n,int p)
{
    take_input(n);
    list.display();
    partition(p);
    new_list.display();
}