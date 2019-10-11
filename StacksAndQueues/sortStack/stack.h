#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<assert.h>

template<typename T>
class StackNodeBase{
    private:
        T data;
    public:
        StackNodeBase(T& d){
            this->data = d;
        }
        T& get_data(){
            return this->data;
        }
};

template<typename T>
class StackNode:public StackNodeBase<T>{
    private:
        StackNode<T>* next;
    public:
        StackNode(T& d):StackNodeBase<T>(d){
            this->next = NULL;
        }
        StackNode* get_next(){
            return next;
        }
        void set_next(StackNode* n){
            next = n;
        }
};

template<typename T>
class StackBase{
    public:
        virtual void push(T& d) = 0;
        virtual T pop() = 0;
        virtual T& peek() = 0;
        virtual bool isEmpty() = 0;
        virtual void display() = 0;
        virtual ~StackBase(){
        }
};

template<typename T>
class Stack:public StackBase<T>{
    private:
        StackNode<T>* top;
        uint size;
    public:
        Stack(){
            this->top = NULL;
            this->size = 0;
        }
        ~Stack(){
            StackNode<T>* prev = NULL;
            StackNode<T>* curr = top;
            while(curr){
                prev = curr;
                curr = curr->get_next();
                delete prev;
            }
        }
        void push(T& d){
            StackNode<T>* node = new StackNode<T>(d);
            if(this->top == NULL)
            {
                this->top = node;
            }
            else
            {
                node->set_next(this->top);
                this->top = node;
            }
            size++;
        }
        T pop(){
            assert(this->top != NULL);
            StackNode<T>* node = this->top;
            this->top = this->top->get_next();
            node->set_next(NULL);
            T data = node->get_data();
            delete node;
            size--;
            return data;
        }
        void display(){
            if(size == 0)
            {
                std::cout<<"Empty Stack\n";
                return;
            }
            StackNode<T>* itr = top;
            while(itr!=NULL){
                std::cout<<itr->get_data()<<" ";
                itr = itr->get_next();
            }
            std::cout<<"\n";
        }
        T& peek()
        {
            assert(this->top != NULL);
            return this->top->get_data();
        }
        bool isEmpty()
        {
            if(this->top == NULL)
            {
                return true;
            }
            return false;
        }
        uint get_size()
        {
            return size;
        }
};


#endif