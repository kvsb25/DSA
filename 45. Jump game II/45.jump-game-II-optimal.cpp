class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, l = 0, r = 0;
        int n = nums.size();
        
        while(r<n-1){
            int farthest = 0;
            for(int i = l; i <= r; i++){
                // find the farthest we can jump starting from the range of indices l to r (from the current range)
                farthest = max(i+nums[i], farthest);
            }
            // update the range from l to r -> r+1 to farthest 
            l = r + 1;
            r = farthest;

            // increment jump: we have successfully found the most effecient jump and we jump!
            jumps += 1;
        }

        return jumps;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)