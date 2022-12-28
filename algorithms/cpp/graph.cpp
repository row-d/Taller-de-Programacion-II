#include <vector>

typedef struct
{
  int u, v;
  int weight;
} Edge;

class AdjListGraph
{
public:
  AdjListGraph(int n) : n_(n), adj_(n) {}
  void AddEdge(int u, int v)
  {
    adj_[u].push_back(v);
    adj_[v].push_back(u);
  }
  int n() const { return n_; }
  const std::vector<int> &adj(int u) const { return adj_[u]; }

private:
  int n_;
  std::vector<std::vector<int>> adj_;
};

class adjMatrixGraph
{
public:
  adjMatrixGraph(int n) : n_(n), adj_(n, std::vector<int>(n)) {}
  void AddEdge(int u, int v)
  {
    adj_[u][v] = 1;
    adj_[v][u] = 1;
  }
  int n() const { return n_; }
  const std::vector<int> &adj(int u) const { return adj_[u]; }

private:
  int n_;
  std::vector<std::vector<int>> adj_;
};

class EdgeListGraph
{
public:
  EdgeListGraph(int n) : n_(n) {}
  void AddEdge(int u, int v, int weight = 1)
  {
    edges_.push_back({u, v, weight});
  }
  int n() const { return n_; }
  const std::vector<Edge> &edges() const { return edges_; }

private:
  int n_;
  std::vector<Edge> edges_;
};
