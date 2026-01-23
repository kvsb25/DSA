class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        string sub = "";
        int ans = 1;
        
        sub = sub + s[0];
        for(int i = 1; i < s.size(); i++){
            int j = 0;
            while(j<sub.size()){
                if(sub[j] == s[i]){
                    int len = sub.size();
                    ans = max(ans, len);
                    sub = sub.substr(j+1);
                    break;
                }
                j++;
            }
            sub = sub + s[i];
        }

        if(sub.size() > ans) ans = sub.size();
        return ans;
    }
};