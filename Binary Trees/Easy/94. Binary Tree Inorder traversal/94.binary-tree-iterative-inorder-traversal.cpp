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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            } else {
                if(st.empty()) break; 
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }
};

// NOTE: the stack keeps track of those nodes whose right subtree has not yet been explored
// meaning the stack contains those elements whose left subtree is being explored and if the left subtree has been explored then the element is popped from the stack.
// How do we know if the left subtree has been explored? -> when we encounter a null node then the top of stack's left subtree has been explored hence we can pop it and check it's right subtree (hence node = node->right).
// since we always moved to the left of the node, if we encounter a null element this would mean that we have explored the left subtree of the latest parent in the stack, hence according to inorder traversal it is time to record the element in the traversal and find the inorder traversal of the right subtree