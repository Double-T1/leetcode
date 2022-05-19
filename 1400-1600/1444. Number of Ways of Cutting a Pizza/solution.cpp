class Solution {
private:
    int m, n;
    static constexpr int mod = 1e9 + 7;
    
public:
    typedef vector<vector<int>> vvi;    
    
    int ways(vector<string>& pizza, int k) {
        
        m = pizza.size(), n = pizza[0].size();
        vvi x(m,vector<int>(n,0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (pizza[i][j] == 'A') x[i][j]++;
                if(i>0) x[i][j] += x[i-1][j];
                if(j>0) x[i][j] += x[i][j-1];
                if(i>0 && j>0) x[i][j] -= x[i-1][j-1];
            }
        }
        
        if (k == 1) return x.back().back()>0? 1 : 0;
        vvi dp(m*n,vector<int>(k,-1));
        return helper(x,0,0,k-1,dp);
    }
    
private:
    int helper(vvi& x, int i1, int j1, int k,vvi& dp) {
        if (dp[i1*n+j1][k]>-1) return dp[i1*n+j1][k];
        if (k == 0) {
            //cout << i1 << j1 << " " << i2 << j2 << endl;
            return 1;
        }
        int ans = 0;
        for (int r=i1; r<m-1 && hasOne(x,r+1,j1,m-1,n-1); r++) {
            if (hasOne(x,i1,j1,r,n-1)) ans += helper(x,r+1,j1,k-1,dp);
            ans %= mod;
        }
        
        for (int c=j1; c<n-1 && hasOne(x,i1,c+1,m-1,n-1); c++) {
            if (hasOne(x,i1,j1,m-1,c)) ans += helper(x,i1,c+1,k-1,dp);    
            ans %= mod;
        }
        
        return dp[i1*n+j1][k] = ans; 
    }
    
    //check if at least one apple exists in this block
    bool hasOne(vvi& x,int i1, int j1, int i2, int j2) {
        int ans = x[i2][j2];
        if (i1>0) ans -= x[i1-1][j2];
        if (j1>0) ans -= x[i2][j1-1];
        if (i1>0 && j1>0) ans += x[i1-1][j1-1];
        return ans;
    }
};
