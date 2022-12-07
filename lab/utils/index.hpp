#ifndef UTILS_INDEX_HPP
#define UTILS_INDEX_HPP
#include <functional>
namespace utils
{
    void useRange(std::function<void(int)> f, int pivot1, int pivot2);
}
#endif // UTILS_INDEX_HPP