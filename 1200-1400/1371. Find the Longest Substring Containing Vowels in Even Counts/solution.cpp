class Solution {
public:
    int findTheLongestSubstring(string s) {
        int ans = 0, bitmask = 0, n = s.size();
        vector<int> count(pow(2,5),n);
        count[0] = -1;
        for (int i=0; i<n; i++) {
            int x = map(s[i]);
            if (x > -1) bitmask ^= 1 << x;
            
            count[bitmask] = min(count[bitmask],i);
            ans = max(ans,i - count[bitmask]);
        }
        return ans;
    }
    
private:
    int map(char x) {
        switch(x) {
            case 'a':
                return 0;
            case 'e':
                return 1;
            case 'i':
                return 2;
            case 'o':
                return 3;
            case 'u':
                return 4;
            default:
                return -1;
        }
        return -1;
    }
};
