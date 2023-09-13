#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <iostream>
#define FOR(varname, init, limit) for (int varname = init; varname < limit; varname++)

using std::freopen;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::next_permutation;
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    int L;
    FOR(i, 0, N)
    {
        cin >> L;
        vector<int> LL(L);
        FOR(j, 0, L)
        {
            cin >> LL.at(j);
        }

        do
        {
            FOR(i, 0, L - 1)
            {
                cout << LL.at(i) << " ";
            }
            cout << LL.at(L-1) << endl;

        } while (next_permutation(LL.begin(), LL.end()));
    }

    return 0;
}
