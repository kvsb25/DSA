class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col = false;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> rec;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (j == 0) {
                        col = true;
                    } else {
                        matrix[0][j] = 0;
                    }
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != 0) {
                    if (!(matrix[0][j] && matrix[i][0])) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        if(matrix[0][0] == 0){
            for(int i = 0; i<n;i++){
                matrix[0][i] = 0;
            }
        }

        if(col){
            for(int i = 0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};