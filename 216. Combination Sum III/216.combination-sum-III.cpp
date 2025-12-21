class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& combo, int k, int n, int sum, int index){
        if(sum > n){
            return;
        }
        if(k==0 && sum == n){
            ans.push_back(combo);
            return;
        }
        if(index>nums.size()-1){
            return;
        }

        combo.push_back(nums[index]);
        helper(nums, ans, combo, k-1, n, sum+nums[index], index+1);
        combo.pop_back();
        helper(nums, ans, combo, k, n, sum, index+1);

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> combo;

        helper(nums, ans, combo, k, n, 0, 0);

        return ans;
    }
};