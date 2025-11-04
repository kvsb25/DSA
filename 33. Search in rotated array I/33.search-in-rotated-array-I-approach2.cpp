class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() - 1;
        int start = 0;
        int end = n;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            //find the sorted half

            if (nums[start] <= nums[mid]) { // if left half is sorted
                // and the element is between it
                if (nums[start] <= target && target <= nums[mid]) {
                    end = mid - 1;
                // else search in the unsorted half (right)
                } else {
                    start = mid + 1;
                }
            } else { // if right half is sorted
                // and the element is between it
                if (nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                // else search in the unsorted half (left)
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};