class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end, int target){
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]<target){
                start = mid + 1;
            } else if(nums[mid]>target){
                end = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int breakPt = -1;
        // find the breaking point (pivot index at which the array is rotated)
        for ( int i = n-1; i>=0; i--){
            if(nums[i]>nums[i+1]){
                breakPt = i;
            }
        }

        // if there is a breaking point then search in the separate halves as they will be sorted 
        if(breakPt!=-1){
            int a = binarySearch(nums, 0, breakPt, target);
            int b = binarySearch(nums, breakPt+1, n, target);
            return a != -1 ? a : b;
        } else {
            // if no breaking point search the whole array at once
            return binarySearch(nums, 0, n, target);
        }
    }
};