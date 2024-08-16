// Construct String from Binary Tree

// Problem Statement :
// Given the root node of a binary tree, your task is to create a string representation of the tree following a specific set of formatting rules. The representation should be based on a preorder traversal of the binary tree and must adhere to the following guidelines:

// Node Representation: Each node in the tree should be represented by its integer value.

// Parentheses for Children: If a node has at least one child (either left or right), its children should be represented inside parentheses. Specifically:

// If a node has a left child, the value of the left child should be enclosed in parentheses immediately following the node's value.
// If a node has a right child, the value of the right child should also be enclosed in parentheses. The parentheses for the right child should follow those of the left child.
// Omitting Empty Parentheses: Any empty parentheses pairs (i.e., ()) should be omitted from the final string representation of the tree, with one specific exception: when a node has a right child but no left child. In such cases, you must include an empty pair of parentheses to indicate the absence of the left child. This ensures that the one-to-one mapping between the string representation and the original binary tree structure is maintained.

// In summary, empty parentheses pairs should be omitted when a node has only a left child or no children. However, when a node has a right child but no left child, an empty pair of parentheses must precede the representation of the right child to reflect the tree's structure accurately.

// Example 1:
// Input: root = [1,2,3,4]
// Output: "1(2(4))(3)"
// Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the empty parenthesis pairs. And it will be "1(2(4))(3)".

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string tree2str(TreeNode *root)
{
    if (root == NULL)
        return "";

    string result = to_string(root->val);
    string Left = tree2str(root->left);
    string Right = tree2str(root->right);

    if (root->left == NULL && root->right == NULL)
        return result;

    if (root->left == NULL)
        return result + "()" + "(" + Right + ")";

    if (root->right == NULL)
        return result + "(" + Left + ")";

    return result + "(" + Left + ")" + "(" + Right + ")";
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    cout << "Tree: ";
    cout << root->val << " ";
    cout << root->left->val << " ";
    cout << root->right->val << " ";
    cout << root->left->right->val << " ";

    cout << "\nString: ";
    cout << tree2str(root) << endl;
    return 0;
}

//         1
//        / \
//       2   3
//        \
//         4

// Tree Representation
// Root Node: 1
// Left Child of 1: 2
// Right Child of 1: 3
// Right Child of 2: 4
