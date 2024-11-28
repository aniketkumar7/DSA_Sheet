// 🎯Problem Explaination :
// We have an array height representing the heights of bars at different positions.
// The goal is to calculate how much water can be trapped between these bars after a rainfall.Each bar has a certain height given by the elements of the height array.

// ✅Approach :

// 1. Determine the maximum elevation to the left and right of each bar:
//      - Use two arrays: left[i] and right[i] 🔢
//      - left[i] stores the maximum height encountered from the start up to the
//        current index i 🏔️
//      - right[i] stores the maximum height encountered from the end up to
//      - the current index i 🏔️

// 2. Filling the left[] array:
//      - Initialize left with the height of the first bar 🌊
//      - For each subsequent index i, compute left[i] as the maximum of left
//        [i-1] and the current height height[i] 🏔️
//      - This ensures that left[i] always holds the maximum height encountered
//        from the start up to i 🔝

// 3. Filling the right[] array:
//      - Initialize right[n-1] with the height of the last bar 🌊
//      - For each index i from n-2 down to 0, compute right[i] as the maximum
//        of right[i+1] and the current height height[i] 🏔️
//      - This ensures that right[i] always holds the maximum height
//         encountered from i to the end 🔝

// 4. Calculating trapped water:
//      - Once left[] and right[] arrays are populated, iterate through the
//        bars 🔁
//      - For each bar at index i, calculate the trapped water above it and
//        store it in trappedWater 💧
//      - Use the formula: trappedWater += (min(left[i], right[i]) - height[i])
//        This represents the maximum water that can be trapped above the bar
//        at i, considering the minimum of the highest bars on its left and
//        right minus its own height

// 5. Final answer:
//      - Variable trappedWater holds the value of trapped water after rain 💧💧
//      - Return the total amount of trapped water 🏆



#include <iostream>
#include<vector>
    using namespace std;

int WaterTrapped(vector<int>& height)
{
    int n = height.size();

    if(n == 0)
        return 0;

    vector<int> left(n);
    vector<int> right(n);

    left[0] = height[0];
    for(int i=1; i<n; i++)
    {
        left[i] = max(left[i-1], height[i]);
    }

    right[n-1] = height[n-1];
    for(int i=n-2; i>=0; i--)
    {
        right[i] = max(right[i+1], height[i]);
    }

    int trappedWater = 0;
    for(int i=0; i<n; i++)
    {
        trappedWater += min(left[i], right[i]) - height[i];
    }

    return trappedWater;
}


// Optimized approach

int WaterTrapped(vector<int>& height)
{
    int n = height.size();

    if(n == 0)
        return 0;

    int left = 0, right = n-1;
    int leftMax = 0, rightMax = 0;
    int trappedWater = 0;

    while(left < right)
    {
        if(height[left] < height[right])
        {
            if(height[left] >= leftMax)
                leftMax = height[left];
            else
                trappedWater += leftMax - height[left];
            left++;
        }
        else
        {
            if(height[right] >= rightMax)
                rightMax = height[right];
            else
                trappedWater += rightMax - height[right];
            right--;
        }
    }

    return trappedWater;
}


int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << WaterTrapped(height);
    return 0;
}



// Let's walk through the step-by-step process of calculating the trapped water using the provided height array [0,1,0,2,1,0,1,3,2,1,2,1] with the approach outlined earlier. We'll track the values of left, right, and trappedWater at each iteration:

// TODO -> Step 0: Initialization
// height = [0,1,0,2,1,0,1,3,2,1,2,1]
// n = 12 (length of height)
// left[] and right[] arrays will be initialized later during execution.


// TODO -> Step 1: Fill left[] Array
// left[0] = height[0] = 0
// left[1] = max(left[0], height[1]) = max(0, 1) = 1
// left[2] = max(left[1], height[2]) = max(1, 0) = 1
// left[3] = max(left[2], height[3]) = max(1, 2) = 2
// left[4] = max(left[3], height[4]) = max(2, 1) = 2
// left[5] = max(left[4], height[5]) = max(2, 0) = 2
// left[6] = max(left[5], height[6]) = max(2, 1) = 2
// left[7] = max(left[6], height[7]) = max(2, 3) = 3
// left[8] = max(left[7], height[8]) = max(3, 2) = 3
// left[9] = max(left[8], height[9]) = max(3, 1) = 3
// left[10] = max(left[9], height[10]) = max(3, 2) = 3
// left[11] = max(left[10], height[11]) = max(3, 1) = 3
// left[] = [0,1,1,2,2,2,2,3,3,3,3,3]


// TODO -> Step 2: Fill right[] Array
// right[11] = height[11] = 1
// right[10] = max(right[11], height[10]) = max(1, 2) = 2
// right[9] = max(right[10], height[9]) = max(2, 1) = 2
// right[8] = max(right[9], height[8]) = max(2, 2) = 2
// right[7] = max(right[8], height[7]) = max(2, 3) = 3
// right[6] = max(right[7], height[6]) = max(3, 1) = 3
// right[5] = max(right[6], height[5]) = max(3, 0) = 3
// right[4] = max(right[5], height[4]) = max(3, 1) = 3
// right[3] = max(right[4], height[3]) = max(3, 2) = 3
// right[2] = max(right[3], height[2]) = max(3, 0) = 3
// right[1] = max(right[2], height[1]) = max(3, 1) = 3
// right[0] = max(right[1], height[0]) = max(3, 0) = 3
// right[] = [3,3,3,3,3,3,3,3,2,2,2,1]


// TODO -> Step 3: Calculate Trapped Water
// i = 0:
//     trappedWater += min(left[0], right[0]) - height[0] = min(0, 3) - 0 = 0 - 0 = 0
//     trappedWater = 0

// i = 1:
//     trappedWater += min(left[1], right[1]) - height[1] = min(1, 3) - 1 = 1 - 1 = 0
//     trappedWater = 0

// i = 2:
//     trappedWater += min(left[2], right[2]) - height[2] = min(1, 3) - 0 = 1 - 0 = 1
//     trappedWater = 1

// i = 3:
//     trappedWater += min(left[3], right[3]) - height[3] = min(2, 3) - 2 = 2 - 2 = 0
//     trappedWater = 1

// i = 4:
//     trappedWater += min(left[4], right[4]) - height[4] = min(2, 3) - 1 = 2 - 1 = 1
//     trappedWater = 2

// i = 5:
//     trappedWater += min(left[5], right[5]) - height[5] = min(2, 3) - 0 = 2 - 0 = 2
//     trappedWater = 4

// i = 6:
//     trappedWater += min(left[6], right[6]) - height[6] = min(2, 3) - 1 = 2 - 1 = 1
//     trappedWater = 5

// i = 7:
//     trappedWater += min(left[7], right[7]) - height[7] = min(3, 3) - 3 = 3 - 3 = 0
//     trappedWater = 5

// i = 8:
//     trappedWater += min(left[8], right[8]) - height[8] = min(3, 2) - 2 = 2 - 2 = 0
//     trappedWater = 5

// i = 9:
//     trappedWater += min(left[9], right[9]) - height[9] = min(3, 2) - 1 = 2 - 1 = 1
//     trappedWater = 6

// i = 10:
//     trappedWater += min(left[10], right[10]) - height[10] = min(3, 2) - 2 = 2 - 2 = 0
//     trappedWater = 6

// i = 11:
//     trappedWater += min(left[11], right[11]) - height[11] = min(3, 1) - 1 = 1 - 1 = 0
//     trappedWater = 6


// TODO -> Final Result
// The total trapped water after rain for the given height array [0,1,0,2,1,0,1,3,2,1,2,1] is 6 units.