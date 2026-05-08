/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findMin(Node *root) {
        if(root == NULL) return -1;
        
        if(root->left == NULL){
            return root->data;
        }
        
        return findMin(root->left);
    }

    int findMax(Node *root) {
        if(root == NULL) return -1;
        
        if(root->right == NULL){
            return root->data;
        }
        
        return findMax(root->right);
    }
};