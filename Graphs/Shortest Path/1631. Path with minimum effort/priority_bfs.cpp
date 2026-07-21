struct Cell{
    int diff;
    int row;
    int col;
};

class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{-1,0}, {0,1}, {0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        auto comp =[](Cell& c1, Cell& c2){
            return c1.diff > c2.diff;
        };
        priority_queue<Cell, vector<Cell>, decltype(comp)> minHeap;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));

        Cell src = {0, 0, 0};
        minHeap.push(src);

        while(!minHeap.empty()){
            auto [diff, r, c] = minHeap.top();
            minHeap.pop();

            
            if(r == rows-1 && c == cols-1) return diff;

            int curr_ht = heights[r][c];

            for(auto [dr, dc] : dirs){
                int nr = r+dr, nc = c+dc;
                if(nr >= 0 && nc >= 0 && nr < rows && nc < cols && !vis[nr][nc]){
                    vis[r][c] = true;
                    int newDiff = abs(curr_ht - heights[nr][nc]);
                    int maxDiff = max(diff, newDiff);
                    minHeap.push({maxDiff, nr, nc});
                }
            }
        }

        return 0;
    }
};