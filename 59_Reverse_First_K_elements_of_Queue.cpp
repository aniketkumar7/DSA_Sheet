// Question: Reverse First K elements of Queue
// Question URL: https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
// Level: Easy

// Problem Statement:
// Given an integer K and a queue of integers, we need to reverse the order of the first K elements of the queue, leaving the other elements in the same relative order.

// Only following standard operations are allowed on queue.

// enqueue(x) : Add an item x to rear of queue
// dequeue() : Remove an item from front of queue
// size() : Returns number of elements in queue.
// front() : Finds front item.
// Note: The above operations represent the general processings. In-built functions of the respective languages can be used to solve the problem.

// Example 1:

// Input:
// 5 3
// 1 2 3 4 5
// Output:
// 3 2 1 4 5
// Explanation:
// After reversing the given
// input from the 3rd position the resultant
// output will be 3 2 1 4 5.


// Code:

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

// Approach1: Using stack
void reverseK(queue<int> &q, int k)
{
    stack<int> s;
    int n = q.size();
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

// Approach2: Using vector
void Reverse(queue<int> &q, int k)
{
    vector<int> v;
    int n = q.size();
    for(int i=0; i<k; i++)
    {
        v.push_back(q.front());
        q.pop();
    }
    reverse(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
    {
        q.push(v[i]);
    }
    for(int i=0; i<n-k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

int main()
{
    int n, k;
    cout << "Enter the number of elements in the queue: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;

    queue<int> q;
    cout << "Enter the elements of the queue: " << endl;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    Reverse(q, k);
    cout << "The reversed queue is: " << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}



// Time and Space Complexity:

// For Approach1:
// Time Complexity: O(n)
// Space Complexity: O(k)

// For Approach2:
// Time Complexity: O(n)
// Space Complexity: O(n)