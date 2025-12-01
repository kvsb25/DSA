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
    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        head2 = reverseLL(head2);
        while(head != NULL && head2 != NULL){
            if(head->val != head2->val) return false;
            head = head->next;
            head2 = head2->next;
        }
        
        return true;
    }
};

// find the mid node (first mid in case of even) then reverse the list post the mid node and assign 'head2'
// now traverse the original head (only if passed as copy and not reference) and head2 together while matching their node's values
// whenever their is mismatch in the values the list is not a palindrome hence return false.
// Now if the list length is odd, their will be 1 extra node in one of the lists (specifically the prior list after partition).
// while traversing both lists together one pointer will reach NULL first and the 'check loop' will terminate. 
// if the list is of odd length, even if we remove the mid node the list will still be a palindrome. So there is no need to worry about odd length lists
// so this approach works for odd lengths as in that case mid node won't be that valuable while checking palindrome.