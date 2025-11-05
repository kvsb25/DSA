class Solution {
public:
    bool binarySearch(vector<int>& nums, int start, int end, int target){
        while(start<=end){
            int mid = start+(end-start)/2;
            if(nums[mid]<target){
                start = mid + 1;
            } else if(nums[mid]>target){
                end = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }

    bool search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int breakPt = -1;
        for ( int i = n-1; i>=0; i--){
            if(nums[i]>nums[i+1]){
                breakPt = i;
            }
        }

        if(breakPt!=-1){
            int a = binarySearch(nums, 0, breakPt, target);
            int b = binarySearch(nums, breakPt+1, n, target);
            // return a != false ? a : b;
            return a || b;
        } else {
            return binarySearch(nums, 0, n, target);
        }
    }
};