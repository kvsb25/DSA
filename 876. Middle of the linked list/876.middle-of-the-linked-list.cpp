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
    ListNode* middleNode(ListNode* head) {
        ListNode* firstPtr = head;
        ListNode* secPtr = head;
        while(secPtr != NULL && secPtr->next != NULL){
            firstPtr = firstPtr->next;
            secPtr = secPtr->next->next;
        }
        return firstPtr;
    }
};

// have two pointers, first and second
// move the second pointer two places while the first pointer only one place at a time.
// terminate the traversal when the second pointer either reaches NULL or its next points to NULL
// so let the loop terminate until the condition (secPtr != NULL && secPtr->next != NULL) is true; 
// also known as TortoiseHare method 