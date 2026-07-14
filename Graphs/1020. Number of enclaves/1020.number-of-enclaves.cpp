class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if(m <= 1 || n <= 1) return 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i%(m-1) == 0 || j%(n-1) == 0) && grid[i][j] == 1){
                    grid[i][j] = -1;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto [dx, dy] : dirs){
                int nx = x+dx, ny = y+dy;
                if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1){
                    q.push({nx, ny});
                    grid[nx][ny] = -1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }

        return ans;
    }
};