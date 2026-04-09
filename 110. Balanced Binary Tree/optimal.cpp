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
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int hLeft = height(root->left);
        int hRight = height(root->right);

        if(hLeft == -1 || hRight == -1) return -1;
        if(abs(hLeft-hRight) > 1) return -1;

        return 1+max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};