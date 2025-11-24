class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto c : s){
            mp[c]++;
        }
        string ans = "";
        priority_queue<pair<int, char>> pq;
        for(auto pair : mp){
            pq.push({pair.second, pair.first});
        }
        int n = pq.size();
        for(int i = 0; i < n; i++){
            ans += string(pq.top().first, pq.top().second);
            pq.pop();
        }

        return ans;
    }
};