class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize != 0) return false;

        // map to keep track of the frequency of each element
        unordered_map<int, int> count;
        for(auto& val: hand){
            count[val]++;
        }

        // min heap to keep track of the unique elements in ascending order (so that consecutive elements appear as they are)
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& [val, cnt] : count){
            pq.push(val);
        }

        while(!pq.empty()){
            int top = pq.top();

            // check if consecutive group of size groupSize can be formed or not
            for(int i = top; i < top+groupSize; i++){
                if(count.find(i) != count.end() && count[i] != 0){
                    count[i]--;
                } else {
                    // if any element that doesn't exist in the input array for the given range of consecutive numbers, then no group can be formed
                    return false;
                }
            }

            // pop the elements in ascending order whose count == 0
            while(!pq.empty() && count[pq.top()] == 0){
                pq.pop();
            }
        }

        return true;
    }
};

// for a number 'x', 'n' consecutive elements including 'x' would be the range [x, x+n).
// so considering top of min heap as 'x', if the range [x, x+n) doesn't exist in the input array then there is no chance of arranging the elements in consecutive order of size n
// here n is groupSize and 'x' is top of min heap whose count is not 0.