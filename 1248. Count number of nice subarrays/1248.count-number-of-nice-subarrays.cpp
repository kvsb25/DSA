class Solution {
public:
    // function to find number of subarrays with less than k odd numbers
    int func(vector<int>& nums, int k) {
        if(k < 0) return 0;
        int l = 0, r = 0, oddNums = 0, count = 0;

        while (r < nums.size()) {
            if (nums[r] % 2 != 0)
                oddNums++;
            while (oddNums > k) {
                if (nums[l] % 2 != 0)
                    oddNums--;
                l++;
            }
            if (oddNums <= k)
                count += r-l+1;
            r++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = abs(func(nums, k) - func(nums, k-1));
        return res;
    }
};

/*
    Counting problems: For problems that require to count, we need to cover every possible subarray. Hence use while loop to shrink the window when conditions are not met
    Maximization: if we need to find the maximimum length (or minimum length) of subarray then we don't shrink (or expand) the window because we don't need to check for maxLen-1 (or minLen+1) as we are looking for max. Hence we don't need to cover every subarray and we move 'l' pointer with 'r' pointer (without using while loop to shrink) whenever conditions fail.

    *conditions are given in problem statement
*/