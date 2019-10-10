#include "solution.h"

/*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
    
}
OptimalSolution::~OptimalSolution()
{
}


void OptimalSolution::solve()
{
    int t,val;
    bool bValue;
    std::cout<<"Let's start queue operations:-\n";
    while(true)
    {
        std::cout<<"1. Add\n";
        std::cout<<"2. Remove\n";
        std::cout<<"3. isEmpty()\n";
        std::cout<<"4. Peek\n";
        std::cout<<"5. Exit\n";
        std::cin>>t;
        switch (t)
        {
        case 1:
            std::cin>>val;
            myQ.add(val);
            q.add(val);
            break;
        case 2:
            val = myQ.remove();
            assert(val == q.remove());
            break;
        case 3:
            bValue = myQ.isEmpty();
            assert(bValue == q.isEmpty());
            break;
        case 4:
            val = myQ.peek();
            assert(val == q.peek());
            break;
        case 5:
            bValue = verify();
            if(bValue)
            {
                std::cout<<"Verification Success\n";
            }
            else
            {
                std::cout<<"Some Error\n";
                assert(0);
            }
            return;
            break;
        default:
            std::cout<<"Please enter the correct value\n";
            break;
        }
    }
}