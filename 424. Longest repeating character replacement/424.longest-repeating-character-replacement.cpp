class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int l = 0, r = 0, maxFreq = 0, maxLen = 0;
        while(r<s.size()){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            if((r-l+1)-maxFreq > k){
                mp[s[l]]--;
                l++;
            }
            if((r-l+1)-maxFreq <= k){
                maxLen = max(r-l+1, maxLen);
            }
            r++;
        }
        return maxLen;
    }
};

// increase right pointer always, and do whatever is necessary at every step (in this case it is calculating max freq char)
// increase left pointer (or shrink the subarray) only when conditions are not met 
//      (in this case the characters in the substring that can be converted should be less than 'k')
//      [chars that can be converted (in the substring) to give the max length of consecutive same char = length of the substring - the most appearing character]
// compute the answer when the conditions are met