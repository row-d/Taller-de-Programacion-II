#include <iostream>
using namespace std;

#define NOTEOF($PATTERN, ...) while (scanf($PATTERN, __VA_ARGS__) != EOF)
#define fori(i, len) for (size_t i = 0; i < len; i++)
#define forfrom(i, init, len) for (size_t i = init; i < len; i++)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    return 0;
}