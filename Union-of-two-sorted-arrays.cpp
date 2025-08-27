class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;

        while(i<n && j<m){
            if (i > 0 && nums1[i] == nums1[i - 1]) {
                i++;
                continue;
            }
            if (j > 0 && nums2[j] == nums2[j - 1]) {
                j++;
                continue;
            }
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                i++;j++;
            } else if(nums1[i] <= nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else {
                res.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n){
            if (i > 0 && nums1[i] == nums1[i - 1]) {
                i++;
                continue;
            }
            res.push_back(nums1[i]);
            i++;
        }

        while(j<n){
            if (j > 0 && nums2[j] == nums2[j - 1]) {
                j++;
                continue;
            }
            res.push_back(nums2[j]);
            j++;
        }

        return res;
    }
};