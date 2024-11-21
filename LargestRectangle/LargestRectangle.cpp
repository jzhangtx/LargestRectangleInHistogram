// LargestRectangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int GetArea(const std::vector<int>& heights, size_t index)
{
    int minHeight = 0;
    int count = 0;
    int area = 0;
    for (size_t i = index; i < heights.size(); ++i)
    {
        if (heights[i] == 0)
            break;

        count++;
        if (minHeight == 0)
            minHeight = heights[i];
        else
            minHeight = std::min(minHeight, heights[i]);

        area = std::max(area, minHeight * count);
    }

    return area;
}

int GetLargestArea(std::vector<int>& heights)
{
    int area = 0;
    for (size_t i = 0; i < heights.size(); ++i)
    {
        area = std::max(area, GetArea(heights, i));
    }

    return area;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of heights: ";
        std::cin >> count;
        if (count == 0)
            break;

        std::vector<int> vec(count);
        std::cout << "The heights: ";
        for (int i = 0; i < count; ++i)
            std::cin >> vec[i];

        std::cout << "The largest area is " << GetLargestArea(vec) << std::endl;
    }
}
