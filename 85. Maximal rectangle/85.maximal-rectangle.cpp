class Solution {
public:
    int largestHistogram(vector<int>& arr){
        stack<pair<int,int>> st;
        int ans = 0, n = arr.size();

        for(int i = 0; i < n; i++){
            int start = i;
            while(!st.empty() && arr[i] < st.top().second){
                auto [index, val] = st.top();
                st.pop();
                ans = max(ans, val*(i-index));
                start = index;
            }
            st.push({start, arr[i]});
        }

        while(!st.empty()){
            auto [index, val] = st.top();
            st.pop();
            ans = max(ans, val*(n-index));
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));

        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += matrix[i][j]-'0';
                if(matrix[i][j]-'0' == 0) sum = 0; // if zero encountered make the sum reset to 0 as no bar can be considered from there
                prefix[i][j] = sum; // sum being the jth bar height at ith row
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, largestHistogram(prefix[i]));
        }

        return ans;
    }
};

// Intuition:
// Treat each row as the “ground” of a histogram formed by stacking 1s upward from that row.
// Each column’s bar height is simply how many consecutive 1s end at the current row vertically.
// We reuse these heights row by row, so we never recount 1s again from scratch.
// For every such histogram, compute the largest rectangle using the monotonic stack idea.