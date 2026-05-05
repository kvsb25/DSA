class Solution {
public:
    void func(TreeNode* root, int row, int col, map<int, map<int, multiset<int>>>& mp){
        if(root == NULL) return;

        mp[col][row].insert(root->val);
        func(root->left, row+1, col-1, mp);
        func(root->right, row+1, col+1, mp);

        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        vector<vector<int>> ans;
        func(root, 0, 0, mp);

        for(auto pr : mp){
            vector<int> temp;
            for(auto p : pr.second){
                temp.insert(temp.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(temp);
        }

        return ans;
    }
};