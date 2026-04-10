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
    int height(TreeNode* root, int& diam){
        if(root == NULL) return 0;

        int leftH = height(root->left, diam);
        int rightH = height(root->right, diam);

        diam = max(diam, leftH+rightH);

        return 1+max(leftH, rightH);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        height(root, diam);
        return diam;
    }
};