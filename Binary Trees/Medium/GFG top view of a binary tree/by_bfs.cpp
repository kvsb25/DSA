/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            Node* node = it.first;
            int col = it.second;
            
            if(mp.find(col) == mp.end()) mp[col] = node->data;
            
            if(node->left != NULL){
                q.push({node->left, col-1});
            }
            if(node->right != NULL){
                q.push({node->right, col+1});
            }
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

// Best case time complexity : O(N)
// Worst case time complexity: O(N Log N)

// Best case space : O(1)
// Worst case space : O(N)