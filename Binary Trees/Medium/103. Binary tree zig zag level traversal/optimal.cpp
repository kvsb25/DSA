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
        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> list(size); // initialize here only to dogde out of bounds error
            for(int i = 0; i<size; i++){
                TreeNode* node = q.front(); 
                q.pop();

                int index = (leftToRight) ? i : size - 1 - i;
                list[index] = (node->val);

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            leftToRight = !leftToRight; // toggle traversal direction after each level traversal
            ans.push_back(list);
        }

        return ans;
    }
};

// Time Complexity: O(n)