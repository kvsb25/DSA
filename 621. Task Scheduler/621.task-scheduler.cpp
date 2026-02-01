class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(auto c : tasks){
            freq[c-'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCount = 0;
        for(auto i: freq){
            if(maxFreq == i){
                maxCount++;
            }
        }

        int partCount = maxFreq - 1; // leaving the last
        int partLength = n+1;
        int minTime = partCount*partLength + maxCount;

        return max((int)tasks.size(), minTime);
    }
};