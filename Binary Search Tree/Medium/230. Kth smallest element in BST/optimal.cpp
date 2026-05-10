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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        int count = 0;
        while(true){
            if(node !=NULL){
                st.push(node);
                node = node->left;
            } else {
                if(st.empty()) break;
                node = st.top();
                st.pop();
                count++;
                if(count == k){
                    return node->val;
                }
                node = node->right;
            }
        }
        return -1;
    }
};

// Timecomplexity = O(height of tree) 
// SpaceComplexity = O(height of tree) because max elements stored at a time in the stack will be equal to the height of the tree, because we be popping elements whose left has been visited.
// Heigh of tree = Log N when the binary search tree is balanced 