class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj_list, vector<bool>& vis){
        if(vis[node]) return false;
        if(adj_list.size() == 0) return true;

        vis[node] = true;
        for(auto i : adj_list[node]){
            if(!dfs(i, adj_list, vis)) return false;
        }

        vis[node] = false;
        adj_list[node] = {};
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        vector<bool> vis(numCourses, false);

        for(auto e : prerequisites){
            adj_list[e[0]].push_back(e[1]);
        }

        for(int i = 0; i < adj_list.size(); i++){
            if(!dfs(i, adj_list, vis)) return false;
        }

        return true;
    }
};