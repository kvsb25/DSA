class Solution {
public:
    int divisorSum(vector<int>& nums, int divisor){
        int sum = 0;
        for(auto num : nums){
            sum += ceil((double)num/(double)divisor);
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = *(max_element(nums.begin(), nums.end()));
        while(start<=end){
            int divisor = start+(end-start)/2;

            if(divisorSum(nums, divisor)<=threshold){
                end = divisor-1;
            } else {
                start = divisor + 1;
            }
        }
        return start;
    }
};