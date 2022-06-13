class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int ans = 0, n = nums.size();
        for (int i=0; i<n; i++) {
            ans += i*nums[i];
        }
        
        int cur = ans;
        for (int k=n-1; k>0; k--) {
            cur += sum - n*nums[k];
            ans = max(ans,cur);
        }
        
        return ans;
    }
};
