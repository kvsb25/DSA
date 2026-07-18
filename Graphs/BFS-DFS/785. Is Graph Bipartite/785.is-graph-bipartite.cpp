class Solution {
public:
    bool bfs(int node, vector<vector<int>>& graph, vector<int>& bi_set){
        if(bi_set[node]){ // if curr node is visited bi_set[node] != 0
            return true; // if node was visited and did not return false this means it is a valid node hence return true
        }

        queue<int> q;
        bi_set[node] = -1;
        q.push(node);

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto nei : graph[curr]){
                if(bi_set[nei] && bi_set[nei] == bi_set[curr]){ // if the nei is visited then it should be in the opposite set of curr, if not then it is not a bi-partite graph hence return false
                    return false;
                } else if(!bi_set[nei]){
                    bi_set[nei] = bi_set[curr] * -1;
                    q.push(nei); // as the nei was not visited earlier, push it to the queue.
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> bi_set(graph.size());

        for(int i = 0; i < graph.size(); i++){
            if(!bfs(i, graph, bi_set)) return false;
        }

        return true;
    }
};

// here we need to check the visited node also (as we have to check whether the neighbors of the current belong to the opposite set or not)
// so we use a single data structure (array) to store the set of the node as well as its visit status
// 0 == not visited, 1 == in set 1, -1 == in set 2