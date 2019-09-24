#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<assert.h>

template<typename T>
class ListNode{
    protected:
        T data;
    public:
        ListNode(T& d){
            this->data = d;
        }
        T& get_data(){
            return this->data;
        }
};

template<typename T>
class SinglyListNode:public ListNode<T>{
    private:
        SinglyListNode<T>* next;
    public:
        SinglyListNode(T& d):ListNode<T>(d){
            this->next = NULL;
        }
        SinglyListNode* get_next(){
            return next;
        }
        void set_next(SinglyListNode* n){
            next = n;
        }
        void set_data(T& d)
        {
            this->data = d;
        }
};

template<typename T>
class DoublyListNode:public ListNode<T>{
    private:
        DoublyListNode<T>* next;
        DoublyListNode<T>* prev;
    public:
        DoublyListNode(T& d):ListNode<T>(d){
            this->next = NULL;
            this->prev = NULL;
        }
        DoublyListNode* get_next(){
            return next;
        }
        DoublyListNode* get_prev(){
            return prev;
        }
        void set_next(DoublyListNode* n){
            next = n;
        }
        void set_prev(DoublyListNode* p){
            prev = p;
        }
};

template<typename T>
class LinkedList{
    public:
        virtual void push_back(T& d) = 0;
        virtual void pop_back() = 0;
        // virtual void _push_front() = 0;
        // virtual void _pop_front() = 0;
        virtual void display() = 0;
        virtual ~LinkedList(){
        }
};

template<typename T>
class SinglyLinkedList:public LinkedList<T>{
    private:
        SinglyListNode<T>* head;
        SinglyListNode<T>* tail;
        int size;
    public:
        SinglyLinkedList(){
            this->head = NULL;
            this->tail = NULL;
            size = 0;
        }
        ~SinglyLinkedList(){
            SinglyListNode<T>* prev = NULL;
            SinglyListNode<T>* curr = head;
            while(curr){
                prev = curr;
                curr = curr->get_next();
                delete prev;
            }
        }
        void push_back(T& d){
            SinglyListNode<T>* node = new SinglyListNode<T>(d);
            if(this->tail == NULL){
                this->head = node;
                this->tail = node;
            }
            else
            {
                this->tail->set_next(node);
                this->tail = node;
            }
            size++;
        }
        void push_back(SinglyListNode<T>* node)
        {
            if(this->tail == NULL){
                this->head = node;
                this->tail = node;
            }
            else
            {
                this->tail->set_next(node);
                this->tail = node;
            }
            size++;
        }
        void push_front(SinglyListNode<T>* node)
        {
            if(this->head == NULL){
                this->head = node;
                this->tail = node;
            }
            else
            {
                node->set_next(head);
                head = node;
            }
            size++;
        }
        void push_front(T& d)
        {
            SinglyListNode<T>* node = new SinglyListNode<T>(d);
            if(this->head == NULL){
                this->head = node;
                this->tail = node;
            }
            else
            {
                node->set_next(head);
                head = node;
            }
            size++;
        }
        
        void pop_back(){
            if(this->tail == NULL)
            {
                return;
            }
            if(this->head == this->tail)
            {
                SinglyListNode<T>* n = this->tail;
                this->head = NULL;
                this->tail = NULL;
                delete n;
                size--;
                return;
            }
            SinglyListNode<T>* itr = this->head;
            while(itr->get_next() != this->tail)
            {
                itr = itr->get_next();
            }
            itr->set_next(NULL);
            delete this->tail;
            this->tail = itr;
            size--;
        }
        void display(){
            SinglyListNode<T>* itr = head;
            while(itr!=NULL){
                std::cout<<itr->get_data()<<" ";
                itr = itr->get_next();
            }
            std::cout<<"\n";
        }
        SinglyListNode<T>* get_head(){
            return this->head;
        }
        SinglyListNode<T>* get_tail(){
            return this->tail;
        }
        void set_head(SinglyListNode<T>* n)
        {
            this->head = n;
        }
        int get_size()
        {
            return size;
        }
        
};

