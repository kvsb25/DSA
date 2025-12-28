class Solution {
public:
    int divide(long dividend, long divisor) {
        if(dividend == divisor) return 1;
        bool sign = false;
        if(dividend < 0) sign = !sign;
        if(divisor < 0) sign = !sign;

        long n = abs(dividend);
        long d = abs(divisor);
        long quot = 0;
        while(n>=d){
            int cnt = 0;
            while(n >= (d << (cnt+1))){
                cnt += 1;
            }
            quot += (1<<cnt);
            n -= (d<<cnt);
        }
        if(quot == (1<<31) && !sign){
            return INT_MAX;
        }
        if(quot == (1<<31) && sign){
            return INT_MIN;
        }
        return sign ? -quot : quot;
    }
};

// We don’t subtract divisor one by one.
// Instead, we subtract big chunks: divisor * (powers of two). from dividend;
// subtract subtract 'divisor * (powers of two)' when: divisor * ((power of two)-1) > dividend;
// Each chunk we subtract adds that power of two to the quotient.
// So the quotient becomes the sum of these powers of two.