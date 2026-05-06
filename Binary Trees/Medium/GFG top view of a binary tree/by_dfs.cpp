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
    
    void func(Node *root, int row, int col, map<int, map<int, vector<int>>>& mp){
        if(root == NULL) return;
        mp[col][row].push_back(root->data);
        
        func(root->left, row+1, col-1, mp);
        func(root->right, row+1, col+1, mp);
        
        return;
    }
    
    vector<int> topView(Node *root) {
        map<int, map<int, vector<int>>> mp;
        vector<int> ans;
        
        func(root, 0, 0, mp);
        
        for(auto temp : mp){
            auto it = temp.second.begin();
            ans.push_back(it->second[0]);
        }
        
        return ans;
    }
};


// Best case time complexity: O(N Log N)
// Worst case time complexity: O(N Log N)

// Best case space: O(N)
// WOrst case space: O(N)