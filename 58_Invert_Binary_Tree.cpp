// Question: Invert Binary Tree
// Question URL: https://leetcode.com/problems/invert-binary-tree/
// Level: Easy

// Problem Statement:
// Given the root of a binary tree, invert the tree, and return its root.

// Example 1:
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

// Example 2:
// Input: root = [2,1,3]
// Output: [2,3,1]

// Example 3:
// Input: root = []
// Output: []


// Approach:

// Breadth-First Traversal:

// We use a queue to perform a level-order traversal of the tree.
// Nodes are processed level by level, and their children are added to the queue.
// Printing Format:

// The tree is printed in a list format with values separated by commas.
// nullptr nodes are skipped to maintain the structure of the tree.
// Edge Case:

// If the tree is empty, we print [].



// Code :

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *invertTree(TreeNode *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// Print the tree level by level
void printTree(TreeNode *root)
{
    if (root == nullptr)
    {
        cout << "[]" << endl;
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    cout << "[";
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node)
        {
            cout << node->val;
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            continue;
        }

        if (!q.empty())
        {

            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    cout << "Original Tree: ";
    printTree(root);

    TreeNode *invertedRoot = invertTree(root);

    cout << "Inverted Tree: ";
    printTree(invertedRoot);

    return 0;
}






// Time and Space Complexity:

/// Time Complexity
// Initialization:

// Pushing the root node into the queue takes (O(1)) time.
// Traversal:

// Each node is processed exactly once.
// For each node, we perform constant-time operations: printing the value, pushing left and right children into the queue.
// Therefore, the traversal takes (O(n)) time, where (n) is the number of nodes in the tree.
// Overall Time Complexity:
// The overall time complexity is (O(n)).

/// Space Complexity
// Queue:

// In the worst case, the queue will store all the nodes at the deepest level of the tree.
// For a balanced binary tree, the maximum number of nodes at the deepest level is (O(n/2)), which simplifies to (O(n)).
// Output:

// The output string requires space proportional to the number of nodes, which is (O(n)).
// Overall Space Complexity:
// The overall space complexity is (O(n)).