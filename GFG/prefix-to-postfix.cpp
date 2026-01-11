// User function Template for C++

class Solution {
  public:
    bool operand(const char c){
        return !(c=='+'||c=='-'||c=='*'||c=='/');
    }
    
    string preToPost(string s) {
        int i = s.size()-1;
        stack<string> st;
        
        while(i>=0){
            if(operand(s[i])){
                string op(1, s[i]);
                st.push(op);
            } else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string res = t1 + t2 + s[i];
                st.push(res);
            }
            i--;
        }
        
        return st.top();
    }
};