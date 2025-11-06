class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int least = INT_MAX;
        while(s<=e){
            int m = s+(e-s)/2;
            
            // find the sorted half of the rotated array. The starting element of the sorted array may be the minimum
            // if the second half is sorted
            if(nums[m] <= nums[e]){
                least = min(nums[m], least); // the minimum might be the starting element of this half
                e = m - 1; // look for the minimum in the unsorted half (first)
            } else {
            // if the first half is sorted
                least = min(nums[s],least); // the minimum might be the starting element of this half
                s = m + 1; // look for the minimum in the unsorted half (second)
            }
        }
        return least;
    }
};