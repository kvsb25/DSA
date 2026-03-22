class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        // initialize min start and max end as the start and end of the first interval
        int mn = intervals[0][0];
        int mx = intervals[0][1];
        int i = 1;

        while (i < n) {
            // if the ith (current) interval's start is less than mx (end of prev interval)
            // then the intervals overlap
            if (mx >= intervals[i][0]) {
                // hence update the mn and mx as the minimum start upon merger and maximum end upon merger
                mn = min(mn, intervals[i][0]); // min(prev start, curr start)
                mx = max(mx, intervals[i][1]); // max(prev end, curr end)
            } else {
            // else if they don't overlap
            // push the overlapped interval to answer vector
            // and reinitialize mn, mx as curr start and curr end
                ans.push_back({mn, mx});
                mn = intervals[i][0];
                mx = intervals[i][1];
            }
            i++;
        }
        // push the final mn, mx 
        ans.push_back({mn, mx});
        return ans;
    }
};

// for each loop can be used instead of while loop

// for (auto i : intervals) {
//     if (mx >= i[0]) {
//         mn = min(mn, i[0]);
//         mx = max(mx, i[1]);
//     } else {
//         ans.push_back({mn, mx});
//         mn = i[0];
//         mx = i[1];
//     }
// }