/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node->next->next != NULL){
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        node->next = NULL;
    }
};

// replace the value of given node with the value of the next node
// move to the next node and repeat the same until node->next->next == NULL
// at node where node->next->next == NULL, replace its value by the value of its next and then make node->next = NULL in order to remove the last redundant node from the list