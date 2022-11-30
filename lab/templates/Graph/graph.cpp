#include "./graph.hpp"

template <typename V, typename E>
class Graph : public GraphAdjacencyListADT<V, E>
{
private:
    vector<struct Node<V>> _nodes;
    vector<E> _edges;

public:
    Graph(vector<struct Node<V>> nodes, vector<E> edges)
    {
        this._nodes = nodes;
        this._edges = edges
    };

    bool adjacent(struct Node<V> x, struct Node<V> y)
    {
        // no estoy seguro si funciona
        // TODO: Investigar listas de adyacencias
        return this._edges[x] == this._edges[y] && this._edges[y] == this._edges[x];
    };

    vector<struct Node<V>> neighbors(struct Node<V> x)
    {

        vector<V> neighbors;
        vector<V>::iterator it;
        size_t i = 0;
        for (it = myvector.begin(); it != myvector.end(); it++, i++)
        {
            if (*it == x)
            {
                neighbors.push_back(it);
            }
        }

        return neighbors;
    };

    struct Node<V> add_vertex(struct Node<V> x)
    {
        return this._nodes.push_back(x);
    };
    void remove_vertex(struct Node<V> x)
    {
        vector<V>::iterator it;
        size_t i = 0;
        for (it = myvector.begin(); it != myvector.end(); it++, i++)
        {
            if (*it == x)
            {
                this->_nodes.erase(i);
            }
        }
    };
    struct Node<V> add_edge(struct Node<V> x, struct Node<V> x, E e){
        
    };
    void remove_edge(struct Node<V> x);
    get_edge_value(struct Node<V> x, struct Node<V> y);
    set_edge_value(struct Node<V> x, struct Node<V> y, V value);
};