#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto& road: roads) {
            ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        return dijkstra(graph, n, 0);
    }
    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.push({0, 0}); // dist, src
        while (!minHeap.empty()) {
            auto[d, u] = minHeap.top(); minHeap.pop();
            if (d > dist[u]) continue; // Skip if `d` is not updated to latest version!
            for(auto [v, time] : graph[u]) {
                if (dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u]; // this is the time we find a cheaper path, so the number of ways we can arrive at this vertex (this nei of curr node) with the cheapest cost would be equal to the number of ways we can arrive at its parent. Even if we have a value for path_count[nei] already that would be all the ways we could reach without this cheap cost, so this time we found a better cost way so we will overwrite it.
                    minHeap.push({dist[v], v});
                } else if (dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % MOD; // we found another parent for this neighbor that can help us reach here with the current cheapest cost (min_cost[nei]), therefore we add it's parent's total num of ways. (as we found more ways we could reach this vertex (nei) with this cheapest cost (min_cost[nei]).
                }
            }
        }
        return ways[n-1];
    }
};