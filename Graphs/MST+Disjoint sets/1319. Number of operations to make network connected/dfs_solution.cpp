class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis){
        if(vis[node]) return;
        vis[node] = true;

        for(auto nei : adj[node]){
            dfs(nei, adj, vis);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;

        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        for(auto connection : connections){
            int u = connection[0], v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                count++;
                dfs(i, adj, vis);
            }
        }

        return count-1;
    }
};