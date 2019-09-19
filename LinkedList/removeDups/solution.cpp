#include "solution.h"

/*
* Note: for this problem, our BCR(Best Conceivable Time) is O(N) since we have to traverse every value
*/

void Solution::take_input(int n){
    int input;
    for(int i=0;i<n;i++){
        std::cin>>input;
        assert(input<= MAX_ELEMENT);
        list.push_back(input);
    }
}

BruteForceSolution::BruteForceSolution()
{
}

/*
* Time Complexity : O(n^2)
* Space Complexity: O(1)
*/

void BruteForceSolution::removeDups(){
    DoublyListNode<int>* curr = list.get_head();
    DoublyListNode<int>* p_itr = NULL;
    DoublyListNode<int>* itr = curr;
    while(curr!=NULL){
        itr = curr->get_next();
        p_itr = curr;
        while(itr!=NULL){
            p_itr = itr;
            itr = itr->get_next();
            if(p_itr->get_data() == curr->get_data()){
                list.remove_node(p_itr);
            }
        }
        curr = curr->get_next();
    }
}

void BruteForceSolution::solve(int n)
{
   take_input(n);
   removeDups();
   list.display();
}


SortSolution::SortSolution()
{
}

/*
* Time Complexity : O(nlog2(n))
* Space Complexity: O(1)
*/

void SortSolution::removeDups(){
    list.set_head(list.sort(list.get_head()));
    list.update_tail();
    list.display();
    DoublyListNode<int>* curr = list.get_head();
    DoublyListNode<int>* itr = curr->get_next();
    DoublyListNode<int>* temp;
    while(curr)
    {
        itr = curr->get_next();
        while(itr && itr->get_data() == curr->get_data())
        {
            temp = itr;
            itr = itr->get_next();
            list.remove_node(temp);
        }
        curr = itr;
    }
}

void SortSolution::solve(int n)
{
    take_input(n);
    removeDups();
    list.display();
}

HashMapSolution::HashMapSolution()
{
}

/*
* Time Complexity : O(N)
* Space Complexity: O(N)
*/

void HashMapSolution::removeDups(){
    DoublyListNode<int>* itr = list.get_head();
    DoublyListNode<int>* nodeToDelete = NULL;
    while(itr)
    {
        if(m.find(itr->get_data()) != m.end())
        {
            nodeToDelete = itr;
            itr=itr->get_next();
            list.remove_node(nodeToDelete);
        }
        else
        {
            m[itr->get_data()] = true;
            itr = itr->get_next();
        }
    }
}

void HashMapSolution::solve(int n)
{
    take_input(n);
    removeDups();
    list.display();
}

/*
* Time Complexity : O(N)
* Space Complexity: O(N) // will be 8 times less than the UnOrdered Map Solution
* BUT, We've to assume that maximum element will be <= MAX_ELEMENT,
* since for using bitset, we have to know the number of bits we need to assign,
* and our assumption will help us to assign MAX_ELEMENT bits.
* We can say that our space complexity in O(1).
*/

BitSetSolution::BitSetSolution()
{

}
void BitSetSolution::removeDups(){
    DoublyListNode<int>* itr = list.get_head();
    DoublyListNode<int>* nodeToDelete = NULL;
    while(itr)
    {
        if(bSet.test(itr->get_data()))
        {
            nodeToDelete = itr;
            itr=itr->get_next();
            list.remove_node(nodeToDelete);
        }
        else
        {
            bSet.set(itr->get_data());
            itr = itr->get_next();
        }
    }
}

void BitSetSolution::solve(int n)
{
    take_input(n);
    removeDups();
    list.display();
}
