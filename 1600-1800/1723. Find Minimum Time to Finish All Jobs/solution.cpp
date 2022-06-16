//time: O(k*3^n)
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size(), limit = 1 << n;
        int sum[limit], i = 0;
        sum[0] = 0;
        for (int m=1; m<limit; m++) {
            int submask = m&(m-1);
            if (submask==0) sum[m] = jobs[i++];
            else sum[m] = sum[submask] + sum[m^submask];
        }
        
        vector<vector<int>> dp(k+1,vector<int>(limit,INT_MAX));
        dp[0][0] = 0;
        for (int i=0; i<k; i++) {
            for (int mask=0; mask<limit; mask++) {
                if (dp[i][mask] == INT_MAX) continue;
                int comp = limit-mask-1;
                for (int submask=comp; submask; submask=(submask-1)&comp) {
                    dp[i+1][mask|submask] = min(dp[i+1][mask|submask],
                                               max(dp[i][mask],sum[submask]));
                }
            }
        }
        return dp[k][limit-1];
    }
};


/*
split the vector into k groups, find the minimum possible maximum accumulation among the groups of different assignments

x(i,mask): the minimum possible max working time when there are i workers, with masked jobs chosen
target: all jobs chosen with a workforce of k, x(k,limit-1)
base case: x(0,0) = 0, x(0,other) = invalid;

x(i+1,mask|newMask) = min{max(x(i,mask),sum(newMask))|newMask of not mask}

*/
