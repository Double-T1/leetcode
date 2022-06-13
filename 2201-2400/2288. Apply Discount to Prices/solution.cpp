class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string ans = "", cur = "";
        int n = sentence.size();
        int d = (100-discount);
        
        for (int i=0; i<n; i++) {
            if (sentence[i] == '$') {
                ans += '$';
                
                if (i>0 && sentence[i-1] != ' ') continue;
                while (i<n-1 && sentence[i+1]<='9' && sentence[i+1]>='0') {
                    i++;
                    cur += sentence[i];
                }
                
                if (cur.empty() || (i<n-1 && sentence[i+1] != ' ')) {
                    ans += cur;
                } else {
                    long long p = stoll(cur);
                    p *= d;
                    string decimals = p%100 > 9? to_string(p%100) : '0' + to_string(p%100);
                    p /= 100;                   
                    
                    ans += to_string(p) + '.' + decimals;
                }
                
                cur = "";
            } else {
                ans += sentence[i];
            }
        }
        
        return ans;
    }
};

/*
an array of char is a price if 
1. starts with a $
2. only consists of digits after $ and before space or end
3. without leading zeros

calc discount:
double p
p - p*discount/100
=> p = p * (100-discount)/100

to get two decimal points
p *= 100;
p = trunc(p);
p /= 100;

string x = to_string(p);

if less than two decimal points => add 0s to fill up



*/
