class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = nums[0];
        int total = 0;

        // iterate through each of the elements of the input array
        for (int n : nums)
        {
            // Logic: If the current sum (`total`) is negative,
            // If the current running sum (`total`) is negative, carrying it forward only reduces the overall sum.
            // Starting fresh at 'n' (by resetting total to 0) is always the better choice.
            // Mathematically: Since (total < 0), then (total + n) < (0 + n).
            // Therefore, we reset `total` to 0 to start a new, potentially optimal subarray from 'n'.
            if (total < 0)
            {
                total = 0;
            }

            total += n;
            res = max(res, total);
        }

        return res;
    }
};