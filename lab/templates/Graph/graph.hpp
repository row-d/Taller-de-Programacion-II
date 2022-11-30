#include "vector"
using std::vector;
#ifndef __GRAPH__
#define __GRAPH__

template <typename T>
struct Node
{
    T value;
};

template <typename V, typename E>
class GraphAdjacencyListADT
{

private:
    vector<struct Node<V>> _nodes;
    vector<E> edges;

public:
    virtual bool adjacent(struct Node<V> x, struct Node<V> y) = 0;
    virtual vector<struct Node<V>> neighbors(struct Node<V> x) = 0;
    virtual struct Node<V> add_vertex(struct Node<V> x) = 0;
    virtual void remove_vertex(struct Node<V> x) = 0;
    virtual struct Node<V> add_edge(struct Node<V> x, struct Node<V> x, E e) = 0;
    virtual void remove_edge(struct Node<V> x) = 0;
    virtual get_edge_value(struct Node<V> x, struct Node<V> y) = 0;
    virtual set_edge_value(struct Node<V> x, struct Node<V> y, V value) = 0;
};

#endif