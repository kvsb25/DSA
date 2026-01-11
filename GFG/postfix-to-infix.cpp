// User function Template for C++

class Solution {
  public:
  
    bool operand(const char c){
        return !(c == '+' || c == '-' || c == '/' || c == '*');
    }
    
    string postToInfix(string &exp) {
        int i = 0;
        stack<string> st;
        
        while(i<exp.size()){
            // if an operand, push to stack
            if(operand(exp[i])){
                string op (1,exp[i]);
                st.push(op);
            // if operator, form infix of top 2 ele of stack and push res to stack
            } else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string res = '(' + t2 + exp[i] + t1 + ')';
                st.push(res);
            }
            i++;
        }
        
        return st.top();
    }
};