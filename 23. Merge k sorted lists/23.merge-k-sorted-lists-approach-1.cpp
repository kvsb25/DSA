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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i = 0; i < lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                pq.push(temp->val);  // time com: k log(N)
                temp = temp->next;
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* head = dummy;

        while(!pq.empty()){
            int ele = pq.top();
            pq.pop();  // N log(N)
            
            ListNode* newNode = new ListNode(ele);
            head->next = newNode;
            head = head->next;
        }

        return dummy->next;
    }
};

// Time Complexity : O(N logN), where N = all the nodes across all linked list
// Space Complexity: O(N)