class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle.back().size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        
        for (int i=m-1; i>=0; i--) {
            for (int j=0; j<=i; j++) {
                dp[j] = min(dp[j],dp[j+1]) + triangle[i][j]; 
            }
        }
        
        return dp[0];
    }
};
