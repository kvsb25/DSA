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