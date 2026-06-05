class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k >= nums.size()){
            k %= nums.size();
        }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin()+k, nums.end());
        reverse(nums.begin(), nums.begin()+k);
    }
};


// rotating an array, of size n, n times results in the same array. Therefore rotations more than the size of array (say k) produce same results as rotating the array k%n times 