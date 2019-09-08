#ifndef SOLUTION_H
#define SOLUTION_H

#define MAX_N (256)

/*
* Solution is an abstract class(containing pure virtual function)
* We can't make the object of an abstract class.But, abstract class can have constructors(to initialize its variables)
* Pure Virtual functions are used when we don't know how to implement some functionality in base class,
* but we know all the derived class will have that functionality.
* Eg. Class Shape has some function draw(), we don't know how to draw some shape,
* but we know all the derived class like Circle, square will have draw function and
* we know how to draw these derived classes shapes
* Virtual function will be used for runtime polymorphism
* Runtime polymorphism means at the runtime only, computer will see the object
* containing the pointer, and based on that object, the function will be called,(It is called runtime Binding)
* obviously if the function is virtual, that's where the runtime polymorphism/  term comes
* Compile time binding is when compiler binds some function(non virtual) to the class based on the pointer itself
* One more thing, if a function is pure virtual, then all of the derived class MUST Implement that function
* Another  thing, We can't access the private members of base class(even derived class can't access)
*/

#include<string>

class Solution{
    protected:
        std::string input1;
        std::string input2;
        virtual bool checkPermutation() = 0;
    public:
        virtual void solve() = 0;
        Solution(std::string& s1, std::string& s2);
};

class SortSolution: public Solution{
    private:
        bool checkPermutation();
    public:
        SortSolution(std::string& s1,std::string& s2);
        void solve();
};


class HashMapSolutionNotOptimised: public Solution{
    private:
        bool checkPermutation();
        int hMapA[MAX_N];
        int hMapB[MAX_N];
    public:
        HashMapSolutionNotOptimised(std::string& s1, std::string& s2);
        void solve();
};

class HashMapSolutionSpaceOptimised: public Solution{
    private:
        bool checkPermutation();
        int hMap[MAX_N];
    public:
        HashMapSolutionSpaceOptimised(std::string& s1, std::string& s2);
        void solve();
};

#endif