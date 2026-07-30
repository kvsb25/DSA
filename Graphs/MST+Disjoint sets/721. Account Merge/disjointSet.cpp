class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;
public:
    DisjointSet(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size.assign(n, 1);
    }

    int find(int i){
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unionBySize(int i, int j){
        int root_i = find(i);
        int root_j = find(j);

        if(root_i != root_j){
            if(size[root_i] < size[root_j]){
                parent[root_i] = root_j;
                size[root_j] += size[root_i];
            } else {
                parent[root_j] = root_i;
                size[root_i] += size[root_j];
            }
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        
        unordered_map<string, int> mailToAcc;

        for(int i = 0; i<n; i++){
            for(int j = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(!mailToAcc.count(mail)){
                    mailToAcc[mail] = i;
                }else{
                    ds.unionBySize(i, mailToAcc[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto p : mailToAcc){
            string mail = p.first;
            int acc = p.second;
            int rootAcc = ds.find(acc);
            mergedMail[rootAcc].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i<n; i++){
            if(mergedMail[i].size() == 0) continue;
            vector<string> temp;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            temp.push_back(accounts[i][0]);
            for(auto mail : mergedMail[i]){
                temp.push_back(mail);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

// use a map to track each mail and it's account
// if a mail is associated with an account then union(that account, curr_account)
// else associate the mail with the curr_account
// then push every mail to its root account
// sort and push into final ans array