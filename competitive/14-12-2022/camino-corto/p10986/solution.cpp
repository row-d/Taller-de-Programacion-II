#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>

#ifndef ONLINE_JUDGE
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#endif

using std::greater;
using std::make_pair;
using std::pair;
using std::priority_queue;
using std::vector;

typedef pair<int, int> iPair;

void addEdge(vector<pair<int, int>> adj[], int u, int v,
             int wt);

vector<int> dijkstra(vector<pair<int, int>> adj[], int V,
                     int src);

int main()
{
    int n;
    cin >> n;
    for (int _n = 0; _n < n; _n++)
    {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        vector<iPair> adj[n];
        for (size_t _m = 0; _m < m; _m++)
        {
            int sv1, sv2, latency;
            cin >> sv1 >> sv2 >> latency;
            addEdge(adj, sv1, sv2, latency);
        }

        vector<int> dist = dijkstra(adj, n, S);
        cout << "Case #" << _n + 1 << ": ";
        if (dist[T] == INT32_MAX)
        {
            cout << "unreachable\n";
        }
        else
        {
            cout << dist[T] << "\n";
        }
    }
    return 0;
}

void addEdge(vector<pair<int, int>> adj[], int u, int v,
             int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

vector<int> dijkstra(vector<pair<int, int>> adj[], int V,
                     int src)
{

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(V, INT32_MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist;
}
