class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, 1e9);
        prices[src] = 0;

        for(int i = 0; i < k+1; i++){ // takes care each of the layers
            vector<int> temp(prices); 

            // edges that can be reached in current layer of traversal
            for(auto edge : flights){
                int s = edge[0], d = edge[1], p = edge[2];
                if(prices[s] == 1e9) continue; // this ensures only the edges of the sources that can be reached (dist[s] != infi) are traversed
                if(prices[s]+p < temp[d]){
                    temp[d] = prices[s] + p;
                }
            }
            prices = temp;
        }

        if(prices[dst] == 1e9) prices[dst] = -1;
        return prices[dst];
    }
};