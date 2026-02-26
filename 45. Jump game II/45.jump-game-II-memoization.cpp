class Solution {
public:
    int func(vector<int>& nums, int i, int jumps, vector<vector<int>> memo){
        int n = nums.size();
        if(i >= n-1) return jumps;

        int mini = INT_MAX;
        for(int j = 1; j <= nums[i]; j++){
            if(i+j <= n-1 && jumps+1 <= n-1){
                if(memo[i+j][jumps+1] == -1) memo[i+j][jumps+1] = func(nums, i+j, jumps+1, memo);
                mini = min(mini, memo[i+j][jumps+1]);
                // mini = min(mini, func(nums, i+j, jumps+1, memo));
            }
        }

        return mini;
    }

    int jump(vector<int>& nums) {
        vector<vector<int>> memo (nums.size(), vector<int>(nums.size(),-1));
        return func(nums, 0, 0, memo);
    }
};