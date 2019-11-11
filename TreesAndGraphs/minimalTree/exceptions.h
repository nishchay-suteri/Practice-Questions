#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

class NotPresentException: public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Element Not Found\n";
        }
};
/*
const char * - is the return type of the function.
what - is the name of the function.
() - the (empty) parameter list. The method takes no parameters.
const - declares this to be a const function (in general, this means it should not change the state of the object from which the function is called).
throw () - declares that the function throws no exceptions. It  is an exception specification which prevents function(what()) from throwing any exceptions.
NOTE: We can remove const throw()
*/

class NullNodeException: public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Node is NULL\n";
        }
};

class EmptyHeapException : public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Heap is empty\n";
        }
};

class InvalidInputException: public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Invalid Input\n";
        }
};

class BSTCreateMinimalTreeException: public std::exception
{
    public:
        const char* what() const throw()
        {
            return "Create Minimal Tree Invalid size exception\n";
        }
};

#endif