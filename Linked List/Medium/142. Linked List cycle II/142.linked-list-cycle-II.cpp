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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;
        ListNode* curr = head;
        while(curr!=nullptr && curr->next!=nullptr){
            if(visited[curr] == true) return curr;
            visited[curr] = true;
            curr = curr->next;
        }
        return NULL;
    }
};