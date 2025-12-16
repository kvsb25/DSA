class Solution {
  public:
  
    void insert(stack<int> &st, int val){

        if(st.empty()){
            st.push(val);
            return;
        }
        
        if(st.top()<val){
            st.push(val);
            return;
        } else {
            int top = st.top();
            st.pop();
            insert(st, val);
            st.push(top);
            return;
        }
        return;
    }
    
    void sortStack(stack<int> &st) {
        
        if(st.empty()) return;
        
        int curr = st.top();
        st.pop();
        
        sortStack(st);
        insert(st, curr);
        
        return;
    }
};