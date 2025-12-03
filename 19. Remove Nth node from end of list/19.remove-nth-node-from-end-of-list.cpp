/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL || head->next == NULL) return NULL;

        ListNode* first = head;
        ListNode* second = head;

        // create delay of n steps between first and second pointers
        while (n > 0){
            first = first->next;
            n--;
        }

        // if first not pointing to last node, move the first and second to the end of the list while maintaining the delay
        while (first != NULL && first->next != NULL) {
            first = first->next;
            second = second->next;
        }

        // if first == NULL this means n = size of the list and hence deletion at head must take place
        if(first != NULL){
            ListNode* toDelete = second->next;
            second->next = second->next->next;
            delete toDelete;
        } else {
            // delete at head
            head = second->next;
            delete second;
        }

        return head;
    }
};

// maintain two pointers and update one with a delay of n steps