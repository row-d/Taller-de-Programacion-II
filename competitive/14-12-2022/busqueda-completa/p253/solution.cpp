#include <iostream>
#include <fstream>

#define TRUE "TRUE"
#define FALSE "FALSE"
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    /**
     * input example:
     * rbgggrrggbgr
     * rrrbbbrrbbbr
     * rbgrbgrrrrrg
     *
     * output example:
     * TRUE
     * FALSE
     * FALSE
     */

    std::string cubes;
    while (std::cin >> cubes)
    {
        size_t len = cubes.size();
        size_t half = len / 2;
        std::string initialCube = cubes.substr(0, half);
        std::string finalCube = cubes.substr(half, len);
    }

    return 0;
}