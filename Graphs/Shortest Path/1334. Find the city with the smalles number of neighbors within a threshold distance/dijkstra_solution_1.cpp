#define pii pair<int,int>
class Solution {
public:
    int dijkstra(int n, int node, vector<vector<pii>> adj, int distanceThreshold){
        vector<int> min_dist(n, 1e9);
        priority_queue<pii, vector<pii>, greater<pii>> min_heap;
        int nei_within_thres = 0;

        min_dist[node] = 0;
        min_heap.push({0, node});

        while(!min_heap.empty()){
            auto p = min_heap.top();
            min_heap.pop();
            int dist = p.first, curr = p.second;
            
            if(dist < min_dist[curr]) continue;

            for(auto p_nei : adj[curr]){
                int nei_dist = p_nei.first, nei = p_nei.second;
                if(min_dist[curr] + nei_dist < min_dist[nei]){
                    min_dist[nei] = min_dist[curr]+nei_dist;
                    min_heap.push({min_dist[nei], nei});
                }
            }
        }

        for(auto i : min_dist){
            if(i <= distanceThreshold){
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