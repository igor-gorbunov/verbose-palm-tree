#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "radix_sort.hpp"
#include <vector>

TEST(test_radix_sort, radix_sorting_of_unsigned_integers)
{
    using namespace ::testing;

    {
        SCOPED_TRACE("Empty input");
        std::vector<unsigned int> empty{ };
        sorting::radix_sort(empty);
        ASSERT_EQ(empty.size(), 0);
    }

    {
        SCOPED_TRACE("Input of 1 element");
        std::vector<unsigned int> single{ 1 };
        sorting::radix_sort(single);
        ASSERT_EQ(single.size(), 1);
        ASSERT_THAT(single, ElementsAre(1));
    }

    {
        SCOPED_TRACE("Input of 2 sorted elements");
        std::vector<unsigned int> two{ 1, 2 };
        sorting::radix_sort(two);
        ASSERT_EQ(two.size(), 2);
        ASSERT_THAT(two, ElementsAre(1, 2));
    }

    {
        SCOPED_TRACE("Input of 2 unsorted elements");
        std::vector<unsigned int> two{ 2, 1 };
        sorting::radix_sort(two);
        ASSERT_EQ(two.size(), 2);
        ASSERT_THAT(two, ElementsAre(1, 2));
    }

    {
        SCOPED_TRACE("Input of 3 equal elements");
        std::vector<unsigned int> three{ 2, 2, 2 };
        sorting::radix_sort(three);
        ASSERT_EQ(three.size(), 3);
        ASSERT_THAT(three, ElementsAre(2, 2, 2));
    }

    {
        SCOPED_TRACE("Input of 10 unsorted elements");
        std::vector<unsigned int> ten{ 2, 1, 8, 3, 5, 9, 4, 10, 7, 6 };
        sorting::radix_sort(ten);
        ASSERT_EQ(ten.size(), 10);
        ASSERT_THAT(ten, ElementsAre(1, 2, 3, 4, 5, 6, 7, 8, 9, 10));
    }

    {
        SCOPED_TRACE("Input of 20 unsorted elements");
        std::vector<unsigned int> twenty{ 10000000, 1000000, 1, 100000, 10, 100000, 100, 10000, 10, 1, 10, 1000, 1000, 10000, 100, 100000, 10, 1000000, 1, 10000000 };
        sorting::radix_sort(twenty);
        ASSERT_EQ(twenty.size(), 20);
        ASSERT_THAT(twenty, ElementsAre(1, 1, 1, 10, 10, 10, 10, 100, 100, 1000, 1000, 10000, 10000, 100000, 100000, 100000, 1000000, 1000000, 10000000, 10000000));
    }

    {
        SCOPED_TRACE("Sorted input");
        std::vector<unsigned int> sorted{ 1, 2, 3, 4, 5, 6 };
        sorting::radix_sort(sorted);
        ASSERT_EQ(sorted.size(), 6);
        ASSERT_THAT(sorted, ElementsAre(1, 2, 3, 4, 5, 6));
    }

    {
        SCOPED_TRACE("Input containing maximum number");
        std::vector<unsigned int> vector{ 1, std::numeric_limits<unsigned int>::max(), 0, 6, 5, 4, 5, 6, std::numeric_limits<unsigned int>::max() };
        sorting::radix_sort(vector);
        ASSERT_EQ(vector.size(), 9);
        ASSERT_THAT(vector, ElementsAre(0, 1, 4, 5, 5, 6, 6, std::numeric_limits<unsigned int>::max(), std::numeric_limits<unsigned int>::max()));
    }

    {
        SCOPED_TRACE("Input containing maximum number");
        std::vector<unsigned long long> vector{ 1, std::numeric_limits<unsigned long long>::max(), 0, std::numeric_limits<unsigned long long>::max() - 1, std::numeric_limits<unsigned long long>::max() - 2, 4, 5, 6, std::numeric_limits<unsigned int>::max() };
        sorting::radix_sort(vector);
        ASSERT_EQ(vector.size(), 9);
        ASSERT_THAT(vector, ElementsAre(0, 1, 4, 5, 6, std::numeric_limits<unsigned int>::max(), std::numeric_limits<unsigned long long>::max() - 2, std::numeric_limits<unsigned long long>::max() - 1, std::numeric_limits<unsigned long long>::max()));
    }

    {
        SCOPED_TRACE("Input of 10 numbers some of which are negative");
        std::vector<signed int> vec{ 1, -2, 3, -4, 5, -6, 7, -8, 9, 0 };
        sorting::radix_sort(vec);
        ASSERT_EQ(vec.size(), 10);
        ASSERT_THAT(vec, ElementsAre(-8, -6, -4, -2, 0, 1, 3, 5, 7, 9));
    }
}
