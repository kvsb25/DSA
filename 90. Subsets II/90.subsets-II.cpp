class Solution {
public:

    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& sub, int index){
        if(index >= nums.size()){
            return;
        }

        // include the current element and go to the next element
        sub.push_back(nums[index]);
        ans.push_back(sub);

        helper(nums, ans, sub, index+1);

        // don't include the current element and go to the next element
        sub.pop_back();

            // as we are not including the current element, we don't want the next element to be same as the current as we don't want duplicate subsets and we are not including the current element
            // so skipping the duplicates if any
        while(index+1 < nums.size() && nums[index] == nums[index+1]){
            index++;
        }
        helper(nums, ans, sub, index+1);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        vector<int> sub;

        sort(nums.begin(), nums.end());
        helper(nums, ans, sub, 0);
        return ans;
    }
};

// Both calls go to index+1, but they represent different choices:
// 1) First call: nums[index] was INCLUDED (sub already has it)
// 2) Second call: nums[index] was EXCLUDED — we skip ALL duplicates
//    using the while loop, so index jumps to the next *new* value.
// Hence, same f(index+1) call, but with different "state" (sub contents),
// which is what generates all unique subsets.