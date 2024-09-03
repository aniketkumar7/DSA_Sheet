// QUESTION: PRINT KTH NODE FROM END

// PROBLEM STATEMENT:

// Given a linked list of N nodes. The task is to find the Kth node from the end of the linked list.

// EXAMPLE:

// Input:
// LinkedList: 1->2->3->4->5->6
// K = 3
// Output: 3

// ALGORITHM:
// 1. Traverse the linked list from head to tail
// 2. Again traverse the linked list from head to tail until the k equal to 0
// 3. When the k becomes 0, return the node

// SOLUTION:

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};


// Approach 1:

void Solve(Node* &head, int &k, int &ans){
    if(head == NULL){
        return;
    }

    // traverse the linked list from head to tail
    Solve(head->next, k, ans);

    // again traverse the linked list from head to tail until the k equal to 0
    // when k becomes 0, return the node
    if(k == 1){
        ans = head->data;
    }
    --k;
}

int getNode(Node *head, int k)
{
    int ans = -1;
    Solve(head, k, ans);
    return ans;
}


// Approach 2:
int findKthFromEnd(Node *head, int k)
{
    Node *first = head;
    Node *second = head;

    // Move first pointer k steps ahead
    for (int i = 0; i < k; ++i)
    {
        if (!first)
            return -1; // k is larger than the number of nodes
        first = first->next;
    }

    // Move both pointers until first reaches the end
    while (first)
    {
        first = first->next;
        second = second->next;
    }

    return second ? second->data : -1;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}



int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    print(head);
    int k = 4;
    cout << "The " << k << " node from the end is: " << endl;
    cout << getNode(head, k) << endl;
    cout << "The " << k << " node from the end is: " << endl;
    cout << findKthFromEnd(head, k) << endl;
    return 0;
}

