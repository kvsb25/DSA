class Solution {
  public:
  
    void helper(stack<int> &st, stack<int> &st2){
        if(st.empty()) return;
        
        int top = st.top();
        st.pop();
        helper(st, st2);
        st2.push(top);
        return;
    }
    
    void reverseStack(stack<int> &st) {
        stack<int> st2;
        helper(st, st2);
        
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        
        return;
    }
};