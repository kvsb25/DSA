class Solution {
public:
    vector<int> findNge(vector<int>& arr){
        int n = arr.size();
        vector<int> nge(n, n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[i] >= arr[st.top()]){
                st.pop();
            }
            nge[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nge;
    }

    vector<int> findPge(vector<int>& arr){
        int n = arr.size();
        vector<int> pge(n, -1);
        stack<int> st;

        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[i] > arr[st.top()]){
                st.pop();
            }
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pge;
    }

    vector<int> findNse(vector<int>& arr){
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;

        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nse;
    }

    vector<int> findPse(vector<int>& arr){
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for(int i = 0 ; i<n; i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }

    long long sumOfSubarrayMins(vector<int>& arr){
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);

        long long res = 0;
        for(int i = 0; i < arr.size(); i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            res += (long long)left * right * arr[i];
        }

        return res;
    }

    long long sumOfSubarrayMaxs(vector<int>& arr){
        vector<int> nge = findNge(arr);
        vector<int> pge = findPge(arr);

        long long res = 0;
        for(int i = 0; i < arr.size(); i++){
            int left = i - pge[i];
            int right = nge[i] - i;
            res += (long long)left * right * arr[i];
        }

        return res;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumOfSubarrayMaxs(nums) - sumOfSubarrayMins(nums);
    }
};