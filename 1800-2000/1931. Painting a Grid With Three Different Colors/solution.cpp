class Solution {
private: 
    const int mod = 1e9+7;
    int col[3] = {0,1,2};
    int p;
    
public:
    int colorTheGrid(int m, int n) {
        p = pow(3,m);
        vector<vector<int>> dp(n*m,vector<int>(p,-1));
        return helper(n,m,0,0,0,dp);
    }
    
private:
    int helper(int n, int m, int i, int j, int state, vector<vector<int>>& dp) {
        if (j == m) i++, j=0;
        if (i == n) return 1;
        if (dp[i*m+j][state]>-1) return dp[i*m+j][state];
        
        int left = j>0? state%3: -1;
        int up = i>0 ? ((state*3)/p)%3 : -1;
        
        int ans = 0;
        for (auto c: col) {
            if (c == left || c == up) continue;
            ans += helper(n,m,i,j+1,update(state,c),dp);
            ans %= mod;
        }
        
        return dp[i*m+j][state] = ans;
    }
    
    int update(int state, int c) {
        return (state*3)%(this->p) + c;
    }
};

/*
for the convience of states, flip n and m=> consider m as cols, and n as rows


*/
