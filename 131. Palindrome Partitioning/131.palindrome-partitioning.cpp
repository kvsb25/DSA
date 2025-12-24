class Solution {
public:

    bool isPal(string& s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }

    void dfs(int i, string& s, vector<string>& part, vector<vector<string>>& ans){
        if(i >= s.length()){
            ans.push_back(part);
            return;
        }
        for(int j = i; j<s.length(); j++){
            if(isPal(s, i, j)){
                part.push_back(s.substr(i, j-i+1));
                dfs(j+1, s, part, ans);
                part.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;

        dfs(0, s, part, ans);

        return ans;
    }
};