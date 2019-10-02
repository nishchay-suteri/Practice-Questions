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
    int data = 20;
    head = new SinglyListNode<int>(data); 

    data = 4;
    newNode = new SinglyListNode<int>(data);  
    head->set_next(newNode); 
  
    data = 15;
    newNode = new SinglyListNode<int>(data); 
    head->get_next()->set_next(newNode); 
  
    data = 10;
    newNode = new SinglyListNode<int>(data); 
    head->get_next()->get_next()->set_next(newNode); 
  
    head->get_next()->get_next()->get_next()->set_next(head); 
   
}


/*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
}


SinglyListNode<int>* OptimalSolution::loopDetection()
{
    if(head == NULL)
    {
        return NULL;
    }
    SinglyListNode<int>* slow = head;
    SinglyListNode<int>* fast = head;
    while(fast && fast->get_next())
    {
        slow = slow->get_next();
        fast = fast->get_next()->get_next();
        if(slow == fast)
        {
            break;
        }
    }
    if(fast == NULL || fast->get_next() == NULL)
    {
        return NULL; // No LOOP
    }
    slow = head;
    while(slow != fast)
    {
        slow = slow->get_next();
        fast = fast->get_next();
    }
    return slow;
}

void OptimalSolution::solve()
{
    take_input();
    SinglyListNode<int>* loopStart = NULL;
    loopStart = loopDetection();
    if(loopStart != NULL)
    {
        std::cout <<"Found loop at: "<<loopStart->get_data()<<"\n";
    }
    else
    {
        std::cout<<"NOPE\n";
    }
    
    
}