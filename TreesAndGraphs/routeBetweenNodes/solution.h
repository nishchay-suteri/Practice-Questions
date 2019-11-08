#ifndef SOLUTION_H
#define SOLUTION_H


/*
* Solution is an abstract class(containing pure virtual function)
* We can't make the object of an abstract class.But, abstract class can have constructors(to initialize its variables)
* Pure Virtual functions are used when we don't know how to implement some functionality in base class,
* but we know all the derived class will have that functionality.
* Eg. Class Shape has some function draw(), we don't know how to draw some shape,
* but we know all the derived class like Circle, square will have draw function and
* We know how to draw these derived classes shapes
* Virtual function will be used for runtime polymorphism
* Runtime polymorphism means at the runtime only, computer will see the object
* containing the pointer, and based on that object, the function will be called,(It is called runtime Binding)
* obviously if the function is virtual, that's where the runtime polymorphism/  term comes
* Compile time binding is when compiler binds some function(non virtual) to the class based on the pointer itself
* One more thing, if a function is pure virtual, then all of the derived class MUST Implement that function
* Another  thing, We can't access the private members of base class(even derived class can't access)
*/
#include "graphs.h"

class Solution{
    public:
        virtual void solve() = 0;
};

template<typename T>
class MyGraph:public ListGraph<T>
{   
    private:
        bool isPathExistHelper(T& src,T& dest)
        {
            Queue<T> q;
            this->vis.clear();
            q.add(src);
            this->vis[src] = true;
            while(!q.isEmpty())
            {
                T vertex = q.remove();
                if(vertex == dest)
                {
                    return true;
                }
                std::vector<T>& neighbours = this->adjList[vertex];
                for(int i=0;i<neighbours.size();i++)
                {
                    if(this->vis.find(neighbours[i]) == this->vis.end())
                    {
                        q.add(neighbours[i]);
                        this->vis[neighbours[i]] = true;
                    }
                }
            }
            return false;
        }
    public:
        bool isPathExist(T node1,T node2)
        {
            // if(isPathExistHelper(node1,node2) || isPathExistHelper(node2,node1))
            if(isPathExistHelper(node1,node2))
            {
                return true;
            }
            return false;
        }
        MyGraph(GraphType t):
        ListGraph<T>(t)
        {
            
        }
};

class OptimalSolution: public Solution{
    private:
        MyGraph<int>* graph;
        bool verify();
    public:
        OptimalSolution();
        ~OptimalSolution();
        void solve();
};

#endif