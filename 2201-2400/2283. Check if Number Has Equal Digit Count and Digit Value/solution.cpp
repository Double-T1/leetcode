class Solution {
public:
    bool digitCount(string num) {
        int n = num.size();
        int dict[n];
        memset(dict,0,sizeof(dict));
        
        for (int i=0; i<n; i++) {
            int v = num[i]-'0';
            if(v<n) dict[v]++;
        }
        
        for (int i=0; i<n; i++) {
            if (num[i]-'0' != dict[i]) return false;
        }
        return true;
    }
};
