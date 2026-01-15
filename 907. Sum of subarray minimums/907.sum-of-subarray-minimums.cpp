class Solution {
public:
    const int MOD = 1e9+7;

    vector<int> findNse(vector<int>& arr){
        stack<int> st;
        vector<int> nge(arr.size(), arr.size());
        for(int i = arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            nge[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return nge;
    }

    vector<int> findPse(vector<int>& arr){
        stack<int> st;
        vector<int> pse(arr.size(), -1);
        for(int i = 0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){ // edge case: [1,1] where 1,1 subarray would be considered twice. So the function finds the previous smaller or equal ele
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        long long res = 0;
        for(int i = 0; i < arr.size(); i++){
            int left = i - pse[i]; // number of elements to the left of arr[i] that are greater than arr[i]
            int right = nse[i] - i; // number of elements to the right of arr[i] that are greater than arr[i]
            long long ttlSubArr = (left*right)%MOD; // total subarrays with arr[i] as the min ele
            long long contri = (ttlSubArr*arr[i])%MOD; // the contribution of arr[i] to res (sum of min ele of all subarrays) being the min ele in some of the subarrays
            res += contri%MOD;
        }
        return res%MOD;
    }
};

// find all the subarrays for each element where that element is the minimum amongst all in a subarray
// to do so for each element, get the previous minimum element's index to know the number of elements that are greater than the curr ele and come before it
// get the next greater element's index to know the number of element that are greater than the current element an come after it
// after having the 'left' and the 'right', multiplying them would give us the number of subarrays where the current ele is the least or minimum of all
// lets say this number is 'x'
// if there are x subarrays where the current element is the minimum, then the curr ele should be added to the res 'x' times.
// this means the contribution of the current element in the res is x*arr[i]; x*val-of-curr-ele
// repeat this for each element to get the sum of all minimum