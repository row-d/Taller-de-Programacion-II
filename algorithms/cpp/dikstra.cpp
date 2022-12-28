#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <limits>

using std::greater;
using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

template <typename Key>
vector<pair<int, Key>> dijkstra(unordered_map<Key, vector<pair<int, Key>>> grafo, Key raiz)
{
  // par<prioridad, vertice>
  priority_queue<pair<int, Key>, vector<pair<int, Key>>, greater<pair<int, Key>>> cola;
  unordered_map<Key, int> distancias;
  unordered_map<Key, Key> padres;
  vector<pair<int, Key>> arbol;

  // Inicializar distancias
  for (auto vertice : grafo)
    distancias[vertice.first] = std::numeric_limits<int>::max();

  // Inicializar cola
  cola.push({0, raiz});
  distancias[raiz] = 0;

  while (!cola.empty())
  {
    auto actual = cola.top();
    cola.pop();

    // Si la distancia del vertice actual es menor a la distancia que se tiene
    // en el vector de distancias, entonces se ignora el vertice actual
    if (actual.first > distancias[actual.second])
      continue;

    // Si el vertice actual no es la raiz, se agrega al arbol
    if (actual.second != raiz)
      arbol.push_back({distancias[actual.second], actual.second});

    // Se recorren los vecinos del vertice actual
    for (auto vecino : grafo[actual.second])
    {
      // Si la distancia del vecino es menor a la distancia que se tiene
      // en el vector de distancias, entonces se actualiza la distancia
      // y se agrega el vecino a la cola
      if (distancias[actual.second] + vecino.first < distancias[vecino.second])
      {
        distancias[vecino.second] = distancias[actual.second] + vecino.first;
        cola.push({distancias[vecino.second], vecino.second});
        padres[vecino.second] = actual.second;
      }
    }
  }

  return arbol;
}

int main()
{
  unordered_map<char, vector<pair<int, char>>> grafo = {
      {'A', {{7, 'B'}, {8, 'C'}, {9, 'D'}}},
      {'B', {{7, 'A'}, {10, 'C'}, {15, 'D'}}},
      {'C', {{8, 'A'}, {10, 'B'}, {11, 'D'}, {2, 'E'}}},
      {'D', {{9, 'A'}, {15, 'B'}, {11, 'C'}, {6, 'E'}}},
      {'E', {{2, 'C'}, {6, 'D'}}}};

  auto arbol = dijkstra(grafo, 'A');

  for (auto arista : arbol)
    std::cout << arista.second << " " << arista.first << std::endl;

  return 0;
}