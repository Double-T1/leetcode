class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1) return INT_MAX;
            if (divisor == 1) return INT_MIN;
            if (divisor == INT_MIN) return 1;
            if (divisor&1) dividend++;
            else dividend >>=1, divisor >>=1;
        }
        if (divisor == INT_MIN) return 0;
        
        bool isNeg = dividend>0 ^ divisor>0;
        int a = abs(dividend), b = abs(divisor), ans = 0;
        while (a>=b) {
            int temp = b, cur = 1;
            while (temp <= (a >> 1)) {
                temp <<= 1;
                cur <<=1;
            }
            a -= temp;
            ans += cur;
        }
        return isNeg? (~ans)+1 : ans;
    }
};
