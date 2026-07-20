class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
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

// NOTE: While computing transpose, j = i+1 so that we only swap the elements in the upper triangle with the ele in the lower triangle of the matrix
// If you start at j = 0, you will end up swapping every pair of elements twice, which puts them exactly back where they started hence giving the array in input.