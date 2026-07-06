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
    ListNode* rotateRight(ListNode* head, int k) {

        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }

        if(size == 0 || k == 0 || size == k) return head;

        // find effective number of rotations
        k = k%size;

        ListNode* first = head, * second = head;

        // add a moving delay between first and second pointer equal to the number of rotations
        while(k-->0){
            first = first->next;
        }


        while(first->next!=NULL){
            first = first->next;
            second = second->next;
        }

        // move the list after second node to the start of the list to perform rotation
        first->next = head;
        head = second->next;
        second->next = NULL;

        return head;
    }
};