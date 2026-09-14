// Longest common subsequence

class Solution {
  public:
  
    /*  Memoization Solution */
    // 0 based indexing used
    
    // int fn(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
    //     if(i < 0 || j < 0) return 0;
        
    //     if(dp[i][j] != -1) return dp[i][j];
        
    //     // if match
    //     if(s1[i] == s2[j]) return dp[i][j] = 1+fn(i-1, j-1, s1, s2, dp);
        
    //     // else 
    //     return dp[i][j] = max(fn(i-1, j, s1, s2, dp), fn(i, j-1, s1, s2, dp));
    // }
    
    // int lcs(string &s1, string &s2) {
    //     int m = s1.size(), n = s2.size();
        
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
        
    //     return fn(m-1, n-1, s1, s2, dp);
    // }
    
    
    /*  Tabulation */
    // 1 based indexing, because vectors can't handle -1 representation of out of bounds
    
    // int lcs(string &s1, string& s2){
    //     int m = s1.size(), n = s2.size();
        
    //     vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        
    //     // for 1 based indexing base case becomes:
    //     // if(i-1 < 0 || j-1 < 0) return 0;
    //     // which is similar to:
    //     // if(i == 0 || j == 0) return 0; // in 1 based indexing
        
    //     for(int i = 0; i<=m; i++) dp[i][0] = 0;
    //     for(int j = 0; j<=n; j++) dp[0][j] = 0;
        
    //     for(int i = 1; i<=m; i++){
    //         for(int j = 1; j<=n; j++){
    //             // i-1 and j-1 as we are using 1 based indexing
    //             if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
    //             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    //         }
    //     }
        
    //     return dp[m][n];
    // }
    
    
    /*  Tab + Sp opti  */
    
    int lcs(string& s1, string& s2){
        int m = s1.size(), n = s2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        
        return prev[n];
    }
};