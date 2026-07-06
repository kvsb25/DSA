/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copy;
        Node* curr = head;
        Node* dummy = new Node(-1);

        while(curr != NULL){
            Node* newNode = new Node(curr->val);
            copy[curr] = newNode;
            curr = curr->next;
        }

        curr = head;

        while(curr != NULL){
            copy[curr]->next = copy[curr->next];
            copy[curr]->random = copy[curr->random];
            curr = curr->next;
        }

        return copy[head];
    }
};