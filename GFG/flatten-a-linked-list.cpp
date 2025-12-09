/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
  
    Node* merge(Node* left, Node* right){
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        while(left != NULL && right != NULL){
            if(left->data < right->data){
                temp->bottom = left;
                left = left->bottom;
                temp = temp->bottom;
            } else {
                temp->bottom = right;
                right = right->bottom;
                temp = temp->bottom;
            }
        }
        
        if(left){
            temp->bottom = left;
        }
        
        if(right){
            temp->bottom = right;
        }
        
        return dummy->bottom;
    }
    
    Node *flatten(Node *root) {
        if(root==NULL || root->next == NULL) return root;
        
        Node* list2 = flatten(root->next);
        
        return merge(root, list2);
    }
};