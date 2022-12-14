#include <iostream>
#include <fstream>
#ifndef ONLINE_JUDGE
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#endif
#define TRUE "TRUE"
#define FALSE "FALSE"
int main()
{
    std::string cubes;
    enum Colors
    {
        r,
        g,
        b
    };
    enum Cube
    {
        A,
        B,
        C,
        D,
        E,
        F
    };

    while (cin >> cubes)
    {
        int r1 = 0;
        int g1 = 0;
        int b1 = 0;

        int r2 = 0;
        int g2 = 0;
        int b2 = 0;
        for (size_t i = 0; i < 6; i++)
        {
            for (size_t i = 0; i < 6; i++)
            {
                for (size_t i = 0; i < 6; i++)
                {
                }
            }
        }

        // cout << r1 << g1 << b1 << std::endl;
        // cout << r2 << g2 << b2 << std::endl;
        if (r1 == r2 && g1 == g2 && b1 == b2)
        {
            cout << TRUE << std::endl;
        }
        else
        {
            cout << FALSE << std::endl;
        }
    }
    return 0;
}