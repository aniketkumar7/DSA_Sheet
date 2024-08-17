// Flatten a Linked List

// Problem Statement

// Given a Linked List, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked lists is in sorted order.
// Flatten the Link List so all the nodes appear in a single level while maintaining the sorted order.

// Note: The flattened list will be printed using the bottom pointer instead of the next pointer. Look at the printList() function in the driver code for more clarity.

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* bottom;

        Node (){
            this->data = 0;
            this->next = NULL;
            this->bottom = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->bottom = NULL;
        }
};

Node* MergeList(Node* a, Node* b){

    if(!a) return b;

    if(!b) return a;

    Node* result = NULL;

    if(a->data < b->data){
        result = a;
        result->bottom = MergeList(a->bottom, b);
    }

    else{
        result = b;
        result->bottom = MergeList(a, b->bottom);
    }

    return result;
}


Node* flatten(Node* root){

    if(!root || !root->next) return root;

    root->next = flatten(root->next);

    root = MergeList(root, root->next);

    return root;

}

void printList(Node* node){

    while(node != NULL){
        cout << node->data << " ";
        node = node->bottom;
    }

}


int main(){
    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);

    head->next->bottom = new Node(20);
    head->next->next->bottom = new Node(22);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);

    cout << "Flattened Linked List: ";
    head = flatten(head);
    printList(head);
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

// Tree Representation

//           5
//         /   \
//        7     10
//       / \     \
//      8   20    22
//         /       \
//        19        28
//                   \
//                    35
//                     \
//                      40