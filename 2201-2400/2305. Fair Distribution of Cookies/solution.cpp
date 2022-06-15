//solution 1
//time: O(n^k)
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> dist(k,0);
        return backtrack(cookies,0,k,dist,0);
    }
    
private:
    int backtrack(vector<int>& cookies, int i, int k, vector<int>& dist,int maxVal) {
        if (i == cookies.size()) return maxVal;
        
        int ans = INT_MAX;
        for (int j=0; j<k; j++) {
            dist[j] += cookies[i];
            ans = min(ans,backtrack(cookies,i+1,k,dist,max(maxVal,dist[j])));
            dist[j] -= cookies[i];
        }
        
        return ans;
    }
};

//solution 2
//DP with bitmask
//time: O(k*(2^n)*(2^n)) => O(k*(4^n))
class Solution {
private:
    int limit;
    int dp[8][256];
    
public:
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        limit = (1 << n) - 1;
        return helper(cookies,k,0,0);
    }
private:
    int helper(vi& cookies, int k, int i, int mask) {
        if (i == k-1) return maskSum(cookies,limit-mask);
        if (dp[i][mask]>0) return dp[i][mask];
        
        dp[i][mask] = INT_MAX;
        for (int curMask=1; curMask<limit; curMask++) {
            if ((curMask&mask) == 0 && __builtin_popcount(limit-(mask|curMask)) >= k-i-1) {
                dp[i][mask] = min(dp[i][mask],
                                max(helper(cookies,k,i+1,mask|curMask),
                                     maskSum(cookies,curMask)
                                    )
                                );                
            }
        }
        return dp[i][mask];
    }
    
    
    int maskSum(vi& cookies, int mask) {
        int n = cookies.size();
        int sum = 0;
        for (int i=0; i<n; i++) {
            if ((1<<i)& mask) sum += cookies[i];
        }
        return sum;
    }
};

//solution 2
//same as above but bottom-up

//solution 3
//DP with bitmask, and submask
//time: O(k*(3^n)) 
class Solution {
public:   
    int distributeCookies(vector<int>& cookies, int k) {
        int n = cookies.size();
        int limit = 1 << n;
        int sum[limit], i=0;
        sum[0] = 0;
        for (int m=1; m<limit; m++) {
            int submask = m&(m-1);
            if (submask == 0) sum[m] = cookies[i++];
            else sum[m] = sum[submask] + sum[m-submask];
        }
        
        //int dp[8][256];
        vector<vector<int>> dp(k+1,vector<int>(limit,INT_MAX));
        dp[0][0] = 0;
        for (int i=1; i<=k; i++) {
            //time: O(3^n) = (n,k)*2^k
            for (int m=0; m<limit; m++) {
                for (int subMask=m; subMask; subMask = m&(subMask-1)) {
                    dp[i][m] = min(dp[i][m],max(dp[i-1][m^subMask], sum[subMask]));
                }
                //cout << dp[i][m] << " " << i << " " << m << endl;
            }
        }
        return dp[k][limit-1];
    }
};

//solution 4
//binary search
//time: O(n! * log(sum-max))
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(),cookies.end());
        int low = *max_element(cookies.begin(),cookies.end());
        int high = accumulate(cookies.begin(),cookies.end(),0)+1;
        int ans = INT_MAX;
        do {
            ans = min(ans,bsearch(cookies,low,high,k));
        } while (next_permutation(cookies.begin(),cookies.end()));
        return ans;
    }
    
private:
    int bsearch(vector<int>& cookies, int left, int right, int k) {
        int ans = 0;
        while (left<right) {
            int mid = left + (right-left)/2;
            if (solve(cookies,mid,k)) {
                ans = mid;
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
    
    bool solve(vector<int>& cookies, int mid, int k) {
        int sum = 0;
        for (auto val: cookies) {
            if (val>mid) return false;
            sum += val;
            if (sum>mid) {
                k--;
                sum = val;
            }
        }
        k--;
        return k >= 0;
    }
};
