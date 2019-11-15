#ifndef BST_H
#define BST_H

#include<iostream>
#include<stdlib.h>
#include<assert.h>
#include "exceptions.h"
#include<limits.h>
#include<list>
#include<queue>
#define MAX_DEPTH (100)
#define DEBUG (0)

template<typename T>
class TreeNode{
    private:
        T data;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
    public:
        TreeNode(T& d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
        T& get_data(){
            return this->data;
        }
        void set_data(T& d)
        {
            this->data = d;
        }
        TreeNode* get_left()
        {
            return this->left;
        }
        void set_left(TreeNode* node)
        {
            this->left = node;
        }
        TreeNode* get_right()
        {
            return this->right;
        }
        void set_right(TreeNode* node)
        {
            this->right = node;
        }
        TreeNode* get_parent()
        {
            return this->parent;
        }
        void set_parent(TreeNode* node)
        {
            this->parent = node;
        }
        void reset()
        {
            this->left = NULL;
            this->right = NULL;
            this->parent = NULL;
        }
};

enum DisplayType{
    INORDER = 0,
    PREORDER,
    POSTORDER
};

// abstract class for Tree
template<typename T>
class Tree{
    protected:
        int size;
        TreeNode<T>* root;
        virtual void display(DisplayType t) = 0;
    public:
        Tree()
        {
            this->root = NULL;
            this->size = 0;
        }
        virtual void insert(T& d) = 0;
        virtual bool remove(T& d) = 0;
        virtual bool search(T& d) = 0;
        virtual ~Tree(){
        }
        bool isEmpty()
        {
            if(size == 0)
            {
                return true;
            }
            return false;
        }
        int get_size()
        {
            return size;
        }
};

template<typename T>
class BinarySearchTree:public Tree<T>{
    private:
        std::list<TreeNode<T>*> bfsList[MAX_DEPTH];
        std::list<TreeNode<T>*> dfsList[MAX_DEPTH];
        bool compare(int i)
        {
            std::list<TreeNode<T>* >& bfs = bfsList[i];
            std::list<TreeNode<T>* >& dfs = dfsList[i];
            if(bfs.size() != dfs.size())
            {
                return false;
            }
            typename std::list<TreeNode<T>* >::iterator itrBfs = bfs.begin();
            typename std::list<TreeNode<T>* >::iterator itrDfs = dfs.begin();
            while(itrBfs!=bfs.end())
            {
                if((*itrBfs)!=(*itrDfs))
                {
                    return false;
                }
                itrBfs++;
                itrDfs++;
            }
            return true;
        }
        void _inorder(TreeNode<T>* node)
        {
            if(node == NULL)
            {
                return;
            }
            _inorder(node->get_left());
            std::cout<<node->get_data()<<" ";
            _inorder(node->get_right());
        }
        void display(DisplayType t)
        {
            switch (t)
            {
            case INORDER:
                _inorder(this->root);
                std::cout<<"\n";
                break;
            
            default:
                std::cout<<"Not an inorder display\n";
                break;
            }
        }
        TreeNode<T>* _insert(TreeNode<T>* node, T& val)
        {
            if(node == NULL)
            {
                node = new TreeNode<T>(val);
                return node;
            }
            else
            {
                if(node->get_data() >= val)
                {
                    node->set_left(_insert(node->get_left(),val));
                    node->get_left()->set_parent(node);
                }
                else
                {
                    node->set_right(_insert(node->get_right(),val));
                    node->get_right()->set_parent(node);
                }
                return node;
            }
        }
        TreeNode<T>* _search(TreeNode<T>* node,T& val)
        {
            if(node == NULL)
            {
                return NULL;
            }
            if(node->get_data() == val)
            {
                return node;
            }
            else
            {
                if(node->get_data() < val)
                {
                    return _search(node->get_right(),val);
                }
                else
                {
                    return _search(node->get_left(),val);
                }
                
            }
            
        }
        TreeNode<T>* _remove(TreeNode<T>* node,T& val)
        {
            if(node == NULL)
            {
                throw NotPresentException();
            }
            if(node->get_data() < val)
            {
                node->set_right(_remove(node->get_right(),val));
                return node;
            }
            else if(node->get_data() > val)
            {
                node->set_left(_remove(node->get_left(),val));
                return node;
            }
            else
            {
                // Found the node
                if(node->get_left() == NULL && node->get_right() == NULL)
                {
                    node->reset();
                    delete node;
                    return NULL;
                }
                else if(node->get_left() == NULL)
                {
                    TreeNode<T>* n = node->get_right();
                    n->set_parent(node->get_parent());
                    node->reset();
                    delete node;
                    return n;
                }
                else if(node->get_right() == NULL)
                {
                    TreeNode<T>* n = node->get_left();
                    n->set_parent(node->get_parent());
                    node->reset();
                    delete node;
                    return n;
                }
                else
                {
                    TreeNode<T>* maxNode;
                    try
                    {
                        maxNode = get_max_node(node->get_left());
                    }
                    catch(const std::exception& e)
                    {
                        std::cerr << e.what() << '\n';
                        assert(0);
                    }
                    node->set_data(maxNode->get_data());
                    node->set_left(_remove(node->get_left(),val));
                    return node;
                }
                
            }
            
        }
        TreeNode<T>* get_max_node(TreeNode<T>* node)
        {
            if(node == NULL)
            {
                throw NullNodeException();
            }
            while(node->get_right())
            {
                node = node->get_right();
            }
            return node;
        }
        void deleteTree(TreeNode<T>* node) // post order
        {
            if(node == NULL)
            {
                return;
            }
            deleteTree(node->get_left());
            deleteTree(node->get_right());
            node->reset();
            delete node;
        }
        TreeNode<T>* createMinimalTreeHelper(T* arr,int start,int end, TreeNode<T>* parent)
        {
            if(start>end)
            {
                return NULL;
            }
            if(start == end)
            {
                TreeNode<T>* node = new TreeNode<T>(arr[start]);
                node->set_parent(parent);
                this->size++;
                return node;
            }
            int mid = (start+end)/2;
            TreeNode<T>* node = new TreeNode<T>(arr[mid]);
            node->set_left(createMinimalTreeHelper(arr,start,mid-1,node));
            node->set_right(createMinimalTreeHelper(arr,mid+1,end,node));
            node->set_parent(parent);
            this->size++;
            return node;
        }
        void _listOfDepthsDFS(TreeNode<T>* node,int depth){
            if(node == NULL)
            {
                return;
            }
            assert(depth < MAX_DEPTH);
            dfsList[depth].push_back(node);
            _listOfDepthsDFS(node->get_left(),depth+1);
            _listOfDepthsDFS(node->get_right(),depth+1);

        }
        void _listOfDepthsBFS(TreeNode<T>* node){
            std::queue<TreeNode<T>* > q;
            int depth = 0;
            q.push(node);
            q.push(NULL);
            while(!q.empty())
            {
                TreeNode<T>* n = q.front();
                q.pop();
                if(n!=NULL)
                {
                    bfsList[depth].push_back(n);
                    if(n->get_left())
                    {
                        q.push(n->get_left());
                    }
                    if(n->get_right())
                    {
                        q.push(n->get_right());
                    }
                }
                else
                {
                    if(q.empty())
                    {
                        break;
                    }
                    depth++;
                    assert(depth < MAX_DEPTH);
                    q.push(NULL);
                }
            }
        }
        void display_bfs(){
            for(int i=0;i<MAX_DEPTH;i++)
            {
                if(bfsList[i].size() != 0)
                {
                    std::cout<<"Depth: "<<i<<"\n";
                    std::list<TreeNode<T>* >& bfs = bfsList[i];
                    typename std::list<TreeNode<T>* >::iterator itrBfs = bfs.begin();
                    while(itrBfs!=bfs.end())
                    {
                        std::cout<<(*itrBfs)->get_data()<<" ";
                        itrBfs++;
                    }
                    std::cout<<"\n";
                }
            }
        }
        void display_dfs(){
            for(int i=0;i<MAX_DEPTH;i++)
            {
                if(dfsList[i].size() != 0)
                {
                    std::cout<<"Depth: "<<i<<"\n";
                    std::list<TreeNode<T>* >& dfs = dfsList[i];
                    typename std::list<TreeNode<T>* >::iterator itrDfs = dfs.begin();
                    while(itrDfs!=dfs.end())
                    {
                        std::cout<<(*itrDfs)->get_data()<<" ";
                        itrDfs++;
                    }
                    std::cout<<"\n";
                }
            }
        }
        bool verify(){
#if DEBUG
            std::cout<<"BFS:-\n";
            display_bfs();
            std::cout<<"DFS:-\n";
            display_dfs();
#endif
            for(int i=0;i<MAX_DEPTH;i++)
            {
                if(bfsList[i].size() != dfsList[i].size())
                {
                    return false;
                }
                if(bfsList[i].size()!=0 && !compare(i))
                {
                    return false;
                }
            }
            return true;
        }

    public:
        BinarySearchTree():Tree<T>(){
        }
        ~BinarySearchTree(){
            deleteTree(this->root);
            this->root = NULL;
        }
        void insert(T& val){
            this->root = _insert(this->root,val);
            this->size++;
        }
        bool remove(T& val){
            try
            {
                this->root = _remove(this->root,val);
                this->size--;
                return true;
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
                return false;
            }
            
        }
        void inOrderDisplay(){
            display(INORDER);
        }
        bool search(T& val)
        {
            if(_search(this->root,val) == NULL)
            {
                return false;
            }
            return true;
        }
        T get_max()
        {
            try
            {
                TreeNode<T>* node = get_max_node(this->root);
                return node->get_data();
            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
                return INT_MIN;
            }
        }
        void createMinimalTree(int* arr,int n)
        {
            this->root = createMinimalTreeHelper(arr,0,n-1,NULL);
            if(this->size != n)
            {
                throw BSTCreateMinimalTreeException();
            }
        }
        void listOfDepths()
        {
            _listOfDepthsDFS(this->root,0);
            _listOfDepthsBFS(this->root);
            if(verify())
            {
                std::cout<<"Success\n";
            }
            else
            {
                std::cout<<"Failed\n";
            }
            
        }

};


#endif