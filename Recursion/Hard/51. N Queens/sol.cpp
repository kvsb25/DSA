class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n){
        for(int i = row; i>=0; i--){
            if(board[i][col] == 'Q') return false;
        }

        int r = row-1, c = col-1;
        while(r>=0 && c>=0){
            if(board[r][c] == 'Q') return false;
            r -= 1; c -= 1;
        }

        r = row-1, c = col+1;
        while(r>=0 && c<n){
            if(board[r][c] == 'Q') return false;
            r -= 1; c += 1;
        }

        return true;
    }

    void solve(vector<string>& board, int n, int row, vector<vector<string>>& ans){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(board, n, row+1, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        vector<vector<string>> ans;

        solve(board, n, 0, ans);
        return ans;
    }
};