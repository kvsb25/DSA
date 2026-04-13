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
class Solution {
public:
    int sum(TreeNode* root, int& max_sum){
        if(root == NULL) return 0;

        int lSum = max(0, sum(root->left, max_sum)); 
        int rSum = max(0, sum(root->right, max_sum));

        max_sum = max(max_sum, lSum+rSum+root->val);
        
        return root->val + max(lSum, rSum);
    }

    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        sum(root, max_sum);
        return max_sum;
    }
};


// NOTE: get the 0 logic in max(0, sum(...)) right, because it is considering that if left and right both are negative then adding them will obviously be less than the root node value (if root->val is positive)
// if the root itself is negative then the max_sum = max(...) will handle it.
// (because addition of negative values in subtraction)