class Solution {
public:
    static const int MOD = 1e9+7; // using MOD to prevent overflow

    long long pow(long long x, long long n){
        if(n == 0) return 1;

        long long ans = 1;
        while(n > 0){
            // if power is odd, multiply base to ans assign to ans and decrement power by 1 (making power even and multiplying base to the ans as well)
            if(n%2==1){
                ans = (ans*x)%MOD; // mod MOD to prevent overflow
                n -= 1;
            // if power is even, square the base and divide the power by two [reducing the problem by half (divide and conquer)]
            } else {
                x = (x*x)%MOD; // mod MOD to prevent overflow
                n = n/2;
            }
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;  // calculating the number of even indexes
        long long odd = n/2;  // calculating the number of odd indexes
        return (pow(5, even)*pow(4, odd))%MOD;
    }
};