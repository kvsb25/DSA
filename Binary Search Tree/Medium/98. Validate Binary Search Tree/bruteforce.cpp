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
    void func(TreeNode* root, vector<int>& inorder){
        if(root == NULL) return;

        func(root->left, inorder);
        inorder.push_back(root->val);
        func(root->right, inorder);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> inorder;

        func(root, inorder);
        bool ans = true;

        for(int i = 0; i < inorder.size()-1; i++){

            // if the array is not sorted or has consecutive duplicate element if sorted, then it is not a binary search tree because inorder traversal of a binary search tree is in strict ascending order and does not contain duplicate elements.
            if(inorder[i] >= inorder[i+1]){
                ans = false;
                break;
            }
        }

        return ans;
    }
};