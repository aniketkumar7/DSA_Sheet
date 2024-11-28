#include <bits/stdc++.h>
using namespace std;

// Function to calculate the minimum operations to make all elements equal
int min_operations_to_equal_elements(vector<int> &arr)
{
    sort(arr.begin(), arr.end());

    int n = arr.size();
    int median;
    if (n % 2 == 0)
    {
        median = arr[n / 2 - 1];
    }
    else
    {
        median = arr[n / 2];
    }

    int operations = 0;
    for (int num : arr)
    {
        operations += abs(num - median);
    }

    return operations;
}

int main()
{
    string input;

    cin >> input;

    // Process the input string into a vector of integers
    vector<int> arr;
    stringstream ss(input);
    int number;

    while (ss >> number)
    {
        arr.push_back(number);
    }

    int result = min_operations_to_equal_elements(arr);
    cout << result << endl;
}