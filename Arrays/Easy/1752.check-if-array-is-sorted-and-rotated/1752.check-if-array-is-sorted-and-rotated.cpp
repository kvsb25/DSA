class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                count++;
            }
        }
        if (nums[n - 1] > nums[0])
        {
            count++;
        }

        return count <= 1;
    }
};

// if the array is sorted and rotated, at most 1 violation of the fact that the current element is smaller than the next is allowed.
// in a rotated array the next of the last element is the first element