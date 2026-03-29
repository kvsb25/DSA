class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n =intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& t1, vector<int>& t2){
            return t1[1]<t2[1];
        });

        int ans = 1;
        int prevEndTime = intervals[0][1];
        for(int i = 1; i<n; i++){
            if(intervals[i][0] >= prevEndTime){
                ans++;
                prevEndTime = intervals[i][1];
            }
        }

        return n-ans;
    }
};