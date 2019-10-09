#include "solution.h"

/*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution(int t)
{
    listOfStacks.clear();
    threshold = t;
    listOfStacks.push_back(new Stack<int>());
    activeStack = 0;
}
OptimalSolution::~OptimalSolution()
{
    for(int i=0;i<listOfStacks.size();i++)
    {
        delete listOfStacks[i];
    }
}

void OptimalSolution::display()
{
    for(int i=0;i<listOfStacks.size();i++)
    {
        std::cout<<"Stack "<<(i+1)<<":-\n";
        listOfStacks[i]->display();
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

void OptimalSolution::push(int val)
{
    if(listOfStacks[activeStack]->get_size() >= threshold)
    {
        listOfStacks.push_back(new Stack<int>());
        activeStack++;
    }
    listOfStacks[activeStack]->push(val);
}

int OptimalSolution::pop()
{
    int val =  listOfStacks[activeStack]->pop();
    if(listOfStacks[activeStack]->get_size() == 0)
    {
        delete listOfStacks[activeStack];
        listOfStacks.pop_back();
        activeStack--;
    }
    return val;
}

int OptimalSolution::popAt(int index)
{
    assert(index < listOfStacks.size());
    assert(index>=0);
    int val;
    if(listOfStacks[index]->get_size() == 0)
    {
        std::cout<<"Empty Stack\n";
        val = INVALID_VALUE;
    }
    else
    {
        int val = listOfStacks[index]->pop();
    }
    
    return val;
}

void OptimalSolution::solve()
{
    push(5);
    display();
    push(1);
    display();
    push(2);
    display();
    push(4);
    display();
    push(3);
    display();
    push(6);
    display();
    pop();
    display();
    popAt(0);
    display();
    push(9);
    display();
}