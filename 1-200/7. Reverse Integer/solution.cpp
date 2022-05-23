//solution 1 using long
class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        bool isNeg = x<0;
        x = abs(x);
        while (x) {
            ans *= 10;
            ans += x%10;
            x /= 10;
        }
        if (isNeg) ans *= -1;
        return ans<=INT_MAX && ans>=INT_MIN ? (int) ans :  0; 
    }
};

//solution 2
class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x) {
            int p = x%10;
            x /= 10;
            
            if (ans > INT_MAX/10 || (ans == INT_MAX/10 && p > 7)) return 0;
            if (ans < INT_MIN/10 || (ans == INT_MIN/10 && p < -8)) return 0;
            
            ans *= 10;
            ans += p;
        }
        return ans; 
    }
};
