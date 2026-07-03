class Solution {
public:
    static vector<string> str;
    string removeOuterParentheses(string s) {
        int count = 0;
        string result = "";
        for(int i = 0 ; i<s.length(); i++){
            if(s[i] == '('){
                if(count > 0){
                    result += s[i];
                }
                count ++;
            } else {
                count--;
                if(count > 0){
                    result += s[i];
                }
            }
        }

        return result;
    }
};