#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> dijkstra(vector<int> &vertices, vector<int> &edges, vector<int> &weights, int start);

int main()
{

  return 0;
}

vector<vector<int>> dijkstra(vector<int> &vertices, vector<int> &edges, vector<int> &weights, int start)
{
  vector<int> visited(vertices.size(), false);
  visited[0] = true;
}