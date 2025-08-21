class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, start = 0, end = nums.size()-1;
        while(i<=end){
            if(nums[i]==0){
                swap(nums[i++], nums[start++]);
            } else if(nums[i] == 1) {
                i++;
            } else {
                swap(nums[i], nums[end--]);
            }
        }
    }
};