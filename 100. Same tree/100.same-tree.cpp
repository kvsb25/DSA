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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // vector<int> ans;
        stack<TreeNode*> pst;
        stack<TreeNode*> qst;

        while(true){
            if(p != NULL && q != NULL){
                pst.push(p);
                qst.push(q);
                p = p->left;
                q = q->left;
            } else if(p == NULL && q == NULL){
                if(pst.empty() || qst.empty()) break; 
                p = pst.top();
                q = qst.top();
                pst.pop();
                qst.pop();
                if(p->val != q->val) return false;
                p = p->right;
                q = q->right;
            } else {
                return false;
            }
        }

        return true;
    }
};