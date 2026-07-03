class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 0;
        int end = n-1;
        // find the two numbers between which the missing element will fit
        // if we find the prior of those two numbers than we can find our kth missing number

        // find the ("prior") number just after which the missing kth number may fit in the array
        while(start<=end){
            int mid = start+(end-start)/2;
            // if no. of missing numbers before mid, is larger than the kth number we want 
            if(arr[mid]-1-mid >= k){
                end = mid - 1; // go for the left half where the prior may exist
            } else {
                start = mid + 1; // else go for the right half where the prior may exist
            }
        }

        return end+k+1;
    }
};

// in an array with all integers (starting from 1) arranged in increasing order, the index of a number "k" would be k-1
// so by that logic the numbers missing in an array before a number k would be equal to the (index_without_missing_numbers - actual_index)
// which would be (k-1 - i)
// so the numbers missing before "k" in an array would be equal to k-1-i (where i is its index in the input array)