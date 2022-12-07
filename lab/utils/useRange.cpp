#include "index.hpp"

void utils::useRange(std::function<void(int)> f, int pivot1, int pivot2)
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