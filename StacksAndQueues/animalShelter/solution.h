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
#include "queue.h"

class Solution{
    public:
        virtual void solve() = 0;
};

enum AnimalType{
    DEFAULT = 0,
    DOG,
    CAT
};

class Animal{
    protected:
        AnimalType animalType;
        int timeStamp;
        // other properties of animals
    public:
        Animal(AnimalType t)
        {
            animalType = t;
        }
        AnimalType getType()
        {
            return animalType;
        }
        void setTimeStamp(int t)
        {
            timeStamp = t;
        }
        int getTimeStamp()
        {
            return timeStamp;
        }
        // other methods of Animals.. Mainly pure virtual since we should define the properties of specific animals in derived classes.
        // Also because we don't want to create the object of animal
};

class Dog:public Animal{
    public:
        Dog():Animal(DOG){

        }
        // other methods of dog class
};

class Cat:public Animal{
    public:
        Cat():Animal(CAT){
            
        }
        // other methods of cat class
};

class AnimalShelter{
    Queue<Animal* > dogList;
    Queue<Animal* > catList;
    int timeStamp;
    public:
        AnimalShelter()
        {
            timeStamp = 0;
        }
        void enqueue(Animal* animal)
        {
            animal->setTimeStamp(timeStamp);
            timeStamp++;

            AnimalType t = animal->getType();
            switch (t)
            {
            case DOG:
                dogList.add(animal);
                break;
            case CAT:
                catList.add(animal);
                break;
            default:
                break;
            }
        }
        Animal* dequeueDog()
        {
            if(dogList.isEmpty())
            {
                std::cout<<"No Dogs to remove.. Add the dogs first.. :)\n";
                return NULL;
            }
            return dogList.remove();
        }
        Animal* dequeueCat()
        {
            if(catList.isEmpty())
            {
                std::cout<<"No Cats to remove.. Add the cats first.. :)\n";
                return NULL;
            }
            return catList.remove();
        }
        Animal* dequeueAny()
        {
            if(dogList.isEmpty() && catList.isEmpty())
            {
                // throw some exception
                assert(0);
            }
            if(dogList.isEmpty())
            {
                return catList.remove();
            }
            if(catList.isEmpty())
            {
                return dogList.remove();
            }
            Animal* dog = dogList.peek();
            Animal* cat = catList.peek();
            if(dog->getTimeStamp() < cat->getTimeStamp())
            {
                return dogList.remove();
            }
            else
            {
                return catList.remove();
            }
            
        }
};

class OptimalSolution: public Solution{
    private:
        AnimalShelter* animalShelter;
    public:
        OptimalSolution();
        ~OptimalSolution();
        void solve();
};

#endif