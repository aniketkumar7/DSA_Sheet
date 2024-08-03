// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.


// Algorithm:

// Step 1: 🔢 Initialize Variables
//      - Initialize two variables num1 and num2 to store the values of the
//        linked lists l1 and l2 respectively.
//      - Initialize a variable dummy to store the head of the new linked list.

// Step 2: 🔄 Loop until l1 is NULL
//      - In each iteration, multiply the current value of num1 by 10 and add
//        the value of the current node l1->val to get the new value of num1.
//      - Move to the next node l1 = l1->next.

// Step 3: 🔄 Loop until l2 is NULL
//      - In each iteration, multiply the current value of num2 by 10 and add
//        the value of the current node l2->val to get the new value of num2.
//      - Move to the next node l2 = l2->next.

// Step 4: 🆕 Create a new node with the sum of the ones digit
//      - Create a new node with the sum of the ones digit (num1 + num2) % 10 //
//        and store it as the value.
//      - Set the head of the new linked list to this new node.

// Step 5: 🔢 Calculate the carry
//      - Calculate the carry (num1 + num2) / 10.

// Step 6: 👆 Keep track of the last node
//      - Initialize a variable current to store the last node of the new
//        linked list.

// Step 7: 🔄 Loop until carry is 0
//      - In each iteration, get the ones digit of the carry carry % 10 and
//        create a new node with this value.
//      - Update the carry by dividing it by 10 carry /= 10.
//      - Move to the next node current = current->next.

// Step 8: 🏁 Return the head of the new linked list
//      - Return the head of the new linked list dummy.




#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;        //  Value stored in the node
    ListNode *next; // 🔗 Pointer to the next node

    ListNode()
    {
        val = 0;     //  Default value is 0
        next = NULL; // 🚫 Initially, no next node
    }

    ListNode(int x)
    {
        val = x;     //  Value is set to x
        next = NULL; // 🚫 Initially, no next node
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // 🔢 Variables to store the values of the linked lists
    int num1 = 0, num2 = 0;

    // 🔄 Loop until l1 is NULL
    while (l1)
    {
        num1 = num1 * 10 + l1->val; // 🔢 Convert linked list to number
        l1 = l1->next;              // 🚶‍♂️ Move to the next node
    }

    //  🔄 Loop until l2 is NULL
    while (l2)
    {
        num2 = num2 * 10 + l2->val; // 🔢 Convert linked list to number
        l2 = l2->next;              // 🚶‍♂️ Move to the next node
    }

    // 🆕 Create a new node with the sum of the ones digit
    ListNode *dummy = new ListNode((num1 + num2) % 10);

    // 🔢 Calculate the carry
    int carry = (num1 + num2) / 10;

    // 👆 Keep track of the last node
    ListNode *current = dummy;

    // 🔄 Loop until carry is 0
    while (carry > 0)
    {
        int val = carry % 10;              // 🔢 Get the ones digit of the carry
        carry = carry / 10;                // 🔢 Update the carry
        current->next = new ListNode(val); // 🆕 Create a new node with the carry digit
        current = current->next;           // 🚶‍♂️ Move to the next node
    }

    // 🏁 Return the head of the new linked list
    return dummy;
}

int main()
{
    // 🆕 Create the first linked list
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // 🆕 Create the second linked list
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // 🆕 Call the function to add the two numbers
    ListNode *result = addTwoNumbers(l1, l2);

    cout << "Resultant linked list: ";
    // 🔄 Loop until the end of the result
    while (result != NULL)
    {
        cout << result->val << " "; // 🖨️ Print the value of the current node
        result = result->next;      // 🚶‍♂️ Move to the next node
    }
    cout << endl;

    return 0;
}

// Dry run:

// Let's consider the example input:

// l1: 2 👉 4 👉 3
// l2: 5 👉 6 👉 4

// num1 and num2 are initialized to 0. 🔢

// Iterate over l1: 🔄

// num1
//  = 0 * 10 + 2 = 2

// num1
//  = 2 * 10 + 4 = 24

// num1
//  = 24 * 10 + 3 = 243

// l1 is NULL now 🚫


// Iterate over l2: 🔄

// num2
//  = 0 * 10 + 5 = 5

// num2
//  = 5 * 10 + 6 = 56

// num2
//  = 56 * 10 + 4 = 564

// l2 is NULL now 🚫

// A new node is created with val
//  = (243 + 564) % 10 = 7. 🆕
// ListNode dummy becomes 7 till now.

// carry is calculated as (243 + 564) / 10 = 80. 🔢

// current is set to the new node (7). 👆

// Iterate over the carry and adding the nodes until carry = 0: 🔄

// val = 80 % 10 = 0,
// A new node with val = 0 is created and added to current . 🆕

// carry = 80 / 10 = 8

// val = 8 % 10 = 8,
// A new node with val = 8 is created and added to current . 🆕

// carry
//  = 8 / 10 = 0

// The
// dummy
//  pointer (pointing to the head of the new linked list) is returned. 🏁

// The final result is: 🎉
// 7 👉 0 👉 8 which represents 807
