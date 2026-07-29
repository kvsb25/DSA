class DisjointSet{
private:
    vector<int> rank;
    vector<int> parent;
    vector<int> comp_size;
    int size;
public:
    DisjointSet(int n){
        rank.assign(n, 0);
        comp_size.assign(n, 1);
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

    void unite(int i, int j){
        int root_i = find(i);
        int root_j = find(j);

        if(root_i != root_j){
            if(rank[root_i] < rank[root_j]){
                parent[root_i] = root_j;
                comp_size[root_j] += comp_size[root_i];
                comp_size[root_i] = 0;
            } else if(rank[root_i] > rank[root_j]){
                parent[root_j] = root_i;
                comp_size[root_i] += comp_size[root_j];
                comp_size[root_j] = 0;
            } else {
                parent[root_j] = root_i;
                rank[root_i]++;
                comp_size[root_i] += comp_size[root_j];
                comp_size[root_j] = 0;
            }
        }
    }

    int sizeOfLargestComponent(){
        int ans = 0;
        for(int i = 0; i < size; i++){
            if(comp_size[i]>1){
                ans += comp_size[i]-1;
                // comp_size[i] = 1;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet d(n);
        for(int i = 0; i <n; i++){
            vector<int> s1 = stones[i]; // stone at i
            for(int j = 0; j<i; j++){
                vector<int> s2 = stones[j]; // stone at j
                if(s1[0] == s2[0] || s1[1] == s2[1]){
                    d.unite(i, j);
                }                
            }
        }

        return d.sizeOfLargestComponent();
    }
};