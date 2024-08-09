// Problem: Container With Most Water

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Example 1:
//     Input: height = [1,8,6,2,5,4,8,3,7]
//     Output: 49


// Approach:

// Brute Force Approach:
// 1. Initialize max_area to 0.
// 2. Use two nested loops to iterate through all possible pairs of lines.
// 3. For each pair of lines, calculate the area by taking the minimum height between the two lines and multiplying it by the distance between them.
// 4. Update max_area if the calculated area is greater than the current max_area.
// 5. Return max_area.

// Time Complexity: O(n^2)
// Space Complexity: O(1)



// Optimized Approach:
// 1. Initialize max_area  to 0.
// 2. Set two pointers and j to the start and end of the vector, respectively.
// 3. While i is less than j, do the following: a. Calculate the area by taking the minimum height between height[i] and height[j] and multiplying it by the distance between i and j. b. Update max_area if the calculated area is greater than the current max_area. c. If height[i]  is smaller than height[j] , increment i. Otherwise, decrement j.
// 4. Return max_area.

// Time Complexity: O(n)
// Space Complexity: O(1)




#include<bits/stdc++.h>
using namespace std;

// Brute force Approach:

int maxAreaBruteForce(vector<int> &height, int heightSize)
{
    int max_area = 0;
    for (int i = 0; i < heightSize; i++)
    {
        for (int j = i + 1; j < heightSize; j++)
        {
            int area = min(height[i], height[j]) * (j - i);
            max_area = max(max_area, area);
        }
    }
    return max_area;
}

// Optimized Approach:
int maxArea(vector<int> &height)
{
    int heightSize = height.size();
    int max_area = 0;
    int i = 0, j = heightSize - 1;
    while (i < j)
    {
        int area = min(height[i], height[j]) * (j - i);
        max_area = max(max_area, area);
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return max_area;
}

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << "Brute Force Approach: " << endl;
    cout << maxAreaBruteForce(height, height.size());
    cout << "\nOptimized Approach: " << endl;
    cout << maxArea(height);
    return 0;
}