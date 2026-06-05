class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int nxt = 1;
        for(int i = 1; i < n; i++){
            if(nums[i]!=nums[i-1]){
                nums[nxt]=nums[i];
                nxt++;
            }
        }
        return nxt;
    }
};

// nxt variable keeps track of the index next to the unique ele (considering the ele at 0th index as the first unique ele, 1 is the index next to the unique ele)
// for loop keeps incrementing 'i' till duplicates are encountered (as the array is sorted, duplicates will be next to each other)
// whenever consecutive duplicates end (meaning we encounter a unique element) [condition: curr ele != prev ele]
// nxt is incremented only when a unique ele is encountered. Hence, value of nxt == number of unique ele in the array