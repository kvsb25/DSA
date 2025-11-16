class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] < target) {
                row++;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                return true;
            }
        }
        return false;
    }
};

// the elements are increasing in an inverted L order. from (0,0) to (0,n) to (m,n) the elements are increasing in this manner
// if target is less than the current coordinates, this means the target would lie before the current in the same row (so col--), as the elements in the same col after the current would be greater than current as well as target
// and if target is greater than the current coordinates, this means target would lie after the current in the same col (so row++), as the elements in the same row before the current would be less than the current as well as target