#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include <assert.h>

template<typename T>
class QueueNodeBase{
    private:
        T data;
    public:
        QueueNodeBase(T& d){
            this->data = d;
        }
        T& get_data(){
            return this->data;
        }
};

template<typename T>
class QueueNode:public QueueNodeBase<T>{
    private:
        QueueNode<T>* next;
    public:
        QueueNode(T& d):QueueNodeBase<T>(d){
            this->next = NULL;
        }
        QueueNode* get_next(){
            return next;
        }
        void set_next(QueueNode* n){
            next = n;
        }
};

template<typename T>
class QueueBase{
    public:
        virtual void add(T& d) = 0;
        virtual T remove() = 0;
        virtual T& peek() = 0;
        virtual bool isEmpty() = 0;
        virtual void display() = 0;
        virtual ~QueueBase(){
        }
};

template<typename T>
class Queue:public QueueBase<T>{
    private:
        QueueNode<T>* head;
        QueueNode<T>* tail;
    public:
        Queue(){
            this->head = NULL;
            this->tail = NULL;
        }
        ~Queue(){
            QueueNode<T>* prev = NULL;
            QueueNode<T>* curr = head;
            while(curr){
                prev = curr;
                curr = curr->get_next();
                delete prev;
            }
        }
        void add(T& d){
            QueueNode<T>* node = new QueueNode<T>(d);
            if(this->tail == NULL){
                this->head = node;
                this->tail = node;
            }
            else
            {
                this->tail->set_next(node);
                this->tail = node;
            }
        }
        T remove(){
            assert(this->head != NULL);
            T data;
            if(this->head == this->tail)
            {
                QueueNode<T>* n = this->head;
                this->head = NULL;
                this->tail = NULL;
                data = n->get_data();
                delete n;
            }
            else
            {
                QueueNode<T>* n = this->head;
                this->head = n->get_next();
                n->set_next(NULL);
                data = n->get_data();
                delete n;
            }
            return data;
        }
        void display(){
            QueueNode<T>* itr = head;
            while(itr!=NULL){
                std::cout<<itr->get_data()<<" ";
                itr = itr->get_next();
            }
            std::cout<<"\n";
        }
        T& peek()
        {
            assert(this->head != NULL);
            return this->head->get_data();
        }
        bool isEmpty()
        {
            if(this->tail == NULL)
            {
                return true;
            }
            return false;
        }
};

#endif