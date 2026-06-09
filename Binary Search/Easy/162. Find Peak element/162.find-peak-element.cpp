class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // checking if the size of array is one or extreme elements are peak or not
        if (n == 1 || nums[0] > nums[1]) {
            return 0;
        } else if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }

        // if the extreme elements are not peak
        // shrink the search space by elemenating the extreme elements
        int s = 1;
        int e = n - 2;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m - 1] < nums[m] && nums[m] > nums[m + 1]) {
                return m;
            } else if (nums[m] < nums[m + 1]) {
                s = m + 1;
            } else if (nums[m - 1] > nums[m]) {
                e = m - 1;
            } else {
                s = m + 1;
            }
        }
        return -1;
    }
};
// if the mid is on a decreasing curve then the peak is in the left half,
// else if mid is on an increasing curve then the peak is in the right half,

// decreasing curve : nums[m-1] > nums[m] > nums[m+1]
// increasing curve : nums[m-1] < nums[m] < nums[m+1]