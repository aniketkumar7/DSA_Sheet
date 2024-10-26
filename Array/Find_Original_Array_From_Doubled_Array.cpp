// Question: Find Original Array From Doubled Array
// Question URL: https://leetcode.com/problems/find-original-array-from-doubled-array/
// Difficulty: Medium

// Problem Statement:
// An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

// Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.



// Example 1:

// Input: changed = [1,3,4,2,6,8]
// Output: [1,3,4]
// Explanation: One possible original array could be [1,3,4]:
// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.
// Other original arrays could be [4,3,1] or [3,1,4].


// Algorithm to Find the Original Array from a Doubled Array
// This algorithm aims to reconstruct the original array from a given doubled array. A doubled array is formed by taking an original array and appending each element multiplied by 2 to it. The goal is to find the original array if it can be reconstructed; otherwise, return an empty array.

// Steps
/// Check Array Size:
// If the size of the input array (changed) is odd, return an empty array because a valid doubled array must have an even number of elements.

/// Count Occurrences:
// Create an unordered map (mp) to count the occurrences of each element in the input array.

/// Sort the Array:
// Sort the input array (changed) in ascending order. Sorting helps in ensuring that when we process each element, we can easily find its double.

/// Reconstruct the Original Array:
// Initialize an empty vector (original) to store the elements of the original array.
// Iterate through the sorted array (changed):
// For each element, check if it is still available in the map (mp).
// If the element's double is not available in the map, return an empty array because the original array cannot be reconstructed.
// If both the element and its double are available, add the element to the original array, and decrement the counts of the element and its double in the map.

/// Return the Result:
// After processing all elements, return the original array.


// Code:
#include <bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    vector<int> original;
    if(changed.size() % 2 != 0)
        return original;

    unordered_map<int, int> mp;
    for(int i = 0; i < changed.size(); i++) {
        mp[changed[i]]++;
    }

    sort(changed.begin(), changed.end());

    for(int i = 0; i < changed.size(); i++) {
        if(mp[changed[i]] == 0) continue;
        if(mp[changed[i] * 2] == 0) return original;
        original.push_back(changed[i]);
        mp[changed[i]]--;
        mp[changed[i] * 2]--;
    }
    return original;
}

int main() {
    vector<int> changed = {1,3,4,2,6,8};
    cout << "Original Array: ";
    for(auto x : changed) {
        cout << x << " ";
    }

    vector<int> original = findOriginalArray(changed);
    cout << "\nReconstructed Original Array: ";
    for(auto x : original) {
        cout << x << " ";
    }
    return 0;
}


/// Dry Run:

// Consider the input array: [1, 3, 4, 2, 6, 8]

/// Initial Input:
// changed = [1, 3, 4, 2, 6, 8]

/// Count Occurrences:
// mp = {1: 1, 3: 1, 4: 1, 2: 1, 6: 1, 8: 1}
// Sort the Array:

/// Reconstruct the Original Array:

// Process 1: Add 1 to original, decrement counts of 1 and 2.
// original = [1]
// mp = {1 : 0, 3 : 1, 4 : 1, 2 : 0, 6 : 1, 8 : 1}

// Process 3: Add 3 to original, decrement counts of 3 and 6.
// original = [ 1, 3 ]
// mp = {1 : 0, 3 : 0, 4 : 1, 2 : 0, 6 : 0, 8 : 1}

// Process 4: Add 4 to original, decrement counts of 4 and 8.
// original = [ 1, 3, 4 ]
// mp = {1 : 0, 3 : 0, 4 : 0, 2 : 0, 6 : 0, 8 : 0}

/// Final Output:
// original = [1, 3, 4]