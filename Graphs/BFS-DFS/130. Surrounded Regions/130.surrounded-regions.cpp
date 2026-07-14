class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        
        if(m <= 1 || n <= 1) return;

        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i%(m-1) == 0 || j%(n-1) == 0){
                    if(board[i][j] == 'O'){
                        q.push({i,j});
                        board[i][j] = '-';
                    }
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            board[x][y] = '-';

            for(auto [dx, dy] : dirs){
                int nx = x+dx, ny = y+dy;
                if(nx < m && ny < n && nx >= 0 && ny >= 0 && board[nx][ny] == 'O'){
                    q.push({nx,ny});
                    board[nx][ny] = '-';
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == '-'){
                    board[i][j] = 'O';
                }
            }
        }

        return;
    }
};