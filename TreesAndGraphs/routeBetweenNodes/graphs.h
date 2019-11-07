#ifndef GRAPHS_H
#define GRAPHS_H

#include <map>
#include<vector>
#include<iostream>
#include "queue.h"

#define DEBUG (0)

enum GraphImpl{
    LIST = 0,
    MATRIX
};

enum GraphType{
    DIRECTED = 0,
    UNDIRECTED
};

enum SearchType{
    BFS = 0,
    DFS
};

template<typename T>
class Graph
{
private:
    GraphImpl graphImpl;
protected:
    virtual void bfs(T& src) = 0;
    virtual void dfs(T& src) = 0;
public:
    virtual void insert(T src,T dest) = 0;
    virtual void traverse(SearchType t) = 0;
    Graph(GraphImpl i)
    {
        this->graphImpl = i;
    }
    // if destructor is not virtual, then only base class destructor will be called
    // (since static binding)
    // therefore to call child class destructor also, we make base class destructor virtual
    virtual ~Graph()
    {
    #if DEBUG
        std::cout<<"Base graph Destructor called\n";
    #endif
    }
};

template<typename T>
class ListGraph:public Graph<T>
{
private:
    std::map<T,std::vector<T> > adjList;
    std::map<T,bool> vis;
    GraphType graphType;
    void dfs(T& src)
    {
        if(vis.find(src) != vis.end())
        {
            return;
        }
        vis[src] = true;
        std::cout<<src<<" ";
        std::vector<T>& neighbours = adjList[src];
        for(uint i=0;i<neighbours.size();i++)
        {
            dfs(neighbours[i]);
        }
    }
    void bfs(T& src)
    {
        if(vis.find(src) != vis.end())
        {
            return;
        }
        Queue<T> q;
        q.add(src);
        vis[src] = true;
        while(!q.isEmpty())
        {
            T vertex = q.remove();
            std::cout<<vertex<<" ";
            std::vector<T>& neighbours = adjList[vertex];
            for(uint i=0;i<neighbours.size();i++)
            {
                if(vis.find(neighbours[i]) == vis.end())
                {
                    q.add(neighbours[i]);
                    vis[neighbours[i]] = true;
                }
            }
        }
    }
    void bfsHelper()
    {
        vis.clear();
        typename std::map<T,std::vector<T> >::iterator itr;
        int src;
        for(itr = adjList.begin();itr!=adjList.end();itr++)
        {
            src = itr->first;
            bfs(src);
        }
    }
    void dfsHelper()
    {
        vis.clear();
        typename std::map<T,std::vector<T> >::iterator itr;
        int src;
        for(itr = adjList.begin();itr!=adjList.end();itr++)
        {
            src = itr->first;
            dfs(src);
        }
    }
public:
    void insert(T src,T dest)
    {
        switch (graphType)
        {
        case DIRECTED:
            adjList[src].push_back(dest);
            break;
        case UNDIRECTED:
            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        default:
            break;
        }
    }
    void traverse(SearchType t)
    {
        switch (t)
        {
        case BFS:
            bfsHelper();
            std::cout<<"\n";
            break;
        case DFS:
            dfsHelper();
            std::cout<<"\n";
            break;
        default:
            break;
        }
    }
    ListGraph(GraphType t):Graph<T>(LIST)
    {
        this->graphType = t;
    }
    ~ListGraph()
    {
    #if DEBUG
        std::cout<<"List graph destructor called\n";
    #endif
    }

};


#endif