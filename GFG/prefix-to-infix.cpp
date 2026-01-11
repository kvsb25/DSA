// User function Template for C++

class Solution {
  public:
    bool operand(const char c){
        return !(c == '+' || c == '-' || c == '*' || c == '/');
    }
    
    string preToInfix(string s) {
        int i = s.size()-1;
        stack<string> st;
        
        while(i>=0){
            // if an operand, push to stack
            if(operand(s[i])){
                string op (1, s[i]);
                st.push(op);
            // if operator, form infix of top 2 ele of stack and push res to stack
            } else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string res = '(' + t1 + s[i] + t2 + ')'; // the order is t1 and t2 as we are examining the string in reverse order
                st.push(res);
            }
            i--;
        }
        
        return st.top();
    }
};