class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();

        // left half
        while(i<n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i+=1;
        }

        // overlapping half
        while(i<n && intervals[i][0] <= newInterval[1]){
            //merge into new interval
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i+=1;
        }
        //push to result
        res.push_back(newInterval);

        // remaining non-overlapping right half
        while(i<n){
            res.push_back(intervals[i]);
            i+=1;
        }
        
        return res;
    }
};