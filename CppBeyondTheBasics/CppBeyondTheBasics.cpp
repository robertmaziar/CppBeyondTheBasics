// CppBeyondTheBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include "Resource.h"
#include "ListAndVector.h"
#include <algorithm>
#include <numeric>
#include <list>

template <typename Func>
long long TimeFunc(Func f)
{
    auto begin = std::chrono::steady_clock::now();
    f();
    auto end = std::chrono::steady_clock::now();

    return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
}

int main()
{
#pragma region Vectors
    /*std::vector<int> numbers{ 0, 1, 2 };
    numbers.push_back(-2);
    numbers[0] = 3;
    int num = numbers[2];

    for (int i : numbers)
    {
        std::cout << i << std::endl;
    }

    Resource r("local");
    {
        std::cout << "----------------------------" << std::endl;
        std::vector<Resource> resources;
        resources.push_back(r);
        std::cout << "----------------------------" << std::endl;
        resources.push_back(Resource("first"));
        std::cout << "----------------------------" << std::endl;
        resources.push_back(Resource("second"));
    }*/
#pragma endregion

#pragma region Lists
    //int const size = 10'000;

    //std::vector<int> v;
    //v.push_back(0);

    //std::list<int> l;
    //l.push_back(0);

    //auto vectormilliseconds = TimeFunc([&]() {BuildVector(size, v); });
    //auto listmilliseconds = TimeFunc([&]() {BuildList(size, l); });
#pragma endregion

#pragma region Lambdas
    //auto isOdd = [](int candidate) { return candidate % 2 != 0; };

    //bool is3Odd = isOdd(3);
    //bool is4Odd = isOdd(4);
#pragma endregion

#pragma region Standard Library Algorithms
    // Populating a vector
    std::vector<int> v;
    //for (int i = 0; i < 5; i++)
    //{
    //    v.push_back(i);
    //}

    //for (int i = 0; i < 5;)
    //{
    //    v.push_back(i++);
    //}

    int i = 0;
    std::generate_n(std::back_inserter(v), 5, [&]() { return i++; });

    // Totalling the elements
    int total = 0;
    //for (int index = 0; index < 5; index++)
    //{
    //    total += v[index];
    //}

    //total = 0;
    //for (int elem : v)
    //{
    //    total += elem;
    //}

    total = std::accumulate(begin(v), end(v), 0);

    // Counting the number of 3's
    //int count1 = 0;
    //for (unsigned int i = 0; i < v.size(); i++)
    //{
    //    if (v[i] == 3)
    //    {
    //        count1++;
    //    }
    //}

    //int count2 = 0;
    //for (auto it = begin(v); it != end(v); it++)
    //{
    //    if (*it == 3)
    //    {
    //        count2++;
    //    }
    //}

    int count3 = std::count(begin(v), end(v), 3);

    // Removing the number 3
    //auto v2 = v;
    //for (unsigned int index = 0; index < v2.size(); index++)
    //{
    //    if (v2[index] == 3)
    //    {
    //        v2.erase(v2.begin() + index);
    //    }
    //}

    //auto v3 = v;
    //for (auto it = begin(v3); it != end(v3); it++)
    //{
    //    if (*it == 3)
    //    {
    //        v3.erase(it);
    //    }
    //}

    auto v4 = v;
    auto endv4 = std::remove_if(begin(v4), end(v4), [](int elem) { return (elem == 3); });
    v4.erase(endv4, end(v4));

    // One-liner
    //v4.erase(std::remove_if(begin(v4), end(v4), [](int elem) { return (elem == 3); }), end(v4));

    v4.push_back(-2);
    v4.push_back(7);
    v4.push_back(0);
    v4.push_back(1);

    std::sort(begin(v4), end(v4));

    bool allpositive = std::all_of(begin(v4), end(v4), [](int elem) { return elem >= 0; });

    std::string s{ "Hello I am a sentence" };
    auto letter = std::find(begin(s), end(s), 'a');

    auto caps = std::count_if(begin(s), end(s), [](char c) { return (c != ' ') && (toupper(c) == c); });
#pragma endregion

    return 0;
}
