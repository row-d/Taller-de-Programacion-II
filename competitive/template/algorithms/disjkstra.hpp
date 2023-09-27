#include "../headers.hpp"
#ifndef DIJKSTRA
#define DIJKSTRA
typedef unsigned int weight;
typedef int vertex;
typedef pair<vertex, vertex> edge;
typedef pair<weight, vertex> weighted_vertex;
typedef vector<vector<weighted_vertex>> graph;
typedef priority_queue<weighted_vertex, vector<weighted_vertex>, greater<weighted_vertex>> min_heap;
const weight INF = numeric_limits<weight>::max();

pair<vector<weighted_vertex>, weight> dijkstra(graph &g, vertex start, vertex destiny)
{
  vector<weight> dist(g.size(), INF);
  vector<vertex> prev(g.size(), -1);
  min_heap q;
  q.push({0, start});
  dist[start] = 0;
  while (!q.empty())
  {
    weighted_vertex u = q.top();
    weight u_weight = u.first;
    vertex u_vertex = u.second;
    q.pop();

    if (u.first > dist[u_vertex])
      continue;
    for (auto &v : g[u_vertex])
    {
      weight v_weight = v.first;
      vertex v_vertex = v.second;
      weight sum_weight = u_weight + v_weight;

      if (dist[v_vertex] > sum_weight)
      {
        dist[v_vertex] = sum_weight;
        prev[v_vertex] = u_vertex;
        q.push({dist[v_vertex], v_vertex});
      }
    }
  }
  vector<weighted_vertex> path;
  weight total_weight = dist[destiny];
  for (vertex v = destiny; v != -1; v = prev[v])
    path.push_back({dist[v], v});
  reverse(path.begin(), path.end());
  return {path, total_weight};
}

#endif