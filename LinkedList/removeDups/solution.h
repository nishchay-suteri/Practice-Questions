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
#include "linkedList.h"
#include<unordered_map>
#include<bitset>
#define MAX_ELEMENT (1000)

class Solution{
    protected:
        DoublyLinkedList<int> list;
        virtual void removeDups() = 0;
        void take_input(int n);
    public:
        virtual void solve(int n) = 0;
};

class BruteForceSolution: public Solution{
    private:
        void removeDups();
    public:
        BruteForceSolution();
        void solve(int n);
};

class SortSolution: public Solution{
    private:
        void removeDups();
    public:
        SortSolution();
        void solve(int n);
};


class HashMapSolution: public Solution{
    private:
        std::unordered_map<int,bool> m;
        void removeDups();
    public:
        HashMapSolution();
        void solve(int n);
};


class BitSetSolution: public Solution{
    private:
        std::bitset<MAX_ELEMENT> bSet;
        void removeDups();
    public:
        BitSetSolution();
        void solve(int n);
};

#endif