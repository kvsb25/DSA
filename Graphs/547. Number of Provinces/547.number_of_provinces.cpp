class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<bool> vis(V, false);
        int ans = 0;

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                ans++;
                vis[i] = true;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int n = q.front();
                    q.pop();
                    
                    for(int j = 0; j < V; j++){
                        if(isConnected[n][j] && !vis[j]){
                            vis[j] = true;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return ans;
    }
};

// time complexity: O(V^2)