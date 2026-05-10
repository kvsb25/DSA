/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findMin(TreeNode* root) {
        if (root == NULL)
            return NULL;

        if (root->left == NULL)
            return root;
        return findMin(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val == key) {
            if (root->left == NULL && root->right == NULL) {
                return NULL;
            } else if (root->right == NULL) {
                return root->left;
            } else if (root->left == NULL) {
                return root->right;
            } else {
                // root here is the node with the key value
                // root->right ke minimum ke left ko root->left krdo
                TreeNode* temp = findMin(root->right);
                temp->left = root->left;
                root->left = NULL;
                temp = root->right;
                root->right = NULL;

                // delete root to prevent memory leak/dangling pointers
                delete root;
                root = NULL;

                // return the updated tree's root
                return temp;
            }
        } else if(root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if(root->val < key) {
            root->right = deleteNode(root->right, key);
        }

        return root;
    }
};