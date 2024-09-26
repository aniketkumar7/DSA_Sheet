// Question: Intersection of Two Linked Lists
// Question URL: https://leetcode.com/problems/intersection-of-two-linked-lists/

// Problem Statement:
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// Example 1:
// Input: listA = [4,1,8,4,5], listB = [5,0,1,8,4,5]
// Output: Intersected at '8'

// Solution:

#include <iostream>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB)
{
    unordered_map<ListNode *, int> m;
    while (headA != NULL)
    {
        m[headA]++;
        headA = headA->next;
    }
    while (headB != NULL)
    {
        if (m[headB] > 0)
        {
            return headB;
        }
        headB = headB->next;
    }
    return NULL;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
        return NULL;

    ListNode *a = headA;
    ListNode *b = headB;

    while (a != b)
    {
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }

    return a;
}

// print the linked list
void printList(ListNode *node)
{
    while (node != NULL)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    // Create the linked list
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = new ListNode(8);
    headA->next->next->next = new ListNode(4);
    headA->next->next->next->next = new ListNode(5);
    cout << "List A: ";
    printList(headA);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = headA->next->next;
    cout << "List B: ";
    printList(headB);

    cout << "Intersection: " << endl;
    ListNode *intersectionNode = getIntersectionNode(headA, headB);
    cout << "Intersected at " << intersectionNode->val << endl;

    return 0;
}