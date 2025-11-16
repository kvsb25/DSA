class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int start = 0;
        int end = n*m - 1;
        while(start<=end){
            int mid = start+(end-start)/2;
            int row = mid/m, col = mid%m;
            if(matrix[row][col]<target){
                start = mid + 1;
            } else if(matrix[row][col]>target){
                end = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

// flatten the 2d matrix to a hypothetical 1d array. So the size of the hypothetical 1d array would be n*m and the last index(hypothetical) would be n*m-1
// then the hypothetical index in 1d array will be some coordinates in the 2d array
// row = mid/m
// col = mid%m
// where mid is the hypothetical 1d array index and m is the number of columns.