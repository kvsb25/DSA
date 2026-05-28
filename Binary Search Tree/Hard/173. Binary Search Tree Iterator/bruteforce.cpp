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
class BSTIterator {
public:
    vector<int> traversal;
    int idx;

    BSTIterator(TreeNode* root) {
        inorder(root);
        idx = -1;
    }

    void inorder(TreeNode* root){
        if(root == NULL) return;

        inorder(root->left);
        this->traversal.push_back(root->val);
        inorder(root->right);
    }
    
    int next() {
        return traversal[++idx];
    }
    
    bool hasNext() {
        return idx+1 < traversal.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */