class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;

        int numOfInc = n/2;
        int numOfDec = numOfInc - 1;
        return s + numOfInc * m - numOfDec;
    }
};