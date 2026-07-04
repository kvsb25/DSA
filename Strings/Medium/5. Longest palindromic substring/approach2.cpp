class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int maxLen = 0;
        
        for(int i = 0; i < s.size(); i++){
            int currLen = 0;
            // odd palindrome
            int l = i, r = i;

            while(l >= 0 && r <= s.size() && s[l] == s[r]){
                currLen = r-l+1;
                if(currLen > maxLen){
                    maxLen = currLen;
                    res = s.substr(l, currLen);
                }
                l--; r++;
            }

            l = i; r = i+1;

            while(l >= 0 && r <= s.size() &&  s[l] == s[r]){
                currLen = r-l+1;
                if(currLen > maxLen){
                    maxLen = currLen;
                    res = s.substr(l, currLen);
                }
                l--; r++;
            }
        }
        return res;
    }
};