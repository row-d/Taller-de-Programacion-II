#ifndef UTILS_INDEX_HPP
#define UTILS_INDEX_HPP
#include <functional>
namespace utils
{
    void forRange(int pivot1, int pivot2, std::function<void(int)> f);
}
#endif // UTILS_INDEX_HPP