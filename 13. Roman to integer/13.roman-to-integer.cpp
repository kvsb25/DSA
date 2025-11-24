class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        for(int i = 0; i<s.length()-1; i++){
            int curr = mp[s[i]], next = mp[s[i+1]];
            if(curr < next){
                value -= mp[s[i]];
            } else {
                value += mp[s[i]];
            }
        }
        value += mp[s[s.length()-1]];
        return value;
    }
};