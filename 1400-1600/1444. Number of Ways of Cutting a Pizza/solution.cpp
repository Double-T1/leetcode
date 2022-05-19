//solution 1
//top-down => TLE
//r*c = 2.5* 10^3
//time: O((r*c)^2 * k * max(r,c))
//O(6.25 * 10^6 * 10 * 50) => O(10^8 * 31.25) TLE
class Solution {
private:
    int m, n;
    static constexpr int mod = 1e9 + 7;
    
public:
    typedef vector<vector<vector<int>>> vvv;
    
    int ways(vector<string>& pizza, int k) {
        
        m = pizza.size(), n = pizza[0].size();
        vector<vector<int>> x(m,vector<int>(n,0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (pizza[i][j] == 'A') x[i][j]++;
                if(i>0) x[i][j] += x[i-1][j];
                if(j>0) x[i][j] += x[i][j-1];
                if(i>0 && j>0) x[i][j] -= x[i-1][j-1];
            }
        }
        
        if (k == 1) return hasOne(x,0,0,m-1,n-1);
        vvv dp(m*n,vector<vector<int>>(m*n,vector<int>(k,-1)));
        return helper(x,0,0,m-1,n-1,k-1,dp);
    }
    
private:
    int helper(vector<vector<int>>& x, int i1, int j1, int i2, int j2, int k,vvv& dp) {
        if (k == 0) return 1;
        if (dp[i1*n+j1][i2*n+j2][k]>-1) return dp[i1*n+j1][i2*n+j2][k];
        
        int ans = 0;
        for (int r=i1; r<i2 && hasOne(x,r+1,j1,i2,j2); r++) {
            if (hasOne(x,i1,j1,r,j2)) ans += helper(x,r+1,j1,i2,j2,k-1,dp);
            ans %= mod;
        }
        
        for (int c=j1; c<j2 && hasOne(x,i1,c+1,i2,j2); c++) {
            if (hasOne(x,i1,j1,i2,c)) ans += helper(x,i1,c+1,i2,j2,k-1,dp);    
            ans %= mod;
        }
        
        return dp[i1*n+j1][i2*n+j2][k] = ans; 
    }
    
    //check if at least one apple exists in this block
    bool hasOne(vector<vector<int>>& x,int i1, int j1, int i2, int j2) {
        int ans = x[i2][j2];
        if (i1>0) ans -= x[i1-1][j2];
        if (j1>0) ans -= x[i2][j1-1];
        if (i1>0 && j1>0) ans += x[i1-1][j1-1];
        return ans;
    }
};

