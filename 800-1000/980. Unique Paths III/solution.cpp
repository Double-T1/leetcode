//time: O(2^(m*n) * (m*n))
class Solution {
private:
    int a,b,end,m,n,c;
    int row[4] = {0,1,0,-1};
    int col[4] = {1,0,-1,0};
    
public:
    typedef vector<vector<int>> vvi;
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(),c = pow(2,m*n)-1;
        vvi dp(m*n, vector<int>(c+1,-1));
        int bitset = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    a = i, b = j;
                    bitset |= 1 << (i*n+j);
                } else if (grid[i][j] == 2) {
                    end = i*n+j;
                } else if (grid[i][j] == -1) {
                    bitset |=  1 << (i*n+j);
                }
            }
        }
        
        return helper(dp,bitset,a,b);
    }
    
private:
    int helper(vvi& dp, int bitset, int i, int j) {
        int cur = i*n + j;
        if (dp[cur][bitset]>-1) return dp[cur][bitset];
        if (cur == end) return dp[cur][bitset] = bitset == c;
        
        int ans = 0;
        for (int k=0; k<4; k++) {
            int p = i+row[k], q = j+col[k];
            if (p<0 || p>=m || q<0 || q>=n || bitset&(1<<p*n+q)) continue;
            ans += helper(dp,bitset|(1<<p*n+q),p,q);
        }
        return dp[cur][bitset] = ans;
    }
};
