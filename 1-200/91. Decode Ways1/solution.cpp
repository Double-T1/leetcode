class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.size(),-1);
        return helper(s,memo,0);
    }
    
private:
    int helper(string& s, vector<int>& memo, int i) {
        if (i == s.size()) return 1;
        if (memo[i]>-1) return memo[i];
        if (s[i] == '0') return memo[i] = 0;
        int ans = helper(s,memo,i+1);
        if (i<s.size()-1 && ((s[i] == '2' && s[i+1]<'7') || (s[i] == '1'))) {
            ans += helper(s,memo,i+2); 
        }
        return memo[i] = ans;
    }
};
