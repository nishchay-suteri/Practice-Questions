#include "solution.h"
/*
* Time Complexity : O(1)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
    this->graph = new MyGraph<int>(DIRECTED);   
}
OptimalSolution::~OptimalSolution()
{
    delete this->graph;
}

bool OptimalSolution::verify()
{
    bool result = false;
    result = graph->isPathExist(0,0);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(0,1);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(0,2);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(0,3);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(0,4);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(0,5);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(1,0);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(1,1);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(1,2);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(1,3);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(1,4);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(1,5);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(2,0);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(2,1);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(2,2);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(2,3);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(2,4);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(2,5);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(3,0);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(3,1);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(3,2);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(3,3);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(3,4);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(3,5);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(4,0);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(4,1);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(4,2);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(4,3);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(4,4);
    if(result == false)
    {
        return false;
    }
    result = graph->isPathExist(4,5);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(5,0);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(5,1);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(5,2);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(5,3);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(5,4);
    if(result == true)
    {
        return false;
    }
    result = graph->isPathExist(5,5);
    if(result == false)
    {
        return false;
    }
    return true;
}

void OptimalSolution::solve()
{
    graph->insert(0,1);
    graph->insert(0,4);
    graph->insert(0,5);
    graph->insert(1,3);
    graph->insert(1,4);
    graph->insert(2,1);
    graph->insert(3,2);
    graph->insert(3,4);
    bool result = verify();
    if(result)
    {
        std::cout<<"Passed\n";
    }
    else
    {
        std::cout<<"Failed\n";
    }
    

}