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
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);

        if(prev != NULL && root->val < prev->val){
            if(first == NULL){
                // first violation
                first = prev;
                middle = root;
            }else{
                last = root; // second violation
                // last = root and not prev because in second violation we want the smaller value as second violation is in later part of the inorder traversal which is having generally greater values (as it is ascending sorted order) 
            }
        }
        prev = root;

        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last){
            swap(first->val, last->val);
        }else if(first && middle){
            swap(first->val, middle->val);
        }
    }
};

// time complexity : O(n)

// correct inorder traversal is ascending order of the elements
// find the elements violating the ascending order, and swap them
// if two violating elements then swap them,
// if only 1 violating element then it should be swapped with the element next (adjacent) to it