class Solution {
public:

    void helper(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combo, int index, int sum){
        if(sum == target){
            ans.push_back(combo);
            return;
        }
        if(sum > target || index > candidates.size()-1){
            return;
        }

        combo.push_back(candidates[index]);
        helper(candidates, target, ans, combo, index+1, sum+candidates[index]);
        combo.pop_back();

        while(index+1 < candidates.size() && candidates[index]==candidates[index+1]){
            index += 1;
        }
        helper(candidates, target, ans, combo, index+1, sum);

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combo;

        // sort candidates so that duplicate values are placed next to each other
        sort(candidates.begin(), candidates.end());

        helper(candidates, target, ans, combo, 0,0);

        return ans;
    }
};

// since the array is sorted, equal numbers are adjacent.
// when we decide NOT to pick candidates[index], we also skip all its duplicates 
// so that the same value does not lead to identical combinations again. because exploring its duplicates would give the same combinations, hence duplicates