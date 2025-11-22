class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> st;
        unordered_map<char, char> ts;
        int n = s.size();
        for(int i = 0; i<n; i++){
                // if the curr char in s string has a mapping and it is not equal
            if((st.count(s[i]) && st[s[i]] != t[i]) || 
                (ts.count(t[i]) && ts[t[i]] != s[i])){
                return false;
            }
            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }

        return true;
    }
};

// a single char in any map cannot point to two distinct characters, if so return false
// if mapping for current char in 's' exists and it maps to something else other than the current char in 't', then the strings are not isomorphic
// IF CHAR OF STRING 's' PAIRS WITH CHAR OF STRING 't' ONCE, THEN THEY MUST PAIR WITH EACH OTHER EVERY SINGLE TIME.