class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int l = 0, r = 1;
        while(l < s.size()){
            if(s[l] == s[r]){
                while(s[l] == s[r] && r < s.size()){
                    r++;
                }
                int diff = r-l;
                if(diff >= 3){
                    ans.push_back({l, r-1});
                }
                l = r;
                r = l+1;
            } else {
                l += 1;
                r += 1;
            }
        }

        return ans;
    }
};