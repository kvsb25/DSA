class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int m = s+(e-s)/2;
            

            if(m == 0 || m == nums.size()-1){
                return nums[m];
            }

            // if both, the next and the previous are not the same as the mid this means at mid there lies the unique element
            if(nums[m-1]!=nums[m] && nums[m]!=nums[m+1]){
                return nums[m];
            }

            // if mid and its next element are equal (rather than the previous)
            if(nums[m] == nums[m+1]){
                // calculate the elements in the right half
                // if odd, this means the unique element is in that half, search this half
                if((e-m+1)%2 != 0){
                    s = m + 2;
                // if even search this half [this means the unique element is in the other half (which has odd number of elements)]
                } else {
                    e = m - 1;
                }
            // if mid and its previous element are equal
            } else if (nums[m-1] == nums[m]){
                // calculate the elements in the left half
                // if odd, search this half 
                if((m-s-1)%2 != 0){
                    e = m - 2;
                // else search the other half (right half)
                } else {
                    s = m + 1;
                }
            }
        }
        return -1;
    }
};

// search the half which has odd number of elements