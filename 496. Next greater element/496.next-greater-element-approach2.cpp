class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        int i = 0;
        for(auto num : nums1){
            mp.insert({num, i++});
        }

        stack<int> st;
        vector<int> nge(nums2.size(), -1);
        vector<int> ans(nums1.size(), -1);

        // reverse loop on nums2
        for(int i = nums2.size()-1; i>=0; i--){

            int curr = nums2[i];
            // stop when st.top() > curr, this means st.top() is the nge of curr
            while(!st.empty() && st.top() <= curr){
                st.pop();
            }

            //st.top() is the nge of curr
            if(!st.empty()){
                nge[i] = st.top();
            }
            // push curr to stack as it can be nge to the elements on its left
            st.push(curr);

            // if curr is in nums1, then marks it's nge (in nums2) in ans
            if(mp.find(curr) != mp.end()){
                int idx = mp[curr];
                ans[idx] = nge[i];
            }
        }

        return ans;
    }
};

// stack keeps track of the greater elements than curr (i.e. nums[i])