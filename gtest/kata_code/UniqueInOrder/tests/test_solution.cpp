#include <vector>
#include <gtest/gtest.h>

#include "solution.h"

#include <algorithm>
#include <iostream>
#include <random>

auto randint(int min, int max) {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

std::string printVec(const std::vector<char>& vec) {
    std::string res = "'" + std::string(1, vec[0]) + "'";
    for (unsigned int i = 1; i < vec.size(); i++) res += ", '" + std::string(1, vec[i]) + "'";
    return res;
}

std::string printVec(const std::vector<int>& vec) {
    std::string res = std::to_string(vec[0]);
    for (unsigned int i = 1; i < vec.size(); i++) res += ", " + std::to_string(vec[i]);
    return res;
}
using VI = std::vector<int>;
using VC = std::vector<char>;

TEST(UniqueInOrder, BasicTests) {
    ASSERT_EQ(uniqueInOrder(""), VC{});
    ASSERT_EQ(uniqueInOrder("AA"), VC{ 'A' });
    ASSERT_EQ(uniqueInOrder("A"), VC{ 'A' });
    ASSERT_EQ(uniqueInOrder("AAAABBBCCDAABBB"), (VC{ 'A', 'B', 'C', 'D', 'A', 'B' }));
    ASSERT_EQ(uniqueInOrder("AADD"), (VC{ 'A', 'D' }));
    ASSERT_EQ(uniqueInOrder("AAD"), (VC{ 'A', 'D' }));
    ASSERT_EQ(uniqueInOrder("ADD"), (VC{ 'A', 'D' }));
    ASSERT_EQ(uniqueInOrder("ABBCcAD"), (VC{ 'A', 'B', 'C', 'c', 'A', 'D' }));
    ASSERT_EQ(uniqueInOrder(VI{ 1,2,3,3 }), (VI{ 1,2,3 }));
    ASSERT_EQ(uniqueInOrder(VC{ 'a','b','b' }), (VC{ 'a','b' }));
};
    template <typename T> std::vector<T> sol(const std::vector<T>&iterable) {
        std::vector<T> res = iterable;
        res.erase(std::unique(begin(res), end(res)), end(res));
        return res;
    }

    std::vector<char> sol(const std::string & iterable) {
        std::string res = iterable;
        res.erase(std::unique(begin(res), end(res)), end(res));
        return std::vector<char>{begin(res), end(res)};
    }
    TEST(UniqueInOrder, RandomTests) {
        std::string base = "abcXYZ";
        for (unsigned int i = 0; i < 40; i++) {
            unsigned int testCase = randint(0, 2), inputLen = randint(3, 40);
            if (testCase == 0) {
                std::string iterable;
                for (; inputLen--;) iterable += base[randint(0, base.size() - 1)];
                std::cout << "Testing for '" << iterable << "'\n\n";
                ASSERT_EQ(uniqueInOrder(iterable), sol(iterable));
            }
            else if (testCase == 1) {
                std::vector<char> iterable;
                for (; inputLen--;) iterable.push_back(base[randint(0, base.size() - 1)]);
                std::cout << "Testing for [" << printVec(iterable) << "]\n\n";
                ASSERT_EQ(uniqueInOrder(iterable), sol(iterable));
            }
            else {
                std::vector<int> iterable;
                for (; inputLen--;) iterable.push_back(randint(-5, 5));
                std::cout << "Testing for [" << printVec(iterable) << "]\n\n";
                ASSERT_EQ(uniqueInOrder(iterable), sol(iterable));
            }
        }
    };