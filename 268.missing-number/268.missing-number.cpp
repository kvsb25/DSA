class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedSum = nums.size(), actualSum = 0;
        for(int i = 0; i<nums.size(); i++){
            expectedSum += i;
            actualSum += nums[i];
        }
        return expectedSum-actualSum;
    }
};