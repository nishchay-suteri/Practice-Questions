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

void OptimalSolution::deleteMiddleNode(SinglyListNode<int>* curr){
    if(curr == NULL || curr->get_next() == NULL)
    {
        std::cout<<"Invalid node\n";
        return;
    }
    curr->set_data(curr->get_next()->get_data());
    SinglyListNode<int>* nodeToDelete =curr->get_next();;
    curr->set_next(curr->get_next()->get_next());
    nodeToDelete->set_next(NULL);
    delete nodeToDelete;
}

void OptimalSolution::solve(int n)
{
    take_input(n);
    list.display();
    deleteMiddleNode(list.get_head()->get_next());
    list.display();
}