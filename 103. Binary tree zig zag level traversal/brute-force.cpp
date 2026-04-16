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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            int size = st.size();
            vector<int> list;
            for(int i = 0; i<size; i++){
                TreeNode* node = st.front(); 
                st.pop();
                if(node->left != NULL) st.push(node->left);
                if(node->right != NULL) st.push(node->right);
                list.push_back(node->val);
            }
            ans.push_back(list);
        }

        for(int i = 0; i < ans.size(); i++){
            if(i%2 != 0){
                reverse(ans[i].begin(), ans[i].end());
            }
        }

        return ans;
    }
};

// Time complexity: O(nlogn)