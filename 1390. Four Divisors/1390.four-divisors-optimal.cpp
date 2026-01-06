class Solution {
public:
    vector<bool> sieve;

    void buildSieve(int n){
        sieve = vector<bool>(n+1, true);
        sieve[0] = sieve[1] = false;
        for(int i = 2; i*i <= n; i++){
            if(sieve[i]){
                for(int j = i*i; j<=n; j+=i){
                    sieve[j] = false;
                }
            }
        }
    }

    bool isPrime(int n){
        if(n < sieve.size()) return sieve[n];
        return false;
    }

    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        int maxNum = 0;

        for(auto num: nums){
            maxNum = max(maxNum, num);
        }

        buildSieve(maxNum);

        for(auto num: nums){

            // check if num is cube of a prime
            int p = round(cbrt(num));
            if(p*p*p == num && isPrime(p)){
                totalSum += (1 + p + p*p + num);
                continue; // no need to check if num is a product of two distinct integers
            }

            // if num not a cube of prime
            // then check if product of two distinct primes
            for(int i = 2; i*i <= num; i++){
                if(num % i == 0){
                    int j = num/i;
                    if(i != j && isPrime(i) && isPrime(j)){
                        totalSum += (1 + i + j + num);
                    }
                    break; // only first factor needed. As we don't want to end up adding the same sum of divisors twice, in the total sum
                }
            }
        }

        return totalSum;
    }
};

// a number has 4 divisors if and only if: it is cube of a prime (p^3 == num) OR a product of two distinc prime (p * q)
// so we first compute all the prime number from 0 till the maximum number in the given input array
// then we iterate the given array to know if it has 4 divisors (i.e. we check if either it is a cube of prime or it is a product of two distinct primes) 
// if yes then add the sum of those divisors to the totalSum