class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s) {
            if (c == '[' || c == '(' || c == '{') {
                st.push(c);
            } else {
                // map can be used to reduce the size of code, particularly if else statements
                if (!st.empty()) {
                    if ((c == ']' && st.top() == '[') ||
                        (c == ')' && st.top() == '(') ||
                        (c == '}' && st.top() == '{')) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};