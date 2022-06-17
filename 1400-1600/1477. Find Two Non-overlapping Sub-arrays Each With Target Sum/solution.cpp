class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n,INT_MAX);
        
        int ans = INT_MAX;
        for (int left=0, right=0, sum=0; right<n; right++) {
            sum += arr[right];
            
            while (sum >= target) {
                if (sum == target) {
                    int length = right-left+1;
                    dp[right] = min(dp[right],length);
                    
                    if(left>0 && dp[left-1] != INT_MAX) 
                        ans = min(ans,dp[left-1] + length);
                }
                
                sum -= arr[left++];
            }

            if(right>0) dp[right] = min(dp[right],dp[right-1]);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};


/*
if the current subarray sum >= target => can't expand further

subarrays of subarrays that fits won't exists.

we can find the subarrays with sum == target

we record the smallest length of valid subarrays before left (left being the left index of a subarray, which has a range of [left,right])

record the current length at right
*/
