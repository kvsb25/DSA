class Solution {
public:
    void setRowZero(vector<vector<int>>& matrix, int row){
        for(int i = 0; i<matrix[0].size(); i++){
            matrix[row][i] = 0;
        }
    }
    void setColZero(vector<vector<int>>& matrix, int col){
        for(int i = 0; i<matrix.size(); i++){
            matrix[i][col] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> rec;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j]==0){
                    rec.push_back({i,j});
                }
            }
        }
        for(int i = 0; i < rec.size();i++){
            setRowZero(matrix, rec[i][0]);
            setColZero(matrix, rec[i][1]);
        }
    }
};