/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class NodeValue{
public:
    int maxNode, minNode, sum;

    NodeValue(int mn, int mx, int sm){
        this->minNode = mn;
        this->maxNode = mx;
        this->sum = sm;
    }
};

class Solution {
public:
    NodeValue largestBST(TreeNode* root, int& maxSum){
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        };

        auto left = largestBST(root->left, maxSum);
        auto right = largestBST(root->right, maxSum);

        // if a valid bst then calculate sum and other attributes
        if(left.maxNode < root->val && root->val < right.minNode){
            int currSum = left.sum + right.sum + root->val;
            maxSum = max(currSum, maxSum); // assigning the max sum for this iteration. currSum is the sum of this valid BST
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), currSum); // assigning the max and min node value for this valid binary search tree

            // if it is a valid BST then left.minNode would be the minimum of the current BST and right.maxNode would be the max for the BST
            // ONLY IF both children are present
            // min(root->val, left.minNode), max(root->val, right.maxNode) is to handle missing children as in case of missing children the min or max of the current tree would be the root if left or right is missing respectively
            // We use min and max so that if a left or right child is missing (returning dummy values like INT_MAX or INT_MIN), the root itself correctly defaults to being the minimum or maximum of its subtree.
        }

        // else if not a bst
        return NodeValue(INT_MIN, INT_MAX, max(left.sum, right.sum)); // if not BST then return the value for sub binary tree that is a BST
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        largestBST(root, maxSum);
        return maxSum >= 0 ? maxSum : 0;
    }
};