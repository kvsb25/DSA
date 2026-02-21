class Solution {
public:

    bool func(int idx, string s, int count){
        if(count < 0) return false;
        if(idx == s.size()) return count == 0;

        if(s[idx] == '('){

            return func(idx+1, s, count+1);
        } else if(s[idx] == ')'){
            return func(idx+1, s, count-1);
        } else {
            return func(idx+1, s, count+1) || func(idx+1, s, count-1) || func(idx+1, s, count);
        }

        return true;
    }

    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> memo(n*n, false);
        return func(0, s, 0, memo);
    }
};

// Time complexity: O(3^n)
// Space complexity: O(n)
// where n is the length of the input string