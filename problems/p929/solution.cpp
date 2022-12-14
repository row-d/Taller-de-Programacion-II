#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <queue>
#include "../../utils/index.hpp"

using std::endl;
using std::vector;
#ifndef ONLINE_JUDGE
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#endif

class UndirectedGraph
{
private:
    int n;
    int rows;
    int cols;
    vector<vector<int>> adj;

public:
    UndirectedGraph(int n) : n(n), adj(n, vector<int>(n, 0)) {}
    void addEdge(int u, int v, int w)
    {
        adj[u][v] = w;
    }
    int getEdge(int u, int v)
    {
        return adj[u][v];
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    // algorithm to find the shortest path from source to destination
    vector<int> dijkstra(int source, int destination)
    {
        // create a vector to store the distance from source to all vertices
        vector<int> dist(n, std::numeric_limits<int>::max());
        // create a vector to store the parent of all vertices
        vector<int> parent(n, -1);
        // create a vector to store the visited vertices
        vector<bool> visited(n, false);
        // create a min heap to store the vertices
        std::priority_queue<int, vector<int>, std::greater<int>> minHeap;
        // initialize the distance of source to 0
        dist[source] = 0;
        // insert the source into the min heap
        minHeap.push(source);
        // loop until the min heap is empty
        while (!minHeap.empty())
        {
            // extract the min element from the min heap
            int u = minHeap.top();
            minHeap.pop();
            // mark the vertex as visited
            visited[u] = true;
            // loop through all the adjacent vertices of u
            for (int v = 0; v < n; v++)
            {
                // if the vertex is not visited and there is an edge between u and v
                if (!visited[v] && getEdge(u, v) != 0)
                {
                    // if the distance of v is greater than the distance of u plus the weight of the edge between u and v
                    if (dist[v] > dist[u] + getEdge(u, v))
                    {
                        // update the distance of v
                        dist[v] = dist[u] + getEdge(u, v);
                        // update the parent of v
                        parent[v] = u;
                        // insert v into the min heap
                        minHeap.push(v);
                    }
                }
            }
        }
        return dist;
    }
};

int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        // read the number of rows and columns of the maze
        int rows, cols;
        cin >> rows >> cols;
        int V = rows * cols;
        // create a graph to represent the maze
        UndirectedGraph maze(V);

        vector<vector<int>> grid(rows, vector<int>(cols, 0));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> grid[i][j];
            }
        }
        // add the edges to the graph
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // if the current cell is not the last cell in the row
                if (j < cols - 1)
                {
                    // add an edge between the current cell and the cell to the right
                    maze.addEdge(i * cols + j, i * cols + j + 1, grid[i][j + 1]);
                }
                // if the current cell is not the last cell in the column
                if (i < rows - 1)
                {
                    // add an edge between the current cell and the cell below
                    maze.addEdge(i * cols + j, (i + 1) * cols + j, grid[i + 1][j]);
                }
            }
        }

        // find the shortest path from the top left cell to the bottom right cell
        vector<int> dist = maze.dijkstra(0, V - 1);
        // print the shortest path
        cout << dist[V - 1] << endl;
    }
    return 0;
}