class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        long long n = numerator, d = denominator;
        string ans = "";
        
        if (n<0 && d>0) n *= -1, ans = "-" ;
        else if (n>0 && d<0) d *= -1, ans = "-";
        if (n<0 && d<0) d*= -1, n*= -1; 
        
        ans += to_string(n/d);
        n %= d;
        if (n>0) ans += ".";
        n *= 10;
        
        unordered_map<long long,int> dict;
        while(n) {
            if (n<d) {
                n *= 10;
                ans += "0";
            } else {
                if (dict.count(n)) {
                    ans = ans.substr(0,dict[n]) + "(" + ans.substr(dict[n],ans.size()-dict[n]) + ")";
                    break;
                }
                dict[n] = ans.size();
                
                ans += to_string(n/d);
                n %= d;
                n *= 10;
            }
        }
        return ans;
    }
};
