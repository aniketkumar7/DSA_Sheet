// Given an array of distinct integers, we need to replace each element of the array with its rank. the minimum value element will have the highest rank.
// Input:{10,8,15,12,6,20,1}
// Output:{ 4,3,6,5,2,7,1}
// 1 : 1
// 6 : 2
// 8 : 3
// 10 : 4
// 12 : 5

// Given an integer N and a Flag
// If the flag is True then return the sum of even position digits of integer N.
// If the flag is False then return the sum of odd position digits of integer N.
// Input: 43125 and Flag is True
// Output: 5

#include <bits/stdc++.h>
using namespace std;


vector<int> rankArray(vector<int> arr)
{
    vector<int> temp = arr; // {10,8,15,12,6,20,1}
    sort(temp.begin(), temp.end()); // {1,6,8,10,12,15,20}
    unordered_map<int, int> rank; // {1:1, 6:2, 8:3, 10:4, 12:5, 15:6, 20:7}
    for (int i = 0; i < temp.size(); i++)
    {
        rank[temp[i]] = i + 1; // {1:1, 6:2, 8:3, 10:4, 12:5, 15:6, 20:7}
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rank[arr[i]];
    }
    return arr;
}


int sumOfDigits(int N, bool flag)
{
    string s = to_string(N); // "43125"
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (flag && (i + 1) % 2 == 0)
        {
            sum += s[i] - '0';
        }
        else if (!flag && (i + 1) % 2 != 0)
        {
            sum += s[i] - '0';
        }
    }
    return sum;
}

// K = 2
// 10
// 8
// 15
// 12
// 6
// 20
// 1


int kthMaxElement(vector<int> arr, int k)  // {10,8,15,12,6,20,1} k=3
{
    sort(arr.begin(), arr.end(), greater<int>()); // {20,15,12,10,8,6,1}
    return arr[k - 1];
}

// using priority queue
int kthMaxElement(vector<int> arr, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push(arr[i]);
    }
    for (int i = 0; i < k - 1; i++)
    {
        pq.pop();
    }
    return pq.top();
}

int main()
{
    vector<int> arr = {10, 8, 15, 12, 6, 20, 1};
    vector<int> result = rankArray(arr);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}