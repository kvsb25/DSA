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
    ListNode* reverseKNodes(ListNode* head, int k, int times){
        ListNode* curr = head;
        ListNode* next = head;
        ListNode* prev = NULL;

        if(times <= 0) return next;

        int count = k;
        while(count > 0 && curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

            count--;
        }
        times--;

        if(next != NULL){
            head->next = reverseKNodes(next, k, times);
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int size = 0;

        while(temp != NULL){
            size++;
            temp = temp->next;
        }

        int times = size/k;

        return reverseKNodes(head, k, times);
    }
};