class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nge (n, -1);
        stack<int> st;

        for(int i = 2*n; i>=0; i--){
            int curr = nums[i%n];
            while(!st.empty() && st.top()<=curr){
                st.pop();
            }

            if(i<n){
                nge[i] = !st.empty() ? st.top() : -1;
            }
            st.push(curr);
        }

        return nge;
    }
};

// consider hypothetical double array and use the monotonic stack to keep track of the nge.
// only assign nge[i] if i (index of curr) is less than 'n' (size of original array)