#include "solution.h"

void Solution::take_input(){
    /*  
        Create two linked lists  
      
        1st 3->6->9->15->30  
        2nd 10->15->30  
      
        15 is the intersection point  
    */
  
    SinglyListNode<int>* newNode; 
  
    // Addition of new nodes 
    int data = 10;
    head1 = new SinglyListNode<int>(data); 
  
    data = 3;
    head2 = new SinglyListNode<int>(data); 
  
    data = 6;
    newNode = new SinglyListNode<int>(data);  
    head2->set_next(newNode); 
  
    data = 9;
    newNode = new SinglyListNode<int>(data); 
    head2->get_next()->set_next(newNode); 
  
    data = 15;
    newNode = new SinglyListNode<int>(data); 
    head1->set_next(newNode); 
    head2->get_next()->get_next()->set_next(newNode); 
  
    data = 30;
    newNode = new SinglyListNode<int>(data); 
    head1->get_next()->set_next(newNode); 
  
    head1->get_next()->get_next()->set_next(NULL); 
   
}


/*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
}

Result* OptimalSolution::get_size_and_tail(SinglyListNode<int>* node,int size)
{
    if(node == NULL)
    {
        return new Result(node,size);
    }
    if(node->get_next() == NULL)
    {
        return new Result(node,size);
    }
    return get_size_and_tail(node->get_next(),size+1);    
}


SinglyListNode<int>* OptimalSolution::intersection()
{
    if(head1 == NULL || head2 == NULL)
    {
        return NULL;
    }
    Result* result1 = get_size_and_tail(head1,1);
    Result* result2 = get_size_and_tail(head2,1);
    if(result1->tail != result2->tail)
    {
        return NULL;
    }
    int diff = 0;
    SinglyListNode<int>* shorter;
    SinglyListNode<int>* longer;
    if(result1->size < result2->size)
    {
        diff = result2->size - result1->size;
        shorter = head1;
        longer = head2;
    }
    else
    {
        diff = result1->size - result2->size;
        shorter = head2;
        longer = head1;
    }
    for(int i=0;i<diff;i++)
    {
        longer = longer->get_next();
    }
    while(shorter != longer)
    {
        shorter = shorter->get_next();
        longer = longer->get_next();
    }
    assert(shorter == longer);
    assert(shorter != NULL);
    return shorter;
    
}

void OptimalSolution::solve()
{
    take_input();
    std::cout << "The node of intersection is " << intersection()->get_data() <<"\n";
}