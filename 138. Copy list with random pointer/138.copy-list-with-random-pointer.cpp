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

        if(head == NULL) return NULL;
        Node* temp = head;

        // add deep copied nodes in between
        while (temp != NULL) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }

        temp = head;

        // define random of the copied nodes. random of copy node will be the next of the random of original node.
        while (temp != NULL) {
            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            } else {
                temp->next->random = NULL;
            }
            temp = temp->next->next;
        }

        Node* copy = head->next;
        Node* res = copy;
        temp = head;

        // separate the two lists
        while(temp != NULL){
            temp->next = res->next;
            temp = temp->next;
            res->next = temp? temp->next : NULL;
            res = res->next;
        }

        // return the head of the copied list
        return copy;
    }
};
