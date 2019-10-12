#include "solution.h"

/*
* Time Complexity : O(N*N)
* Space Complexity: O(1)
*/

OptimalSolution::OptimalSolution()
{
    animalShelter = new AnimalShelter();
}
OptimalSolution::~OptimalSolution()
{
    delete animalShelter;
}

void OptimalSolution::solve()
{
    Dog* d;
    Dog* dOldest;
    Dog* dOldest1;
    Cat* c;
    Cat* cOldest;
    Cat* cOldest1;
    dOldest = new Dog();
    animalShelter->enqueue(dOldest);
    dOldest1 = new Dog();
    animalShelter->enqueue(dOldest1);
    cOldest = new Cat();
    animalShelter->enqueue(cOldest);
    d = new Dog();
    animalShelter->enqueue(d);
    cOldest1 = new Cat();
    animalShelter->enqueue(cOldest1);
    d = new Dog();
    animalShelter->enqueue(d);
    c = new Cat();
    animalShelter->enqueue(c);

    Animal* a = animalShelter->dequeueAny();
    assert( a==dOldest );
    a = animalShelter->dequeueCat();
    assert(cOldest == a);
    a = animalShelter->dequeueDog();
    assert(a == dOldest1);
    std::cout<<"Success\n";
}