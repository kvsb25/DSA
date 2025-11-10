class Solution {
public:
    bool possible(vector<int> bloomDay, int day, int m, int k){
        int count = 0;
        int noOfB = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                count++;
            } else {
                noOfB += count/k;
                count = 0;
            }
        }
        noOfB += count/k;
        return noOfB >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long var = m * 1LL * k * 1LL;
        if(var > bloomDay.size()) return -1;
        int start = *(min_element(bloomDay.begin(), bloomDay.end()));
        int end = *(max_element(bloomDay.begin(), bloomDay.end()));
        while(start<=end){
            int day = start+(end-start)/2;
            if(possible(bloomDay, day, m, k)){
                end = day - 1;
            } else {
                start = day + 1;
            }
        }
        return start;
    }
};