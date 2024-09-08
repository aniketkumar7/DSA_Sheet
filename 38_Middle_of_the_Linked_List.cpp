// QUESTION: MIDDLE OF THE LINKED LIST
// QUESTION LINK: https://leetcode.com/problems/middle-of-the-linked-list/

// PROBLEM STATEMENT:
// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.

//  EXAMPLE:

// Input: head = [1,2,3,4,5]
// Output: [3,4,5]
// Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
// ALGORITHM:
// 1.

// SOLUTION:

#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}


int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    cout << "Linked List: " << endl;
    printList(head);

    ListNode *result = middleNode(head);

    cout << "Middle Node: " << endl;
    while (result != NULL)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}
