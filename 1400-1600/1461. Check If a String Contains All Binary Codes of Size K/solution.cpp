class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size(), cur = 0, need = pow(2,k), allOne = need-1;
        if (n<k) return false;
        
        bool seen[need];
        memset(seen,0,sizeof(seen));
        for (int i=0; i<n; i++) {
            cur <<= 1;
            cur |= s[i] - '0';
            cur &= allOne;
            
            if (i>=k-1 && !seen[cur]) {
                seen[cur] = true;
                need--;
                
                if (need == 0) return true;
            }
        }
        
        return false;
    }
};
