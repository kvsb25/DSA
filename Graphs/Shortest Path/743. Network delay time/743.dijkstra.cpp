struct Path {
    int time;
    int node;
};

struct Comparator {
    bool operator()(const Path& t1, const Path& t2) const {
        return t1.time > t2.time; 
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(const auto& edge : times){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({w, v});
        }

        vector<bool> vis(n + 1, false);
        priority_queue<Path, vector<Path>, Comparator> minHeap;
        minHeap.push({0, k});
        
        int ans = 0;
        int visitedCount = 0;

        while(!minHeap.empty()){
            auto p = minHeap.top();
            minHeap.pop();
            
            int w1 = p.time, u = p.node;
            
            if(vis[u]) continue; 
            
            vis[u] = true;
            visitedCount++;
            
            ans = max(ans, w1); 

            for(auto p : adj[u]){
                int w2 = p.first, nei = p.second;
                if(!vis[nei]){
                    minHeap.push({w1 + w2, nei});
                }
            }
        }

        return visitedCount == n ? ans : -1;
    }
};