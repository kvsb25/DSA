class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int cnt = 0, ans = 0;
        int i = 0, j = 0;
        while(i<n && j<n){
            if(arr[i] <= dep[j]){
                cnt++; i++;
            } else {
                cnt--; j++;
            }
            ans = max(cnt, ans);
        }
        
        return ans;
    }
};

// the max number of trains clashing is the minimum number of stations required.
// max(no. of clashing trains) = ans
// Time complexity: O(2(nlogn + n))
// Space complexity: O(1)