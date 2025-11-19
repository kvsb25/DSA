class Solution {
public:
    int findMaxRowInd(vector<vector<int>>& mat, int col, int m){
        int maxIdx = 0;
        for(int i = 0; i <= m; i++){
            if(mat[i][col] > mat[maxIdx][col]){
                maxIdx = i;
            }
        }
        return maxIdx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size()-1;
        int n = mat[0].size()-1;
        int start = 0;
        int end = mat[0].size()-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            int rowIdx = findMaxRowInd(mat, mid, m);
            int left = mid-1 >= 0 ? mat[rowIdx][mid-1] : -1;
            int right = mid+1 <= n ? mat[rowIdx][mid+1] : -1;
            if(mat[rowIdx][mid]>left && mat[rowIdx][mid]>right){
                return {rowIdx, mid};
            } else if (mat[rowIdx][mid]<left){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return {-1,-1};
    }
};

// apply binary search on columns.
// find the mid column. Then find the largest element in that col and its row index
// this means the largest element is greater than all in the col. Hence its obviously greater than it vertical counterparts (top and bottom), so we don't need to check for the verticals
// then binary search through the row, if on increasing curve then search in the columns on the right
// if on decreasing curve then search in the columns on the left
// hence col are updated as mid 