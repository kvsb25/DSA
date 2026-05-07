/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int, int> mp;
        
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto it = q.front();
                q.pop();
                
                Node* node = it.first;
                int col = it.second;
                
                mp[col] = node->data;
                
                if(node->left != NULL){
                    q.push({node->left, col-1 });
                }
                
                if(node->right != NULL){
                    q.push({node->right, col+1});
                }
            }
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};