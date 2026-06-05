class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() <= 1){
            return;
        }
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==0){
                count++;
            }else{
                swap(nums[i], nums[i-count]);
            }
        }
    }
};

// if it is a zero increament the total count and move
// if it is not a zero swap it with the first zero (whose index is [i-count])