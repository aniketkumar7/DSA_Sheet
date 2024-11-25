// QUESTION :  REVERSE LINKED LIST

// PROBLEM STATEMENT:
// Given the head of a singly linked list, reverse the list, and return the reversed list.

// EXAMPLE:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// ALGORITHM:
// 1. Initialize three pointers prev as NULL, curr as head and next as NULL
// 2. Traverse the list
//     a. Store next
//     b. Change next
//     c. Move prev and curr one step forward
// 3. Return prev
// 4. Time Complexity: O(n)
// 5. Space Complexity: O(1)


// SOLUTION:

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// APPROACH 1:
ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
// Time Complexity: O(n)
// Space Complexity: O(1)


// APPROACH 2:
ListNode *reverseListRec(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}
// Time Complexity: O(n)
// Space Complexity: O(n)


// APPROACH 3:
ListNode *reverseListSt(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    stack<ListNode *> st;
    ListNode *curr = head;

    while (curr != NULL)
    {
        st.push(curr);
        curr = curr->next;
    }
    curr = st.top();
    st.pop();
    head = curr;
    while (!st.empty())
    {
        curr->next = st.top();
        st.pop();
        curr = curr->next;
    }
    curr->next = NULL;
    return head;
}
// Time Complexity: O(n)
// Space Complexity: O(n)

// Print the list
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
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    cout << "Reversed List: ";
    ListNode *ans = reverseList(head);
    printList(ans);
    return 0;
}

