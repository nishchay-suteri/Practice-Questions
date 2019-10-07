#include "solution.h"

/*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
}

void OptimalSolution::push(int val)
{
    stack.push(val);
    if(!minStack.isEmpty())
    {
        if(minStack.peek() > val)
        {
            minStack.push(val);
        }
    }
    else
    {
        minStack.push(val);
    }
}

int OptimalSolution::pop()
{
    assert(!stack.isEmpty());
    assert(!minStack.isEmpty());
    if(stack.peek() == minStack.peek())
    {
        minStack.pop();
    }
    return stack.pop();
}

int OptimalSolution::get_min()
{
    assert(!minStack.isEmpty());
    return minStack.peek();
}

void OptimalSolution::solve()
{
    push(5);
    std::cout<<"Stack is:-\n";
    stack.display();
    std::cout<<"min is:-\n";
    std::cout<<get_min()<<"\n";
    std::cout<<"\n";
    push(6);
    std::cout<<"Stack is:-\n";
    stack.display();
    std::cout<<"min is:-\n";
    std::cout<<get_min()<<"\n";
    std::cout<<"\n";
    push(3);
    std::cout<<"Stack is:-\n";
    stack.display();
    std::cout<<"min is:-\n";
    std::cout<<get_min()<<"\n";
    std::cout<<"\n";
    push(7);
    std::cout<<"Stack is:-\n";
    stack.display();
    std::cout<<"min is:-\n";
    std::cout<<get_min()<<"\n";
    std::cout<<"\n";
    pop();
    std::cout<<"Stack is:-\n";
    stack.display();
    std::cout<<"min is:-\n";
    std::cout<<get_min()<<"\n";
    std::cout<<"\n";
    pop();
    std::cout<<"Stack is:-\n";
    stack.display();
    std::cout<<"min is:-\n";
    std::cout<<get_min()<<"\n";
    std::cout<<"\n";
}