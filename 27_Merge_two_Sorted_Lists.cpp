// QUESTION: MERGE TWO SORTED LISTS

// PROBLEM STATEMENT:
// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Algorithm:
// 1. Initialize a dummy node
// 2. Initialize a pointer to the head of the merged list
// 3. Traverse both the lists
//     a. If the value of the first node of list1 is less than or equal to the value of the first node of list2
//         - Add the value of the first node of list1 to the merged list
//         - Move the pointer to the next node of list1
//     b. Otherwise
//         - Add the value of the first node of list2 to the merged list
//         - Move the pointer to the next node of list2
// 4. Return the head of the merged list

// SOLUTION:
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach 1: Brute Force
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    ListNode *dummy = new ListNode();
    ListNode *head = dummy;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            dummy->next = list1;
            list1 = list1->next;
        }
        else
        {
            dummy->next = list2;
            list2 = list2->next;
        }
        dummy = dummy->next;
    }
    if (list1 != NULL)
        dummy->next = list1;
    if (list2 != NULL)
        dummy->next = list2;
    return head->next;
}
// Time Complexity: O(N)
// Space Complexity: O(N)


// Approach 2: Recursion
ListNode *mergeTwoListsR(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoListsR(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoListsR(list1, list2->next);
        return list2;
    }
}
// Time Copmlexity: O(N)
// Space Complexity: O(N)


// Function to print the linked list
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}


int main()
{
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);
    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    list2->next->next->next = new ListNode(5);

    cout << "List 1: " << endl;
    printList(list1);
    cout << "List 2: " << endl;
    printList(list2);
    cout << endl;

    cout << "Approach 1: " << endl;
    ListNode *mergedList = mergeTwoListsR(list1, list2);
    printList(mergedList);
    cout << endl;
    return 0;
}