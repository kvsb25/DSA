class Solution {
public:
    void helper(unordered_map<char, string>& map, string& digits, vector<string>& ans, string& currStr, int i){
        if(currStr.length() == digits.length()){
            ans.push_back(currStr);
            return;
        }

        for(auto c : map[digits[i]]){
            string temp = currStr + c;
            helper(map, digits, ans, temp, i+1);
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        vector<string> ans;
        string currStr;

        helper(map, digits, ans, currStr, 0);

        return ans;
    }
};