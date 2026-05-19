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
    int inOrderSuccessor(Node *root, Node *k) {
        int succ = -1;
        
        while(root != NULL){
            if(root->data > k->data){
                // if curr val is greater than key, set it as successor and look for a smaller val
                succ = root->data;
                root = root->left;
            } else {
                // if curr val is smaller than key then look for a larger value because successor is obviously greater than key
                root = root->right;
            }
        }
        
        return succ;
    }
};

// Time complexity O(H); H = height of tree
// Space Complexity O(1);