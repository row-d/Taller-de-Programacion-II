#include <iostream>
#include <fstream>
<<<<<<< HEAD
=======
#include <string>

using std::string;

#ifndef ONLINE_JUDGE
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#endif
>>>>>>> b4c8b64d8afe657b9453552c260cd380331b6be8

#define TRUE "TRUE"
#define FALSE "FALSE"

int main()
{
<<<<<<< HEAD
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
=======
    std::string cubes;
>>>>>>> b4c8b64d8afe657b9453552c260cd380331b6be8

    std::string cubes;
    while (std::cin >> cubes)
    {
<<<<<<< HEAD
        size_t len = cubes.size();
        size_t half = len / 2;
        std::string initialCube = cubes.substr(0, half);
        std::string finalCube = cubes.substr(half, len);
=======

        for (size_t i = 0; i < 6; i++)
        {
            for (size_t i = 0; i < 6; i++)
            {
                for (size_t i = 0; i < 6; i++)
                {
                }
            }
        }
>>>>>>> b4c8b64d8afe657b9453552c260cd380331b6be8
    }

    return 0;
}