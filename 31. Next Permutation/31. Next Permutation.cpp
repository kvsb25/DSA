class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        // first find the breaking point starting from the right
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i]<nums[i+1]){ // breaking point is when the order ascending from the right and descending from the left is broken
                idx = i;
                break;
            }
        }
        // if idx==-1 that means no smallest element (breaking point) was found, this means the input string is lexicographically largest
        if(idx == -1){
            reverse(nums.begin(), nums.end()); // simply reversing it will give the next permutation which is lexicographically the smallest 
            return;
        }
        // otherwise find the just larger element than the breaking point element and swap it with the breaking point element
        for(int i = nums.size()-1; i>idx; i--){
            if(nums[i]>nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }
        // make the elements after the element at idx lexicographically the smallest (by reversing as they are already in descending order)
        //(after swapping idx element will be the just larger number than the breaking point element)
        reverse(nums.begin()+idx+1, nums.end());
        return;
    }
};