// Unique Number of Occurrences

// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.


// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.



#include <bits/stdc++.h>
using namespace std;


bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]]++;
    }

    unordered_set<int> st;

    for (auto it : mp) {
        if (st.find(it.second) != st.end()) {
            return false;
        }
        st.insert(it.second);
    }
    return true;
}


// Time Complexity: O(n)
// Space Complexity: O(n)



// Approach 2: Using vector


bool uniqueOccurrences2(vector<int>& arr) {

    vector<int> v(2000, 0);
    for (int i = 0; i < arr.size(); i++) {
        v[arr[i]]++;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < 2001; i++)
    {
        if (v[i] != 0 && v[i] == v[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr = {1, 2, 2, 1, 1, 3};
    cout << "Input: " << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Approach 1: " << endl;
    cout << uniqueOccurrences(arr) << endl;

    cout << "Approach 2: " << endl;
    cout << uniqueOccurrences2(arr) << endl;
    return 0;
}

