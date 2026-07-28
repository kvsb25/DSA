#define pii pair<int,int>
class Solution {
public:
    int dijkstra(int n, int node, vector<vector<pii>> adj, int distanceThreshold){
        vector<int> min_dist(n, 1e9);
        vector<bool> vis(n, false);
        priority_queue<pii, vector<pii>, greater<pii>> min_heap;
        int nei_within_thres = 0;

        min_dist[node] = 0;
        min_heap.push({0, node});

        while(!min_heap.empty()){
            auto p = min_heap.top();
            min_heap.pop();
            int dist = p.first, curr = p.second;
            
            if(vis[curr]) continue;
            vis[curr] = true;

            for(auto p_nei : adj[curr]){
                int dist2 = p_nei.first, nei = p_nei.second;
                int nei_dist = dist + dist2;
                if(nei_dist <= distanceThreshold){
                    min_heap.push({nei_dist, nei});
                }
            }
        }

        for(auto i : vis){
            if(i){
                nei_within_thres += 1;
            }
        }

        return (nei_within_thres-1);
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pii>> adj(n);

        for(auto edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        int min_count = INT_MAX, ans = 0;
        for(int src = 0; src < n; src++){
            int count = dijkstra(n, src, adj, distanceThreshold);
            if(count <= min_count){ // the city with count == min_count is also a valid answer hence we update the ans and min_count at this condition as well.
                min_count = count;
                ans = src;
            }
        }

        return ans;
    }
};