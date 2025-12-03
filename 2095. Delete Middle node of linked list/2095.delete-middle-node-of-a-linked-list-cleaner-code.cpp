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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode* first = head;
        ListNode* second = head;
        ListNode* prev = NULL;

        while(first != NULL && first->next != NULL){
            prev = second;
            second = second->next;
            first = first->next->next;
        }

        if(prev){
            prev->next = second->next;
        } else {
            head = second->next;
        }
        
        delete second;
        return head;
    }
};