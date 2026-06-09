class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(i==j){ continue; }
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

// transpose the matrix
// and then reverse each row 
// this will give you 90deg rotation of the matrix
// just transpose the matrix this will give you 180deg rotation of the matrix