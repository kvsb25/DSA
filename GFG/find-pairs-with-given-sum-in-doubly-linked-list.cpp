// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        vector<int> dll;
        while(head != NULL){
            dll.push_back(head->data);
            head = head->next;
        }
        int i = 0, j = dll.size()-1;
        vector<pair<int,int>> ans;
        while(i<j){
            int sum = dll[i]+dll[j];
            if(sum == target){
                ans.push_back({dll[i], dll[j]});
                i++;j--;
            }else if(sum>target){
                j--;
            } else {
                i++;
            }
        }
        return ans;
    }
};