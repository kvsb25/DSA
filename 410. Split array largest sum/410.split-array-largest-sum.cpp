class Solution {
public:

    bool canSplit(vector<int>&nums, int k, int largest){
        int subArray = 0;
        int currSum = 0;
        for(auto num : nums){
            currSum += num;
            if(currSum > largest){
                subArray++;
                currSum = num;
            }
        }
        subArray++;

        return subArray <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int start = *(max_element(nums.begin(), nums.end()));
        int end = 0;
        for(auto num : nums){
            end += num;
        }

        while(start<=end){

            // compute possible minimized max sum 
            int mid = start + (end-start)/2;

            // if with that possible answer if the array can be split
            if(canSplit(nums, k, mid)){ 
                end = mid - 1; // then find a lower possible answer
            } else { // else 
                start = mid + 1; // the answer must be higher than the possible (hence search the right half of possible answers)
            }
        }
        return start; // return the least possible answer
    }
};

// the least answer for the minimized max sum would be the largest element in the input array
// and the largest answer for the minimized max would be the sum of input array (to be exact - it will be the largest sum among the split subarrays, but to compute that would be inefficient so directly considering the sum of the array to be the largest answer)