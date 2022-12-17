#include <vector>

template <typename T = int>
void depthfirstsearch(T at, std::vector<std::vector<T>> g, std::vector<bool> visited)
{
  std::vector<T> stack;
  stack.push_back(at);
  while (!stack.empty())
  {
    at = stack.back();
    stack.pop_back();
    if (!visited[at])
    {
      visited[at] = true;
      for (auto to : g[at])
      {
        stack.push_back(to);
      }
    }
  }
}