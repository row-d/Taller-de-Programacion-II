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
vector<pair<int, Key>> prim(unordered_map<Key, vector<pair<int, Key>>> grafo, Key raiz)
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
      if (vecino.first < distancias[vecino.second])
      {
        distancias[vecino.second] = vecino.first;
        cola.push({vecino.first, vecino.second});
        padres[vecino.second] = actual.second;
      }
    }
  }

  return arbol;
}

int main()
{
  unordered_map<char, vector<pair<int, char>>> grafo;

  /***
  vector<int> distancias = prim(grafo, 'A');
   * A-> B:1 -> C:2
   * B-> A:1 -> C:3
   * C-> A:2 -> B:3 -> D:4 -> E:5 -> F:6
   * D -> C:4-> E:5
   * E -> D:7 -> F:8-> C:5
   * F -> E:8 -> C:6
   */

  // expect prim : 18
  // expect dijkstra : 18

  grafo['A'] = {{1, 'B'}, {2, 'C'}};
  grafo['B'] = {{1, 'A'}, {3, 'C'}};
  grafo['C'] = {{2, 'A'}, {3, 'B'}, {4, 'D'}, {5, 'E'}, {6, 'F'}};
  grafo['D'] = {{4, 'C'}, {5, 'E'}};
  grafo['E'] = {{7, 'D'}, {8, 'F'}, {5, 'C'}};
  grafo['F'] = {{8, 'E'}, {6, 'C'}};

  // Imprimir distancias
  for (auto distancia : prim(grafo, 'A'))
    std::cout << distancia.second << " " << distancia.first << std::endl;
  // imprimir suma de distancias
  int suma = 0;
  for (auto distancia : prim(grafo, 'A'))
    suma += distancia.first;
  std::cout << "suma: " << suma << std::endl;

  return 0;
}