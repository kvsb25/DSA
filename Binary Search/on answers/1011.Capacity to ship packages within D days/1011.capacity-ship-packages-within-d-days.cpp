class Solution {
public:
    int daysToShip(vector<int>& wts, int maxShipWt) {
        int days = 0;
        int currShipWt = 0;
        for (auto wt : wts) {
            currShipWt += wt;
            if (currShipWt > maxShipWt) {
                days++;
                currShipWt = wt;
            }
        }
        if (currShipWt <= maxShipWt)
            days++;

        return days;
    }

    int sumArr(vector<int>& wts) {
        int sum = 0;
        for (auto wt : wts) {
            sum += wt;
        }
        return sum;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int start = *(max_element(weights.begin(), weights.end()));
        int end = sumArr(weights);

        while (start <= end) {

            int maxShipWt = start + (end - start) / 2;

            if(daysToShip(weights, maxShipWt) <= days){
                end = maxShipWt - 1;
            } else {
                start = maxShipWt + 1;
            }
        }
        return start;
    }
};