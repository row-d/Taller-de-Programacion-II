#include "index.hpp"

void utils::forRange(int pivot1, int pivot2, std::function<void(int)> f)
{
    if (pivot1 < pivot2)
    {
        for (int i = pivot1; i < pivot2; i++)
        {
            f(i);
        }
    }
    else
    {
        for (int i = pivot1; i > pivot2; i--)
        {
            f(i);
        }
    }
}