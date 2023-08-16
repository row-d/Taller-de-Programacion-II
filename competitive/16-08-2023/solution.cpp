#include <iostream>
using namespace std;

#define NOTEOF($PATTERN,...) while(scanf($PATTERN,__VA_ARGS__) != EOF)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    NOTEOF("%i %i",&a,&b)
    {
        cout << a + b << endl;
    }
    return 0;
}