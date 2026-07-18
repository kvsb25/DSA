class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        int islands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    grid[i][j] = '0';
                    q.push({i,j});
                    islands++;
                    while(!q.empty()){
                        auto [x, y] = q.front();
                        q.pop();
                        for(auto [dx, dy] : dirs){
                            int nx = x+dx, ny = y+dy;
                            if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == '1'){
                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};