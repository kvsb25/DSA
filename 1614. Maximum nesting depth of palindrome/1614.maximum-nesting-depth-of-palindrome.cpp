class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int count = 0;
        for(auto c : s){
            if(c == '('){
                count++;
                ans = max(count, ans);
            } else if(c == ')'){
                count--;
            }
        }
        return ans;
    }
};