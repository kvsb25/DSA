// User function Template for C++

class Solution {
  public:
  
    bool operand(const char c){
        return !(c == '+' || c == '-' || c == '*' || c == '/');
    }
    string postToPre(string s) {
        int i = 0;
        stack<string> st;
        
        while(i<s.size()){
            if(operand(s[i])){
                string op (1, s[i]);
                st.push(op);
            } else {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                string res = s[i] + t2 + t1;
                st.push(res);
            }
            i++;
        }
        
        return st.top();
    }
};