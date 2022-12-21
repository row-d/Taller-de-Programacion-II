#include <vector>
template <typename T = int>
void depthfirstsearch(T at, std::vector<std::vector<T>> g, std::vector<bool> visited)
{
  if (!visited[at])
  {
    visited[at] = true;
    for (auto to : g[at])
    {
      depthfirstsearch(to, g, visited);
    }
  }
}