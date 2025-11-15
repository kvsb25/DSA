class Solution {
public:

    vector<int> sorted(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans;
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        while(i<n & j<m){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j<m){
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }

    double median(vector<int> nums){
        double low = 0;
        double high = nums.size()-1;
        double mid = low + (high-low)/2;
        return nums.size()%2 == 0 ? ((double)nums[mid]+(double)nums[mid+1])/2 : nums[mid];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return median(sorted(nums1,nums2));
    }
};