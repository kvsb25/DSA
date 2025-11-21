class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());
        string first = strs[0], last = strs[strs.size()-1];
        for(int i = 0; i<min(first.size(), last.size()); i++){
            if(first[i] != last[i]){
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};

// sorting the strings array would help us retrieve lexicographically the greatest and the smallest among strings
// by that we would have to compare only the first and the last string in the sorted order as they will be sorted based on their prefixes only