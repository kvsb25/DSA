class Solution {
public:
    // function that returns the number of subarrays that have sum less than equal to goal
    int func(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int l = 0, r = 0, sum = 0, count = 0;

        while(r < nums.size()){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = func(nums, goal) - func(nums, goal-1);
        return ans;
    }
};

// try to find the number of subarrays with sum less than or equal to goal. Find this for 'goal' and 'goal-1'
// the difference of number of subarrays with sum less than or equal to goal and goal-1 would give us only the subarrays with sum equal to goal
// this is because func(goal) counts all the satifying subarray that are in func(goal-1).
// So the delta of those counts would be the count of subarrays that are equal to goal as we have removed all the subarrays with sum less than goal (which is same as less than or equal to goal-1 (considering int goal and i/p arr of 0s and 1s))