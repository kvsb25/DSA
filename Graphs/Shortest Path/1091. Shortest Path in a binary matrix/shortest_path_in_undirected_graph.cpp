class Solution {
public:
    vector<pair<int,int>> dirs = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;

        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        queue<pair<int,int>> q;

        dist[0][0] = 1;
        q.push({0,0});

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy] : dirs){
                int nx = x+dx, ny = y+dy;
                if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0 && dist[x][y]+1 < dist[nx][ny]){
                    dist[nx][ny] = dist[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }

        if(dist[n-1][n-1] == 1e9) dist[n-1][n-1] = -1;

        return dist[n-1][n-1];
    }
};

// shortest path in an undirected graph