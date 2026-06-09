class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool leftBias){
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]<target){
                s = m+1;
            } else if(nums[m]>target){
                e = m-1;
            } else { // when nums[m] is equal to target
                ans = m;
                if(leftBias){
                    e = m-1; // search the left half of the array to find the first position of the target element // search for upper bound
                } else {
                    s = m+1; // search the right half of the array to find the last position of the target element //search for lower bound
                }
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binarySearch(nums, target, true);
        int last = binarySearch(nums, target, false);
        return {first, last};
    }
};

// OR you could just find the UB index and LB index
// UB would be the first occurance, and LB would be the last occurance
// UB = Upper Bound; LB = Lower Bound