constexpr int mod = 1e9+7;

class Solution {
private:
    int k;
    
public:
    int distinctSequences(int n) {
        k = n;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(8,vector<int>(8,-1)));
        return helper(0,7,7,dp);
    }
    
private:
    int helper(int i, int last1, int last2, vector<vector<vector<int>>>& dp) {
        if (i == k) return 1;
        if (dp[i][last1][last2]>-1) return dp[i][last1][last2];
        
        long long ans = 0;
        for (int j=1; j<=6; j++) {
            if (last1 == j || last2 == j) continue;
            if (gcd(last1,j)>1) continue;
            ans += helper(i+1,j,last1,dp);
            ans %= mod;
        }
        return dp[i][last1][last2] = ans;
    }
};

/*
6 can't pair with 4,3,2
4 can't pair with 2

same numbers has a gap greater than 2 e.g. 0 with at least 3

Math or DP
can't be the same as past two
1: 2,3,4,5,6 => actually only 5 decisions we can make, since the one before 1 is definitely one of 2-6
2: 1,3,5 => 2 decisions
3: 1,2,4,5 => 4 decisions
4: 1,3,5 => 2
5: 1,2,3,4,6 => 5
6: 1,5 => 1

O(n*36)

x(i,last1,last2): the maximum pairs from i to n with the previous two numbers beign last1 and last2
*/
