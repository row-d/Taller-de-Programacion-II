#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> prim(vector<int> &vertices, vector<int> &edges, int start);

int main()
{

  return 0;
}

vector<vector<int>> prim(vector<int> &vertices, vector<int> &edges, int start)
{
  vector<int> visited(vertices.size(), false);
  visited[0] = true;

}