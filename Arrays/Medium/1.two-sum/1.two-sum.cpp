class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i<nums.size(); i++){
            
            //compute compliment
            int comp = target-nums[i];

            // check if compliment is in the map
            if(map.count(comp)){
                // if yes, this means there are two elements whose sum equals the target
                // return the index of both
                return {map[comp], i};
            }

            // else insert the current into map
            map[nums[i]] = i;
        }
        return {};
    }
};