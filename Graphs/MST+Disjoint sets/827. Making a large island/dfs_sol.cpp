class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,-1},{0,1}};

    bool outOfBounds(int r, int c, int n){
        return (r==n || c==n || r<0 || c<0);
    }

    int dfs(int r, int c, int label, vector<vector<int>>& grid){
        if(outOfBounds(r,c,grid.size()) || grid[r][c] != 1){
            return 0;
        }
        grid[r][c] = label;
        int res = 1;
        
        for(auto [dr, dc] : dirs){
            int nr = r+dr, nc = c+dc;
            res += dfs(nr, nc, label, grid);
        }

        return res;
    }

    int connect(int r, int c, unordered_map<int,int>& size, vector<vector<int>>& grid){
        int res = 1;
        set<int> vis;
        for(auto [dr, dc] : dirs){
            int nr = r+dr, nc = c+dc;
            if(!outOfBounds(nr, nc, grid.size()) && grid[nr][nc] != 0 && !vis.contains(grid[nr][nc])){
                res += size[grid[nr][nc]];
                vis.insert(grid[nr][nc]);
            }
        }
        return res;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        unordered_map<int, int> size;
        int label = 2;
        
        // Precompute
        for(int r = 0; r<n; r++){
            for(int c = 0; c<n; c++){
                if(grid[r][c] == 1){
                    size[label] = dfs(r, c, label, grid);
                    label++;
                }
            }
        }

        int res = size.empty() ? 0 : (*max_element(size.begin(), size.end(), [](const pair<int,int>& p1, const pair<int,int>& p2){
            return p1.second > p2.second;
        })).second;

        for(int r = 0; r<n; r++){
            for(int c = 0; c<n; c++){
                if(grid[r][c] == 0){
                    res = max(res, connect(r, c, size, grid));
                }
            }
        }

        return res;
    }
};