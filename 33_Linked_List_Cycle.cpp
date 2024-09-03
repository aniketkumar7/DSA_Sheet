// QUESTION: LINKED LIST CYCLE
// QUESTION LINK: https://leetcode.com/problems/linked-list-cycle/

// PROBLEM STATEMENT:

// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

// EXAMPLE:
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// SOLUTION:

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// SOLUTION:

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach 1: Brute Force
bool hasCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;

    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}


// Approach 2: Hashing
bool hasCycle2(ListNode *head)
{
    unordered_set<ListNode *> s;
    while (head != NULL)
    {
        if (s.find(head) != s.end())
            return true;
        s.insert(head);
        head = head->next;
    }
    return false;
}


// Approach 3: Fast and Slow
bool hasCycle3(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    ListNode *slow = head, *fast = head->next;
    while (slow != fast)
    {
        if (fast == NULL || fast->next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

// DRIVER CODE:
int main()
{
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    cout << hasCycle(head) << endl;
    cout << hasCycle2(head) << endl;
    cout << hasCycle3(head) << endl;

    return 0;
}

// Linked List Representation

// 3->2->0->-4->2