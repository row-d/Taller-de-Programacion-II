#include <bits/stdc++.h>
using namespace std;

#define NOTEOF(PATTERN, ...) while (scanf(PATTERN, __VA_ARGS__) != EOF)
#define FOR(i, init, len) for (unsigned int i = init; i < len; i++)
#define FROMTO(i, len) FOR(i, 0, len)
#define CASES           \
    unsigned int cases; \
    cin >> cases;       \
    FOR(c, 0, cases)
#define CEROS_LEFT(n) __buildtin_ctz(n)
#define READ(type, var) \
    type var;           \
    cin >> var
#define READ_ARRAY(type, var, len) \
    type var[len];                 \
    FOR_RANGE(i, len)                 \
        cin >> var[i]
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    CASES
    {
        // Lectura
        READ(int, len);
        READ_ARRAY(int,a,len);
        READ_ARRAY(int,b,len);
        // Logica
        int count = 0;
        FOR_RANGE(i, len)
        {
            FOR(j, i + 1, len)
            {
                bool condition = (a[i] * a[j] == b[i] + b[j]);
                count += condition;
                if (condition)
                    cout << "(" << i + 1 << "," << j + 1 << ")\n";
            }
        }
        cout << count << endl;
        // Logica
    }

    return 0;
}