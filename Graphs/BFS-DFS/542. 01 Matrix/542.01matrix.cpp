class Solution {
public:
    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int m = mat.size(), n = mat[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        while(!q.empty()){
            int size = q.size();
            while(size-->0){
                auto [x, y] = q.front();
                q.pop();
                for(auto [dx,dy] : dirs){
                    int nx = x+dx, ny = y+dy;
                    if(nx<m && nx >= 0 && ny<n && ny>=0 && mat[nx][ny] == -1){
                        mat[nx][ny] = mat[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return mat;
    }
};