class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        int e = *(max_element(piles.begin(), piles.end()));
        int ans = e;

        while(s<=e){
            int k = s+(e-s)/2;
            double hours = 0;
            // calculating the time taken for eating the entire pile with speed k
            for(auto pile : piles){
                hours += ceil((double)pile/(double)k); // typecast to double type as int won't represent the correct ceil value
            }
            if(hours<=h){
                ans = min(ans, k);
                e = k - 1;
            } else {
                s = k + 1;
            }
        }
        return ans;
    }
};

// the maximum speed (k = bananas/hour) in which all the piles can be eaten under 'h' hours, is the maximum pile size. As it would help koko eat all the piles in hours = no. of piles
// between 1 and max_element(piles), lies the minimum speed that would help koko eat all the bananas in less than or equal to 'h' hours