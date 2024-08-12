// Merge Intervals

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.


// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> merge(vector<vector<int>>& intervals)
{

    sort(intervals.begin(), intervals.end());

    vector<int> current = intervals[0];

    vector<vector<int>> merged;

    for(int i = 1; i < intervals.size(); i++)
    {
        if(current[1] >= intervals[i][0])
        {
            current[1] = max(current[1], intervals[i][1]);
        }
        else
        {
            merged.push_back(current);
            current = intervals[i];
        }
    }
    merged.push_back(current);
    return merged;
}


int main()
{

    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    cout << "Original Intervals: ";
    for(int i = 0; i < intervals.size(); i++)
    {
        cout << "[" << intervals[i][0] << ", " << intervals[i][1] << "] ";
    }

    cout << endl;

    // Merge the intervals
    vector<vector<int>> merged = merge(intervals);

    // Print the merged intervals
    cout << "Merged Intervals: ";
    for(int i = 0; i < merged.size(); i++)
    {
        cout << "[" << merged[i][0] << ", " << merged[i][1] << "] ";
    }
}


// Step-by-Step Dry Run
// 1. Initial Input:
// Input intervals: [[1, 3], [2, 6], [8, 10], [15, 18]]

// 2. Sorting the Intervals:
// After sorting based on the starting time, the list becomes:
// Sorted Intervals: [[1, 3], [2, 6], [8, 10], [15, 18]]

// 3. Initialization:
// We initialize merged as an empty vector: merged = [].
// We start with the first interval: currentInterval = [1, 3].

// 4. Iteration Through Intervals:
//  - First Iteration:
//      Current Interval: [1, 3]
//      Next Interval: [2, 6]
//      Condition: 2 <= 3 (overlap)
//      Merge: Update currentInterval to [1, max(3, 6)] = [1, 6].
//      urrent state: currentInterval = [1, 6]
//  - Second Iteration:
//      Current Interval: [1, 6]
//      Next Interval: [8, 10]
//      Condition: 8 <= 6 (no overlap)
//      Push currentInterval to merged: merged = [[1, 6]].
//      Update currentInterval to [8, 10].
//      Current state: currentInterval = [8, 10], merged = [[1, 6]].
//  - Third Iteration:
//      Current Interval: [8, 10]
//      Next Interval: [15, 18]
//      Condition: 15 <= 10 (no overlap)
//      Push currentInterval to merged: merged = [[1, 6], [8, 10]].
//      Update currentInterval to [15, 18].
//      Current state: currentInterval = [15, 18], merged = [[1, 6], [8, 10]].
// 5. Final Step:
// After finishing the loop, we add the last currentInterval to merged: merged.push_back([15, 18]).
// Final state: merged = [[1, 6], [8, 10], [15, 18]].
