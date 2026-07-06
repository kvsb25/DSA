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
        while (n > 0){
            first = first->next;
            n--;
        }

        while (first != NULL && first->next != NULL) {
            first = first->next;
            second = second->next;
        }

        if(first != NULL){
            ListNode* toDelete = second->next;
            second->next = second->next->next;
            delete toDelete;
        } else {
            head = second->next;
            delete second;
        }

        return head;
    }
};