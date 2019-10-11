#include "solution.h"

void Solution::take_input(){
    int n;
    std::cin>>n;
    int val;
    for(int i=0;i<n;i++)
    {
        std::cin>>val;
        s.push(val);
    }
}

/*
* Time Complexity : O(N*N)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
}
OptimalSolution::~OptimalSolution()
{
}

void OptimalSolution::sort()
{
    Stack<int> tempStack;
    int tempVar;
    while(!s.isEmpty())
    {
        tempVar = s.pop();
        while(!tempStack.isEmpty() && tempStack.peek() > tempVar)
        {
            int t = tempStack.pop();
            s.push(t);
        }
        tempStack.push(tempVar);
    }
    while(!tempStack.isEmpty())
    {
        tempVar = tempStack.pop();
        s.push(tempVar);
    }
}
void OptimalSolution::solve()
{
    take_input();
    std::cout<<"Stack before sorting:-\n";
    s.display();
    sort();
    std::cout<<"Stack after sorting:-\n";
    s.display();
}