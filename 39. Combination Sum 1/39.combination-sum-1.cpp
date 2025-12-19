class Solution {
public:

    void helper(vector<int>& cand, int target, vector<vector<int>>& ans, vector<int>& combo, int index, int sum){
        if(sum == target){
            ans.push_back(combo);
            return;
        }
        if(sum > target){
            return;
        }
        if(index > cand.size()-1) {
            return;
        }

        sum += cand[index];
        combo.push_back(cand[index]);
        helper(cand, target, ans, combo, index, sum);
        sum -= cand[index];
        combo.pop_back();
        helper(cand, target, ans, combo, index+1, sum);

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combo;
        helper(candidates, target, ans, combo, 0, 0);

        return ans;
    }
};