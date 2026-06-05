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

// keep two pointers one for the start and one for the end
// whenever you encounter a zero swap it with the ele at start and increment start (keeping all zeros at the front of the array)
// whenever you encounter a two swap it with the ele at end and decrement end (keeping all the twos at the end of the array)
// we have only three types of ele, two keeping the smallest at the start and the largest at the end of the array would sort the array