/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){
            return root;
        }

        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        } 
        
        // if both conditions are not true this means one of them is greater than root and the other is smaller than root, hence the node for which both conditions are not true is the common ancestor
        // else either p or q is the lowest common ancestor of both
        return root;
    }
};