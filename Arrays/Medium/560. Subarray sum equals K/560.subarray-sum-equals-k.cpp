class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // map to keep track of prefix sum occurances, how many times a prefix sums occurs
        // we will track the prefixes that come our way while iterating the nums array
        unordered_map<int,int> prefixSum = {{0,1}};
        int res = 0;
        int currSum = 0;
        // iterate and add 
        for(auto n : nums){
            currSum += n;
            int diff = currSum - k; // diff variable to know what prefix sum to be removed from the currSum to get 'k'
            if(prefixSum.find(diff) != prefixSum.end) res += prefixSum[diff]; // prefix[diff] tells the count of subarray that gives the 'diff' as sum (which would be the prefix sum for currSum).
            // So the count of prefix subarray (prefix[diff]) would be the same as the number of subarrays that give 'k' as sum
            prefixSum[currSum]++; // recording the currSum, as prefix, as it would be the prefix for the upcoming sums
        }
        return res;
    }
};

// reference video: https://www.youtube.com/watch?v=fFVZt-6sgyo