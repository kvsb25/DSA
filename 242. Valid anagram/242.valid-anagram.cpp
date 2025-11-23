class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();
        if(n != m) return false;

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for(int i = 0; i < n; i++){
            sMap[s[i]]++; tMap[t[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(!tMap.count(s[i])) return false;
            if(sMap[s[i]] != tMap[s[i]]) return false;
        }
        return true;
    }
};