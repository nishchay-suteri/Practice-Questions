#include "solution.h"

void Solution::take_input(int n1,int n2){
    int input;
    for(int i=0;i<n1;i++){
        std::cin>>input;
        list1.push_back(input);
    }
    for(int i=0;i<n2;i++){
        std::cin>>input;
        list2.push_back(input);
    }
}


/*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
}


SinglyLinkedList<int>* OptimalSolution::sum_lists_helper(SinglyListNode<int>* itr1, SinglyListNode<int>* itr2, int& carry)
{
    if(itr1 == NULL && itr2 == NULL)
    {
        return new SinglyLinkedList<int>;
    }
    assert(itr1!=NULL);
    assert(itr2 != NULL);
    SinglyLinkedList<int>* newList = sum_lists_helper(itr1->get_next(),itr2->get_next(),carry);
    int sum = itr1->get_data() + itr2->get_data() + carry;
    carry = sum/10;
    sum = sum%10;
    newList->push_front(sum);
    return newList;
}


SinglyLinkedList<int>* OptimalSolution::sum_lists()
{
    int carry = 0;
    int size1 = list1.get_size();
    int size2 = list2.get_size();
    int numOfZeros = 0;
    int zeroValue = 0;// to make sure push_front() goes to T&d constructor, not in Node* constructor
    if(size1>size2)
    {
        numOfZeros = size1-size2;
    }
    else
    {
        numOfZeros = size2-size1;
    }
    for(int i=0;i<numOfZeros;i++)
    {
        if(size1>size2)
        {
            list2.push_front(zeroValue);
        }
        else
        {
            list1.push_front(zeroValue);
        }
    }
    SinglyLinkedList<int>* newList = sum_lists_helper(list1.get_head(),list2.get_head(), carry);
    if(carry)
    {
        newList->push_front(carry);
    }
    return newList;
}

void OptimalSolution::solve(int n1,int n2)
{
    take_input(n1,n2);
    list1.display();
    list2.display();
    SinglyLinkedList<int>* newList = sum_lists();
    newList->display();
}