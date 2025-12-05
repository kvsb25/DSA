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

    int getLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head=head->next;
        }
        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        if(lenA>lenB){
            int delay = lenA-lenB;
            while(delay-- > 0) headA=headA->next;
        } else if (lenA<lenB){
            int delay = lenB-lenA;
            while(delay-- > 0) headB=headB->next;
        }

        while(headA != NULL && headB != NULL){
            if(headA == headB) return headA;
            headA=headA->next;
            headB=headB->next;
        }

        return NULL;
    }
};

// time: O(n+m)
// space: O(1)
// find the lengths of both the linked lists to know which one's greater.
// if one of the lists has greater length, find how much greater and remove the delay
// then move the pointers together and returning whenever they first become equal (hence the intersection)