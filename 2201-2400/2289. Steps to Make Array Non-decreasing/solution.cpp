class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<int> st;
        int ans = 0, n = nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        for (int i=n-1; i>=0; i--) {
            while (!st.empty() && nums[st.top()]<nums[i]) {
                int x = st.top(); st.pop();
                dp[i] = max(dp[x],dp[i]+1);
            }
            ans = max(dp[i],ans);
            st.push(i);
        }
        return ans;
    }
};
