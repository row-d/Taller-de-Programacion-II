#include <iostream>
#include <vector>
using namespace std;
#ifndef ONLINE_JUDGE
#define MY_ONLINE_JUDGE               \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif


int main()
{
    MY_ONLINE_JUDGE
    vector<float> alturas(5);
    bool creciente = false;
    bool decreciente = false;
    fori(i, 5)
    {
        cin >> alturas[i];
    }
    forfrom(i, 1, 5)
    {
        float anterior = alturas[i - 1];
        float actual = alturas[i];
        creciente = anterior > actual;
        decreciente = anterior < actual;
    }

    cout << (creciente == decreciente ? "Ninguno" : creciente ? "Creciente"
                                                              : "Decreciente");

    return 0;
}