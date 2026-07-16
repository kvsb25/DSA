class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& prereq, vector<bool>& vis, vector<bool>& cyc, vector<int>& ans){
        if(cyc[node]) return false;
        if(vis[node]) return true;

        cyc[node] = true;
        for(auto pre : prereq[node]){
            if(!dfs(pre, prereq, vis, cyc, ans)) return false;
        }
        cyc[node] = false;
        vis[node] = true;
        ans.push_back(node);
        
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq; // space comp == num of edges
        vector<bool> vis(numCourses, false); // space comp == num of vertices
        vector<bool> cyc(numCourses, false); // space comp == num of vertices
        vector<int> ans; // space comp == num of vertices

        for(auto crs : prerequisites){
            prereq[crs[0]].push_back(crs[1]);
        }

        for(int i = 0; i<numCourses; i++){
            if(!dfs(i, prereq, vis, cyc, ans)) return {};
        }

        return ans;
    }
};

// Time complexity: O(V+E)
// space comp: O(3*V+E) + O(V) (S.C. of call stack)