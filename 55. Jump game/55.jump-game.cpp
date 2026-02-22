class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), maxInd = 0;
        for(int i = 0; i < n; i++){
            if(i>maxInd) return false;
            maxInd = max(maxInd, i+nums[i]);
        }

        return true;
    }
};

// at each step keep track of the maximum index we can reach.
// if at any step/iteration the maximum index we can reach is less than the current index then we cannot reach the last index
// the final maximum index we can reach should be greater than or equal to the last index 