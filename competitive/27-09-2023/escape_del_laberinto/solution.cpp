#include "headers.hpp"
#include "algorithms/disjkstra.hpp"

int main()
{
#ifndef ONLINE_JUDGE
  REDIRECT_STD("input.txt", "output.txt")
#endif

  READ(unsigned int, N);
  READ(unsigned int, M);

  graph g(N);
  vector<edge> edges(M);

  FOR_RANGE(i, M)
  {
    vertex u,v;
    weight w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].push_back({w, v});
    g[v].push_back({w, u});
    edges.push_back({u, v});
  }

  for(auto &edge: edges)
  {
    vertex u = edge.first;
    vertex v = edge.second;
    weight w;
    auto u_it = find_if(g[v].begin(), g[v].end(), [u](auto &wv)
                        { return wv.second == u; });
    auto v_it = find_if(g[u].begin(), g[u].end(), [v](auto &wv)
                        { return wv.second == v; });
    w = v_it->first;
    cout << "edge (" << u + 1 << "," << v + 1 << ") w=" << w << endl;
    g[u].erase(v_it);
    g[v].erase(u_it);
    auto result = dijkstra(g, u, v);
    g[u].push_back({w, v});
    g[v].push_back({w, u});
    if (result.second == INF)
      cout << -1 << endl;
    else
    {
      cout << "path: ";
      for (auto &v : result.first)
        cout << v.second + 1 << " ";
      cout << "\nweight:";
      cout << result.second << endl;
    }
  }

  return 0;
}