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
        int mat[MAX_N][MAX_N];
        int n;
        virtual void rotateMatrix() = 0;
        void display();
    public:
        virtual void solve() = 0;
};

class NormalSolution: public Solution{
    private:
        void rotateMatrix();
        void rotatePoints(int r,int c);
    public:
        NormalSolution(int** mat,int n);
        void solve();
};

#endif