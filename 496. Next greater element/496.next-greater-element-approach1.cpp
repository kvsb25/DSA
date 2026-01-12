class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        stack<int> st;
        unordered_map<int,int> mp;

        for(int i = 0; i < nums1.size(); i++){
            mp.insert({nums1[i], i});
        }

        // from 0 to n on nums2
        for(int i = 0; i < nums2.size(); i++){
            int curr = nums2[i];

            // stop when curr is greater than st.top(), this means curr is nge of st.top()
            // st only has elements of nums1
            while(!st.empty() && curr > st.top()){
                int top = st.top();
                st.pop();
                int idx = mp[top];
                ans[idx] = curr;
            }

            // push only if curr is in nums1, as we are concerned with ele of nums1 only
            if(mp.count(curr) > 0){
                st.push(curr);
            }
        }

        return ans;
    }
};

// pushing only those elements whose nge we want to find, which will be the curr as per the while loop condition