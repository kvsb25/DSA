class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1, -1);
        memo[0] = 0;

        for(int i = 1; i <= amount; i++){
            int mini = INT_MAX;
            for(auto coin: coins){
                int subAmount = i - coin;
                if(subAmount >= 0 && memo[subAmount] != -1){
                    mini = min(mini, memo[subAmount]+1);
                }
            }
            memo[i] = mini != INT_MAX ? mini : -1;
        }

        return memo[amount];
    }
};

// solved using tabulation dynamic programming (bottom-up approach)