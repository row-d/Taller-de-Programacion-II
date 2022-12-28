#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#define forto(i, n) for (int i = 0; i < n; ++i)
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    using std::cin;
    using std::cout;
    using std::endl;
    using std::string;
    using std::unordered_map;
    using std::vector;

    int n;
    cin >> n;
    forto(i, n)
    {
        unordered_map<char, vector<char>> edges;
        char max;
        char edge[2];
        cin >> max;
        while (cin >> edge[0] >> edge[1])
        {
            edges[edge[0]].push_back(edge[1]);
            edges[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(edges.size(), false);
        for (auto u : edges)
        {
            
        }
    }

    return 0;
}