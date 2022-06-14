class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[n+1];
        int diaganol = 0;
        for (int i=m; i>=0; i--) {
            for (int j=n; j>=0; j--) {
                int temp = i==m ? 0 : dp[j];
                if (i == m || j == n) dp[j] = m-i+n-j;
                else if(word1[i] != word2[j]) dp[j] = min(dp[j],dp[j+1])+1;
                else dp[j] = diaganol;
                
                diaganol = temp;
            }
        }
        
        return dp[0];
    }
};
