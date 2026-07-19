class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char, int> mp;

        for(auto c : s){
            mp[c]++;
        }

        if(!mp.count(x) || !mp.count(y)) return s;

        string res = "";
        while(mp.count(y) && mp[y]-- > 0){
            res += y;
        }
        mp.erase(y);
        for(auto p : mp){
            auto [c, times] = p;
            while(times-->0){
                res+=c;
            }
        }

        return res;
        
    }
};