class DisjointSet{
private:
    vector<int> rank;
    vector<int> parent;
    int size;
public:
    DisjointSet(int n){
        rank.assign(n, 0);
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size = n;
    }

    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void union_by_rank(int i, int j){
        int root_i = find(i);
        int root_j = find(j);

        if(root_i != root_j){
            if(rank[root_i] < rank[root_j]){
                parent[root_i] = root_j;
            } else if(rank[root_i] > rank[root_j]){
                parent[root_j] = root_i;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int max_rows = 0, max_cols = 0;
        for(auto s : stones){
            max_rows = max(max_rows, s[0]);
            max_cols = max(max_cols, s[1]);
        }
        
        int n = max_rows + max_cols + 2;
        DisjointSet d(n);
        unordered_set<int> nodes;
        for(auto s : stones){
            int row = s[0];
            int col = s[1] + max_rows + 1;
            
            d.union_by_rank(row, col);
            nodes.insert(row);
            nodes.insert(col);
        }

        int components = 0;
        for(auto node : nodes){
            if(d.find(node) == node){
                components++;
            }
        }

        return stones.size() - components;
    }
};

// take rows and cols as individual nodes and stones as edges (hence use stones to deduce connection between rows and cols)
// the disjoint components made among rows and cols as nodes would be same as the components made among stones as nodes
// taking rows and columns reduces time complexity to O(max_rows + max_cols)