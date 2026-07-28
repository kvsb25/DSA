class DisjointSet{
private:
    vector<int> parent;
    vector<int> rank;
    int size;
public:
    DisjointSet(int _size){
        size = _size;
        parent.resize(size);
        rank.assign(size, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i){
        if(parent[i] == i){
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void unite(int i, int j){
        int root_i = find(i);
        int root_j = find(j);

        if(root_i != root_j){
            if(rank[root_i] < rank[root_j]){
                parent[root_i] = root_j;
            } else if(rank[root_i] > rank[root_j]){
                parent[root_j] = root_i;
            } else{
                rank[root_i]++;
                parent[root_j] = root_i;
            }
        }
    }

    int components(){
        int count = 0;
        for(int i = 0; i < size; i++){
            if(parent[i] == i) count++;
        }
        return count;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        DisjointSet d(n);
        
        for(auto cnctn : connections){
            d.unite(cnctn[0], cnctn[1]);
        }

        int components = d.components();
        return components-1;
    }
};