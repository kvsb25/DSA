class Solution {
  public:
  
    /*      Recursive Solution      
    bool fn(int idx, int sum, vector<int>& arr){
        if(sum == 0) return true;
        if(idx == 0) return (arr[0] == sum);
        
        bool notTake = fn(idx-1, sum, arr);
        bool take = false;
        
        if(arr[idx] <= sum){
            take = fn(idx-1, sum-arr[idx], arr);
        }
        
        return notTake || take;
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        return fn(n-1, sum, arr);
    }
    */
    
    /*      Memoization    
    
    bool fn(int idx, int sum, vector<int>& arr, vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(idx == 0) return (arr[0] == sum);
        
        if(dp[idx][sum] != -1) return dp[idx][sum];
        
        bool notTake = fn(idx-1, sum, arr, dp);
        bool take = false;
        
        if(arr[idx] <= sum){
            take = fn(idx-1, sum-arr[idx], arr, dp);
        }
        
        return dp[idx][sum] = notTake | take;
    }
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        
        return fn(n-1, sum, arr, dp);
    } 
    */
    
    /*      Tabulation      
    
    bool isSubsetSum(vector<int>& arr, int sum){
        int n = arr.size();
        vector<vector<bool>>dp(n, vector<bool>(sum+1, false));
        
        for(int i = 0; i<n; i++) dp[i][0] = true;
        dp[0][arr[0]] = true;
        
        for(int idx = 1; idx < n;idx++){
            for(int target = 1; target<=sum; target++){
                bool notTake = dp[idx-1][target];
                bool take = false;
                
                if(arr[idx] <= target){
                    take = dp[idx-1][target-arr[idx]];
                }
                
                dp[idx][target] = notTake | take;
            }
        }
        
        return dp[n-1][sum];
    }
    */
    
    
    /*      Tab + Space Opti      */
    
    bool isSubsetSum(vector<int>& arr, int sum){
        int n = arr.size();
        vector<bool>prev(sum+1, false);
        vector<bool>curr(sum+1, false);
        
        prev[0] = curr[0] = true;
        prev[arr[0]] = true;
        
        for(int idx = 1; idx < n;idx++){
            for(int target = 1; target<=sum; target++){
                bool notTake = prev[target];
                bool take = false;
                
                if(arr[idx] <= target){
                    take = prev[target-arr[idx]];
                }
                
                curr[target] = notTake | take;
            }
            prev = curr;
        }
        
        return prev[sum];
    }
};