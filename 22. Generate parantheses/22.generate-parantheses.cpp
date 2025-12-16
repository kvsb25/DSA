class Solution {
public:

    void helper(int n, int open_count, int close_count, string& str, vector<string>& ans){
        if(open_count == n && close_count == open_count) {
            ans.push_back(str);
            return;
        }
        if(open_count > n || close_count > open_count){
            return;
        }

        str.push_back('(');
        helper(n, open_count+1, close_count, str, ans);
        str.pop_back();
        str.push_back(')');
        helper(n, open_count, close_count+1, str, ans);
        str.pop_back();

        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        helper(n, 0, 0, str, ans);
        return ans;
    }
};