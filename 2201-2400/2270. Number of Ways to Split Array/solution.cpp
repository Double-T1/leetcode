class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> pre(nums.size());
        pre[0] = (long long)nums[0];
        for (int i=1; i<nums.size(); i++) {
            pre[i] = (long long)nums[i];
            pre[i] += pre[i-1];
        }
            
        
        int ans = 0;
        long long end = pre.back();
        for (int i=0; i<nums.size()-1; i++) {
            if (pre[i]>=end-pre[i]) ans++;
        }
        return ans;
    }
};
