// Question: Merge Nodes in Between Zeros
// Question URL: https://binarysearch.com/problems/Merge-Nodes-in-Between-Zeros

// Problem Statement:
// You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

// For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

// Return the head of the modified linked list.

// Example:
// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
// Explanation:
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 3 + 1 = 4.
// - The sum of the nodes marked in red: 4 + 5 + 2 = 11.


// Approach:

// Brute Force Solution:

// Traverse the linked list.
// Use a temporary list to store values between two consecutive zeros.
// Sum the values in the temporary list and create a new node with the sum.
// Continue until the end of the list.


// Intermediate Solution:

// Traverse the linked list.
// Use a single variable to accumulate the sum between two consecutive zeros.
// Create a new node with the accumulated sum when a zero is encountered.
// Continue until the end of the list.


// Optimized Solution:

// Traverse the linked list.
// Use a single variable to accumulate the sum between two consecutive zeros.
// Modify the original list in place to store the sums.
// Remove the nodes with zero values.


// Code:

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Brute Force Solution
ListNode *mergeNodesBruteForce(ListNode *head)
{
    std::vector<int> values;
    ListNode *current = head->next; // Skip the initial zero
    int sum = 0;

    while (current != nullptr)
    {
        if (current->val == 0)
        {
            values.push_back(sum);
            sum = 0;
        }
        else
        {
            sum += current->val;
        }
        current = current->next;
    }

    ListNode *newHead = new ListNode(0);
    ListNode *newCurrent = newHead;
    for (int val : values)
    {
        newCurrent->next = new ListNode(val);
        newCurrent = newCurrent->next;
    }

    return newHead->next;
}

// Intermediate Solution
ListNode *mergeNodesIntermediate(ListNode *head)
{
    ListNode *dummy = new ListNode(0);
    ListNode *current = head->next; // Skip the initial zero
    ListNode *newCurrent = dummy;
    int sum = 0;

    while (current != nullptr)
    {
        if (current->val == 0)
        {
            newCurrent->next = new ListNode(sum);
            newCurrent = newCurrent->next;
            sum = 0;
        }
        else
        {
            sum += current->val;
        }
        current = current->next;
    }

    return dummy->next;
}

// Optimized Solution
ListNode *mergeNodesOptimized(ListNode *head)
{
    ListNode *current = head->next; // Skip the initial zero
    ListNode *newCurrent = head;
    int sum = 0;

    while (current != nullptr)
    {
        if (current->val == 0)
        {
            newCurrent->val = sum;
            if (current->next != nullptr)
            {
                newCurrent->next = current;
                newCurrent = newCurrent->next;
            }
            sum = 0;
        }
        else
        {
            sum += current->val;
        }
        current = current->next;
    }

    newCurrent->next = nullptr;
    return head;
}

// print the linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    // Example usage
    ListNode *head = new ListNode(0);
    ListNode *current = head;
    current->next = new ListNode(3);
    current = current->next;
    current->next = new ListNode(1);
    current = current->next;
    current->next = new ListNode(0);
    current = current->next;
    current->next = new ListNode(4);
    current = current->next;
    current->next = new ListNode(5);
    current = current->next;
    current->next = new ListNode(2);
    current = current->next;
    current->next = new ListNode(0);
    current = current->next;
    cout << "Original List: ";
    printList(head);

    ListNode *newHead = mergeNodesBruteForce(head);
    cout << "Merged List: ";
    printList(newHead);


    return 0;
}



// Time and Space Complexity Analysis

/// Brute Force Solution
// Time Complexity:

// Traversing the linked list takes (O(n)) time, where (n) is the number of nodes in the list.
// Summing the values and creating new nodes also takes (O(n)) time.
// Overall, the time complexity is (O(n)).

// Space Complexity:

// Using a temporary list to store values between zeros requires (O(n)) additional space.
// Creating a new linked list also requires (O(n)) space.
// Overall, the space complexity is (O(n)).


/// Intermediate Solution
// Time Complexity:

// Traversing the linked list takes (O(n)) time.
// Creating new nodes with the accumulated sum also takes (O(n)) time.
// Overall, the time complexity is (O(n)).

// Space Complexity:

// Using a single variable to accumulate the sum requires (O(1)) additional space.
// Creating a new linked list requires (O(n)) space.
// Overall, the space complexity is (O(n)).


/// Optimized Solution
// Time Complexity:

// Traversing the linked list takes (O(n)) time.
// Modifying the original list in place also takes (O(n)) time.
// Overall, the time complexity is (O(n)).

// Space Complexity:

// Using a single variable to accumulate the sum requires (O(1)) additional space.
// Modifying the list in place does not require additional space for a new list.
// Overall, the space complexity is (O(1)).