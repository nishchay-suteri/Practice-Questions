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

Result* OptimalSolution::palindrome_helper(SinglyListNode<int>* node,int length)
{
    assert(node!=NULL);
    if(length == 0)
    {
        return new Result(node,true);
    }
    if(length == 1)
    {
        return new Result(node->get_next(),true);
    }
    Result* res = palindrome_helper(node->get_next(),length-2);
    assert(res->last_node != NULL);
    if(res->result == false)
    {
        return res;
    }
    res->result = (node->get_data() == res->last_node->get_data());
    res->last_node = res->last_node->get_next();
    return res;
}


bool OptimalSolution::palindrome()
{
    int len = list.get_size();
    Result* result = palindrome_helper(list.get_head(),len);
    return result->result;
}

void OptimalSolution::solve(int n)
{
    take_input(n);
    list.display();
    bool result = palindrome();
    if(result)
    {
        std::cout<<"YES!!\n";
    }
    else
    {
        std::cout<<"NO\n";
    }
    
}