class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1, sum = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum += 1;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak += 1;
                sum += peak;
                i++;
            }

            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                sum += down;
                i++;
                down += 1; // final value for down would be the value for the peak before the decreasing curve
            }

            if(down>peak){
                sum += (down-peak);
                // sum -= peak;
                // sum += down;
            }
        }
        return sum;
    }
};

// use the concept of slope
// for flat slope (0 slope) just add 1 to the sum and skip the current iteration.
// for increasing slope maintain a peak and add it to the sum.
// for decreasing slope maintain a down and add it to the sum. when we shift from an increasing curve to decreasing curve we would start tracking down after the original peak element(the maxima from the previous increasing slope) so we need to init down = 1 then first add down to sum and then update down.
// if down is greater than the peak this means there are more elements lesser than the peak element on the decreasing side than on the increasing side so the new peak value for the peak element becomes the greater down value. So, we remove add the down-peak to sum
// peak keeps the count of elements lesser than the local maxima element (peak element) on the increasing curve and relatively greater than each other (hence the count corresponding to the candies that can be given)
// down keeps the count of elements lesser than the local maxima element (peak element) on the decreasing curve and relatively lesser than each other (hence the count corresponding to the candies that can be given)