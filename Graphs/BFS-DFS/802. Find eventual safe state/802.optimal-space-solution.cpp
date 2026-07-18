class Solution {
public:
    bool dfs(int node, unordered_map<int, bool>& safe, vector<vector<int>>& graph){
        if(safe.count(node)){
            return safe[node];
        }

        safe[node] = false;
        for(auto nei : graph[node]){
            if(!dfs(nei, safe, graph)){
                return false; 
            }
        }

        safe[node] = true;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        unordered_map<int, bool> safe;
        vector<int> ans;

        for(int i = 0; i < graph.size(); i++){
            if(dfs(i, safe, graph)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};

// using the same data structure for checking whether the node is visited and is safe.
// existence of key in map tells its visited
// value tells whether safe or not