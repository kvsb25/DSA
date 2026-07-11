class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();
        int curr_color = image[sr][sc];
        queue<pair<int,int>> q;

        q.push({sr, sc});
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while(!q.empty()){
            int size = q.size();

            while(size-->0){
                auto [x, y] = q.front();
                q.pop();
                image[x][y] = color;

                for(auto [dx, dy] : dirs){
                    int i = x+dx, j = y+dy;
                    if(i >= 0 && i < m && j >= 0 && j < n && image[i][j] == curr_color && image[i][j] != color){
                        q.push({i, j});
                    }
                }
            }
        }

        return image;
    }
};