class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        set<int> st{};
        for (auto i : nums) {
            st.insert(i);
        }
        set<int>::iterator itf = st.begin();
        set<int>::iterator its = st.begin();
        advance(its, 1);
        int longest = 0;
        int max = 0;
        while (itf != st.end()) {
            int diff = abs(*(its) - *(itf));
            if (diff == 1) {
                longest++;
            } else {
                longest++;
                if (longest > max) {
                    max = longest;
                }
                longest = 0;
            }
            if (longest > max) {
                max = longest;
            }
            itf++;
            its++;
        }
        return max;
    }
};