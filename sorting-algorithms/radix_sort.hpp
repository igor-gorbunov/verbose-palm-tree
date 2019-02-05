#pragma once

#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>

namespace sorting
{

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    out << "{ ";
    for (auto next : vec)
        out << next << " ";
    return out << "}";
}

template <typename T>
void radix_sort(std::vector<T> &vec)
{
    if (vec.size() < 2)
        return;

    std::vector<T> vec0, vec1;
    vec0.reserve(vec.size());
    vec1.reserve(vec.size());

    // std::cout << "Number of digits: " << std::numeric_limits<T>::digits << std::endl;

    T mask = 1;
    for (int i = 0; i < std::numeric_limits<T>::digits; ++i, mask <<= 1)
    {
        // std::cout << std::hex << "Mask = 0x" << mask << std::dec << std::endl;

        vec0.resize(0);
        vec1.resize(0);
        for (auto next : vec)
        {
            if (next & mask)
            {
                // group 1
                vec1.push_back(next);
            }
            else
            {
                // group 0
                vec0.push_back(next);
            }
        }
        auto last_it = std::copy(vec0.begin(), vec0.end(), vec.begin());
        std::copy(vec1.begin(), vec1.end(), last_it);

        // std::cout << "vec.size = " << vec.size() << ", " << vec << std::endl;
    }
}

}
