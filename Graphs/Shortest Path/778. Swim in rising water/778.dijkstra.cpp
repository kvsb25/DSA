# define pip pair<int,pair<int,int>> 
class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

    bool outOfBounds(int r, int c, int n){
        return (r < 0 || c < 0 || r == n || c == n);
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pip, vector<pip>, greater<pip>> min_heap;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        min_heap.push({grid[0][0], {0,0}});

        while(!min_heap.empty()){
            auto p = min_heap.top();
            int time = p.first, r = p.second.first, c = p.second.second;
            min_heap.pop();
            if(vis[r][c]) continue;
            vis[r][c] = true;
            if(r == n-1 && c == n-1){
                return time;
            }

            for(auto [dr, dc] : dirs){
                int nr = r+dr, nc = c+dc;
                if(!outOfBounds(nr, nc, n) && !vis[nr][nc]){
                    int newTime = max(grid[nr][nc], time);
                    min_heap.push({newTime, {nr, nc}});
                }
            }
        }

        return n*n;
    }
};