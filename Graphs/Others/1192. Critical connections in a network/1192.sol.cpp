class Solution {
public:

    void dfs(int node, int& timer, vector<int>& low, vector<int>& tin, vector<bool>& vis, vector<vector<int>>& adj, vector<vector<int>>& critical, int parent){
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;

        for(auto nei : adj[node]){
            if(nei == parent) continue;
            if(!vis[nei]){
                dfs(nei, timer, low, tin, vis, adj, critical, node);
                low[node] = min(low[node], low[nei]);

                if(low[nei] > tin[node]){
                    critical.push_back({node, nei});
                }
            } else {
                low[node] = min(low[node], low[nei]);
            }

        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int timer = 0;
        vector<int> low(n), tin(n);
        vector<bool> vis(n);
        vector<vector<int>> adj(n);

        for(auto connection : connections){
            int u = connection[0], v = connection[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> critical;

        dfs(0, timer, low, tin, vis, adj, critical, -1);

        return critical;
    }
};