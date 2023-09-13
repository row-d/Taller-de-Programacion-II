#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "aba";

    do
    {
        cout << s << '\n';

    } while (next_permutation(s.begin(), s.end()));

    cout << s << '\n';
    return 0;
}
