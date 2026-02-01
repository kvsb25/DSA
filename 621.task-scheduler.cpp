/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        
        unordered_map<char, int> mp;
        for(auto const& task : tasks){
            mp[task]++;
        }

        for(auto [task, freq] : mp){
            pq.push(freq);
        }

        int time = 0;
        queue<pair<int,int>> remaining;

        while(!pq.empty()){
            int freq = pq.top(); pq.pop();
            time++;
            remaining.push({freq-1, time+n});

            auto [rFreq, execTime] = remaining.front();
            if(execTime <= time){
                remaining.pop();
                if(rFreq > 0)
                    pq.push(rFreq);
            }
        }

        return time;
    }
};
// @lc code=end