template<typename T>
class DoublyLinkedList:public LinkedList<T>{
    private:
        DoublyListNode<T>* head;
        DoublyListNode<T>* tail;

        DoublyListNode<T>* get_mid(DoublyListNode<T>* node){
            DoublyListNode<T>* slowPtr = node;
            DoublyListNode<T>* fastPtr = node->get_next();// since for 2 nodes, we should return fitrst node
            while (fastPtr && fastPtr->get_next())
            {
                slowPtr = slowPtr->get_next();
                fastPtr = fastPtr->get_next()->get_next();
            }
            return slowPtr;
        }

        DoublyListNode<T>* merge(DoublyListNode<T>* node1,DoublyListNode<T>* node2)
        {
            if(node1 == NULL)
            {
                return node2;
            }
            if(node2 == NULL)
            {
                return node1;
            }
            DoublyListNode<T>* result = NULL;
            if(node1->get_data() <= node2->get_data())
            {
                result = node1;
                result->set_next(merge(node1->get_next(),node2));
                result->get_next()->set_prev(result);
            }
            else
            {
                result = node2;
                result->set_next(merge(node1,node2->get_next()));
                result->get_next()->set_prev(result);
            }
            return result;
        }
    public:
        DoublyLinkedList(){
            this->head = NULL;
            this->tail = NULL;
        }
        ~DoublyLinkedList(){
            DoublyListNode<T>* prev = NULL;
            DoublyListNode<T>* curr = head;
            while(curr){
                prev = curr;
                curr = curr->get_next();
                delete prev;
            }
        }
        void push_back(T& d){
            DoublyListNode<T>* node = new DoublyListNode<T>(d);
            if(this->tail == NULL){
                this->head = node;
                this->tail = node;
            }
            else
            {
                this->tail->set_next(node);
                node->set_prev(this->tail);
                this->tail = node;
            }
        }

        void pop_back(){
            if(this->tail == NULL)
            {
                return;
            }
            DoublyListNode<T>* n = this->tail;
            if(this->head == this->tail)
            {
                this->head = NULL;
                this->tail = NULL;
            }
            else
            {
                this->tail = n->get_prev();
                n->get_prev()->set_next(NULL);
                n->set_prev(NULL);
            }
            delete n;
        }
        void remove_node(DoublyListNode<T>* node){
            if(node == this->head && node == this->tail){
                this->head = NULL;
                this->tail = NULL;
                delete node;
            }
            else if(node == this->head){
                this->head = node->get_next();
                this->head->set_prev(NULL);
                node->set_next(NULL);
                delete node;
            }
            else if(node == this->tail)
            {
                this->tail = node->get_prev();
                this->tail->set_next(NULL);
                node->set_prev(NULL);
                delete node;
            }
            else
            {
                node->get_prev()->set_next(node->get_next());
                node->get_next()->set_prev(node->get_prev());
                node->set_next(NULL);
                node->set_prev(NULL);
                delete node;
            }
            
        }
        DoublyListNode<T>* get_head(){
            return this->head;
        }
        DoublyListNode<T>* get_tail(){
            return this->tail;
        }
        void set_head(DoublyListNode<T>* n)
        {
            this->head = n;
        }

        DoublyListNode<T>* sort(DoublyListNode<T>* node)
        {
            if(node == NULL || node->get_next() == NULL)
            {
                return node;
            }
            DoublyListNode<T>* middle = get_mid(node);
            DoublyListNode<T>* secondListHead = middle->get_next();
            middle->get_next()->set_prev(NULL);
            middle->set_next(NULL);
            node = sort(node);
            secondListHead = sort(secondListHead);
            DoublyListNode<T>* finalHead = merge(node,secondListHead);
            return finalHead;
        }
        void update_tail()
        {
            assert(this->head!=NULL);
            DoublyListNode<T>* itr = this->head;
            while(itr->get_next())
            {
                itr = itr->get_next();
            }
            this->tail = itr;
        }
        

        void display(){
            DoublyListNode<T>* itr = head;
            while(itr!=NULL){
                std::cout<<itr->get_data()<<" ";
                itr = itr->get_next();
            }
            std::cout<<"\n";
        }
};

#endif