class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
    }
    
    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    
    void unionBySize(int i, int j){
        int u = find(i), v = find(j);
        
        if(u!=v){
            if(size[u] < size[v]){
                parent[u] = v;
                size[v] += size[u];
            } else {
                parent[v] = u;
                size[u] += size[v];
            }
        }
    }
};

class Solution {
  public:
  
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool outOfBounds(int r, int c, int n, int m){
        return(r <0 || c<0 || r==n || c ==m);
    }
    
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        int k = operators.size();
        vector<vector<int>> grid(n, vector<int>(m, 0));
        DisjointSet ds(n*m);
        vector<int> ans;
        int cnt = 0;
        
        for(int i = 0; i<k; i++){
            int r = operators[i][0];
            int c = operators[i][1];

            // check if grid is already set 1
            if(grid[r][c] == 1) {
                ans.push_back(cnt);
                continue;
            }

            // if not, set it as 1
            grid[r][c] = 1;

            // note down the node for current operation cell (island)
            int node = r*m + c;

            // assume it contributes 1 to the total count of isolated islands
            cnt += 1;

            // check its neighbors (4 directional adjacent nodes)
            for(auto [dr, dc] : dirs){
                int nr = r+dr, nc = c+dc;
                int adjNode = nr*m + nc;

                // if the neighbor is an island, and is not already associated with the current island
                if(!outOfBounds(nr, nc, n, m) && grid[nr][nc] == 1 && ds.find(node) != ds.find(adjNode)){
                    // it is a part of already existing island
                    cnt--; // hence its contribution is rejected
                    ds.unionBySize(node, adjNode); // and associated to the island it is part of
                }
            }

            // push the number of islands after the current operation
            ans.push_back(cnt);
        }
        
        return ans;
    }
};

// test case to be evaluated to understand the solution better:
// n = 4
// m = 5
// operations = {{0,0},{0,0},{1,1},{1,0},{0,1},{0,3},{1,3},{0,4},{3,2},{2,2},{1,2},{0,2}};
// the operation {1,2} is a must 