class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0, r = cardPoints.size()-1, sum = 0, maxSum = 0;
        int n = cardPoints.size();

        // calculate sum as if only left was selected
        while(l < k){
            sum += cardPoints[l++];
        }

        l--;
        maxSum = sum;

        while(r >= n-k-1 && l>=0){
            sum -= cardPoints[l--];
            sum += cardPoints[r--];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

// calculate all the sum of all the possible subarrays according to the question condition (pick either from left or right at a time)
// and track the maxSum on the go