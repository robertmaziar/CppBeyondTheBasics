// CppBeyondTheBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include "Resource.h"
#include "ListAndVector.h"

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
    int const size = 10'000;

    std::vector<int> v;
    v.push_back(0);

    std::list<int> l;
    l.push_back(0);

    auto vectormilliseconds = TimeFunc([&]() {BuildVector(size, v); });
    auto listmilliseconds = TimeFunc([&]() {BuildList(size, l); });
#pragma endregion

    return 0;
}
