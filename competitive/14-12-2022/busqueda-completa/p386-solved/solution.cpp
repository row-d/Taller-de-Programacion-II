#include <iostream>
#include <fstream>

#ifndef ONLINE_JUDGE
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#endif

using std::endl;

int main()
{
    int n = 3;
    for (size_t a = 6; a < 201; a++)
    {
        int a3 = a * a * a;
        for (size_t b = 2; b < 201; b++)
        {
            for (size_t c = 2; c < 201; c++)
            {
                for (size_t d = 2; d < 201; d++)
                {
                    int b3 = b * b * b;
                    int c3 = c * c * c;
                    int d3 = d * d * d;
                    int sum = (b3 + c3 + d3);
                    if (sum == a3 && b < c && c < d)
                    {
                        cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;
                    }
                }
            }
        }
    }
    return 0;
}