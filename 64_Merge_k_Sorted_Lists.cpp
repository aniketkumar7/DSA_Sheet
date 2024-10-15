// Question: Merge K Sorted Lists
// Question URL: https://leetcode.com/problems/middle-of-the-linked-list/
// Topics: Linked List, Merge Sort

// Problem Statement:
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

// Example:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]

// Approach:




// Code:

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeLists(vector<ListNode*>& lists) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (true) {
        int minVal = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] && lists[i]->val < minVal) {
                minVal = lists[i]->val;
                minIndex = i;
            }
        }

        if (minIndex == -1) {
            break;
        }

        current->next = lists[minIndex];
        current = current->next;
        lists[minIndex] = lists[minIndex]->next;
    }

    return dummy->next;
}

// print the linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        cout << current->val << "-> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    vector<ListNode*> lists;
    ListNode* head1 = new ListNode(1);
    ListNode* current = head1;
    current->next = new ListNode(4);
    current = current->next;
    current->next = new ListNode(5);
    lists.push_back(head1);


    ListNode* head2 = new ListNode(1);
    current = head2;
    current->next = new ListNode(3);
    current = current->next;
    current->next = new ListNode(4);
    lists.push_back(head2);


    ListNode* head3 = new ListNode(2);
    current = head3;
    current->next = new ListNode(6);
    lists.push_back(head3);


    // Whole list
    cout << "Original List: " << endl;
    // lists = [[1,4,5],[1,3,4],[2,6]]
    for (int i = 0; i < lists.size(); i++) {
        printList(lists[i]);
    }

    ListNode* result = mergeLists(lists);
    cout << "Merged List: ";
    printList(result);

    return 0;
}