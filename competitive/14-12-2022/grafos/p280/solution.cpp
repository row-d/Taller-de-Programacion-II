#include <iostream>
#include <fstream>
#include <map>
#include <vector>

#ifndef ONLINE_JUDGE
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#endif

std::vector<size_t> dfs(std::vector<std::vector<size_t>> adj, std::vector<size_t> visited, size_t start)
{
    visited[start] = true;
    std::vector<size_t>::iterator i;
    for (i = adj[start].begin(); i != adj[start].end(); ++i)
    {
        if (!visited[*i])
        {
            dfs(adj, visited, *i);
        }
    }
}

int main()
{
    size_t n;
    do
    {
        cin >> n;
        std::vector<std::vector<size_t>> adj;
        std::vector<size_t> visited(n, false);
        for (size_t i = 0; i < n; i++)
        {
            size_t key;
            size_t u;
            size_t j = 0;
            do
            {
                cin >> key;
                if (j = 0)
                {
                    u = key;
                }
                else
                {
                    adj[u].push_back(key);
                }
                j++;

            } while (key != 0);
            cin.ignore();
            dfs(adj,visited,0);
        }

    } while (n != 0);
    return 0;
}