//solution 4 is the best

//conventional top-down dp
class Solution {
private:
    int m, n;
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')' || grid.back().back() == '(' || (m+n)%2 == 0) return false;
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>((m+n)/2+1,-1)));
        return helper(dp,grid,0,0,0);
    }
private:
    bool helper(vector<vector<vector<int>>>& dp, vector<vector<char>>& grid, int i, int j, int l) {
        if (j == n || i == m || j<0 || i<0 || l<0 || l>(m+n)/2) return false;
        if (i == m-1 && j == n-1) return l == 1;
        if (dp[i][j][l]>-1) return dp[i][j][l];
        
        int curL = grid[i][j] == '(' ? l+1 : l-1;        
        return dp[i][j][l] = helper(dp,grid,i+1,j,curL) || helper(dp,grid,i,j+1,curL);
    }
};

//bottom-up 
//same complexity
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')' || grid.back().back() == '(' || (m+n)%2 == 0) return false;
        bool dp[m][n][(m+n)/2+1];
        memset(dp,-1,sizeof(dp));
        
        auto getPrev = [&](int i, int j, int l){
            if (j == n || i == m || j<0 || i<0 || l<0 || l>(m+n)/2) return false;
            return dp[i][j][l];
        };
        
        for (int i=m-1; i>=0; i--) {
            for (int j=n-1; j>=0; j--) {
                for (int l=0; l<=(m+n)/2; l++) {
                    int curL = grid[i][j] == '(' ? l+1 : l-1; 
                    if (i == m-1 && j == n-1) dp[i][j][l] = l == 1;
                    else dp[i][j][l] = getPrev(i+1,j,curL) || getPrev(i,j+1,curL);
                }
            }
        }
        
        return dp[0][0][0];
    }
};

//alternative bottom-up
//same idea but from reverse direction
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')' || grid.back().back() == '(' || (m+n)%2 == 0) return false;
        
        vector<vector<vector<bool>>> dp(m,vector<vector<bool>>(n,vector<bool>((m+n)/2+1,false)));
        dp[0][0][0] = true;
        int limit = (m+n)/2;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                for (int l=0; l<=limit; l++) {
                    int curL = grid[i][j] == ')' ? l-1 : l+1;
                    if (curL<0 || curL>limit) continue;
                    if (i<m-1) dp[i+1][j][curL] = dp[i+1][j][curL] || dp[i][j][l];
                    if (j<n-1) dp[i][j+1][curL] = dp[i][j+1][curL] || dp[i][j][l];
                }
            }
        }
        
        return dp[m-1][n-1][1];
    }
};

//solution 3
//bit trick
//build upon alternate solution 2
//fast as fuck, as expected
//time: O(m*n*(m+n)/32) or 64, depends on the cpu
//space: O(m*n*(m+n)/32)
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')' || grid.back().back() == '(' || (m+n)%2 == 0) return false;
        
        vector<vector<bitset<101>>> dp(m,vector<bitset<101>>(n));
        dp[0][0][0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                auto x = grid[i][j] == ')'? (dp[i][j] >> 1) : (dp[i][j] << 1);
                if (i<m-1) dp[i+1][j] |= x;
                if (j<n-1) dp[i][j+1] |= x;
            }
        }
        
        return dp[m-1][n-1][1];
    }
};

//solution 3-2
//bit trick that compresses the space
//time: O(m*n*(m+n)/32) 
//space: O(n*(m+n)/32) => 1D space only
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == ')' || grid.back().back() == '(' || (m+n)%2 == 0) return false;
        
        vector<bitset<101>> dp(n+1);
        dp[0][0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i == m-1 && j == n-1) break;
                auto x = grid[i][j] == ')'? (dp[j] >> 1) : (dp[j] << 1);
                dp[j+1] |= x;
                dp[j] = x;
            }
        }
        
        return dp[n-1][1];
    }
};
