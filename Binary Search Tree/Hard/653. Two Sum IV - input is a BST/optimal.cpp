/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator{
    stack<TreeNode*> st;
    bool reverse;

public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(reverse){
            pushAll(temp->left);
        } else {
            pushAll(temp->right);
        }
        return temp->val;
    }

private:
    void pushAll(TreeNode* node){
        for(; node!=NULL;){
            st.push(node);
            if(reverse){
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator it1(root, false);
        BSTIterator it2(root, true);
        int i = it1.next();
        int j = it2.next();

        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = it1.next(); // move to next larger element from the start
            else j = it2.next(); // move to next smaller element form the end
        }

        return false;
    }
};

// Time complexity: O(N)
// space complexity: O(2*H)

// Use BST Iterator to iterate a BST in inorder (sorted in ascending order)
// and use a reversed BST iterator to iterate a BST in reverse inorder (sorted in descending order)
// while iterating the sorted array (BST in inorder form first element and last element) check if their sum if greater than, less than or equal to the target