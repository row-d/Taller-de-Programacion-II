#include <iostream>
#include <vector>
#include <algorithm>
#include "./utils/index.hpp"

using namespace std;

int main()
{
    utils::useRange([](int i) { cout << i << endl; }, 0, 10);
    
    return 0;
}