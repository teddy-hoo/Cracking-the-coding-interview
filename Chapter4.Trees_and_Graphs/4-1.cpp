/**
 * Chapter 4  --  4.1
 * Implement a function to check if a binary tree is balanced. For the purposes
 * of this question, a balanced tree is defined to be a tree such that the
 * heights of the two subtrees of any node never differ by more than one.
 */

/**
 * Author: Teddy
 * Date: 28-01-2015 
 */

/**
 * Analysis:
 * Recursive solution: recursively calculate the height of the left chhild and
 * right child, then compare the height.
 */

#include <iostream>
#include <stack>

using namespace std;

/**
 * Binary Tree
 */
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(NULL), right(NULL){}
};

int getHeight(TreeNode *root){
    
    if(root == NULL){
        return 0;
    }

    // use -1 denote that a tree is not balanced.

    int left = getHeight(root->left);
    if(left == -1){
        return -1;
    }
    int right = getHeight(root->right);
    if(right == -1){
        return -1;
    }

    if(left - right > 1 || right - left > 1){
        return -1;
    }

    return left > right ? left + 1 : right + 1;

}

bool isBalanced(TreeNode *root){

    return getHeight(root) > 0;

}

/**
 * Main function
 * normal case, edge case.
 * use a tree like below:
 *         5
 *      /     \
 *     3       7
 *   /   \   /   \
 *  2     4 6     8
 */
int main(){

    TreeNode *five  = new TreeNode(5);
    TreeNode *four  = new TreeNode(4);
    TreeNode *three = new TreeNode(3);
    TreeNode *two   = new TreeNode(2);
    TreeNode *six   = new TreeNode(6);
    TreeNode *seven = new TreeNode(7);
    TreeNode *eight = new TreeNode(8);

    five->left  = three;
    three->left = two;

    cout << isBalanced(five) << endl;

    three->right = four;
    five->right  = seven;
    seven->left  = six;
    seven->right = eight;

    cout << isBalanced(five) << endl;

    return 0;
}
