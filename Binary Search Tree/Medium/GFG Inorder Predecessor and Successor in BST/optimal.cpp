/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* succ = NULL, *pred=NULL;
        
        Node* temp = root;
        
        while(temp != NULL || root != NULL){
            if(temp != NULL){
                if(temp->data < key){
                    pred = temp;
                    temp = temp->right;
                } else {
                    temp = temp->left;
                }
            }
            
            if(root != NULL){
                if(root->data > key){
                    succ = root;
                    root = root->left;
                } else {
                    root = root->right;
                }
            }
        }
        
        return {pred, succ};
    }
};

// Time complexity O(H); H = height of tree
// Space complexity O(1)