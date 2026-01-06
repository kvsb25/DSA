class Solution {
public:

    int sumIfFourDivisors(int num){
        int sum = 0, count = 0;
        for(int i = 1; i <= num/2; i++){
            if(num%i == 0){
                sum+=i;
                count++;
            }
        }
        sum += num;
        count++;
        return count == 4 ? sum : -1 ;
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            int temp = sumIfFourDivisors(num);
            if(temp != -1){
                sum += temp;
            }
        }
        return sum;
    }
};

// TLE on large cases