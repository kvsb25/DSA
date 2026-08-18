class Solution {
  public:
    
    /* Memoization Solution */
    
    int helper(int day, int choose, vector<vector<int>>& mat, vector<vector<int>>& dp){
        if(day == 0) return mat[0][choose];
        
        if(dp[day][choose] != -1) return dp[day][choose];
        
        int max_ans = 0;
        
        for(int i = 0; i<3; i++){
            if(choose != -1 && i == choose) continue;
            max_ans = max(max_ans, mat[day][choose] + helper(day-1, i, mat, dp));
        }
        
        return dp[day][choose] = max_ans;
    }
  
    int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size(); 
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(3, -1));
        
        for(int i = 0; i<3; i++){
            ans = max(ans, helper(n-1, i, mat, dp));
        }
        
        return ans;
    }
    
    
    /* Tabulation solution */
    
    int maximumPoints(vector<vector<int>>& mat) {
        
        int n = mat.size(); 
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(3, -1));
        dp[0][0] = mat[0][0]; dp[0][1] = mat[0][1]; dp[0][2] = mat[0][2];
        
        for(int day = 1; day<n; day++){
            for(int i = 0; i<3; i++){
                int max_ans = 0;
                for(int j = 0; j<3; j++){
                    if(j == i) continue;
                    max_ans = max(max_ans, mat[day][i] + dp[day-1][j]);
                }
                dp[day][i] = max_ans;
            }
        }
        
        for(int i = 0; i<3; i++){
            ans = max(ans, dp[n-1][i]);
        }
        
        return ans;
    }
    
    
    /* Tabulation + Space Optimization */
    
    int maximumPoints(vector<vector<int>>& mat) {
        
        int n = mat.size(); 
        int ans = 0;
        vector<int> prev = {mat[0][0], mat[0][1], mat[0][2]};
        
        for(int day = 1; day<n; day++){
            vector<int> curr(3, -1);
            for(int i = 0; i<3; i++){
                int max_ans = 0;
                
                for(int j = 0; j<3; j++){
                    if(j == i) continue;
                    max_ans = max(max_ans, mat[day][i] + prev[j]);
                    
                }
                
                curr[i] = max_ans;
            }
            prev = curr;
        }
        
        for(int i = 0; i<3; i++){
            ans = max(ans, prev[i]);
        }
        
        return ans;
    }
};