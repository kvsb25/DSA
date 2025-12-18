class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int n = 0; n< pow(2,nums.size()); n++){
            vector<int> sub;
            for(int i = 0; i < nums.size(); i++){
                if((n & (1<<i)) != 0){
                    sub.push_back(nums[i]);
                }
            }
            ans.push_back(sub);
        }
        return ans;
    }
};

// We iterate over all bitmasks from 0 to (2^n - 1), where each bitmask represents one subset
// A bit set to 1 means the element at that index is included in that subset

// to know if bit at index 'x' of a number is set to 1 or not: Left shift 1 'x' times and perform Bitwise AND with that number
// if the result is not equal to 0 then the bit at that index (x) is set 1 else it is not.