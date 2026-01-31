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
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;

        for(auto list: lists){
            if(list != NULL)
                pq.push({list->val, list});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            ListNode* node = top.second;
            tail->next = node;
            tail = tail->next;

            if(node->next!= NULL)
                pq.push({node->next->val, node->next});

        }   // size of pq will not become more than 'k' (size of input array) because we store the whole list only as an element

        return dummy->next;
    }
};

// Time Complexity : O(N logk) where N = all the nodes across all the linked lists, k = size of input array
// Space Complexity : O(k)