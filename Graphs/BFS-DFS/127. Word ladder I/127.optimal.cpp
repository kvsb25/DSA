class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        
        unordered_map<string, vector<string>> adj;
        unordered_set<string> vis;
        queue<string> q;

        for(auto word : wordList){
            for(int i = 0; i<word.size(); i++){
                string pattern = word.substr(0, i) + "*" + word.substr(i+1);
                adj[pattern].push_back(word);
            }
        }


        q.push(beginWord);
        vis.insert(beginWord);
        int steps = 0;

        while(!q.empty()){
            int size = q.size();
            steps += 1;
            while(size-->0){
                string curr = q.front();
                q.pop();


                if(curr == endWord) return steps;
                
                for(int i = 0; i<curr.size(); i++){
                    string pattern = curr.substr(0, i) + "*" + curr.substr(i+1);
                    for(auto next : adj[pattern]){
                        if(!vis.contains(next)){
                            vis.insert(next);
                            q.push(next);
                        }
                    }
                }
            }
        }

        return 0;
    }
};

// time complexity: O(M*L^2)