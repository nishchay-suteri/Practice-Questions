#include "solution.h"
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<bitset>

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
    
}

void SortSolution::solve(int n)
{
//     take_input(n);
// //    removeDups();
//     list.set_head(list.sort(list.get_head()));
//    list.display();
}

HashMapSolution::HashMapSolution()
{
}

/*
* Time Complexity : O(N)
* Space Complexity: O(N)
*/

void HashMapSolution::removeDups(){
    // std::unordered_map<char,bool> m;
    // for(int i=0;i<input.size();i++)
    // {
    //     if(m.find(input[i]) != m.end())
    //     {
    //         return false;
    //     }
    //     m[input[i]] = true;
    // }
    // return true;
}

void HashMapSolution::solve(int n)
{
    
}
