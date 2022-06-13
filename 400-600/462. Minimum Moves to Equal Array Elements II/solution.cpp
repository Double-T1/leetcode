class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long ans = 0;
        int n = nums.size(), base = nums[n/2];
        for (int i=0; i<n; i++) {
            ans += abs(nums[i] - base);
        }
        
        // long long sum = ans;
        // for (int i=1; i<n; i++) {
        //     if (nums[i] == nums[i-1]) continue;
        //     long long diff = nums[i] - nums[i-1];
        //     sum += diff*(2*i-n);
        //     ans = min(ans,sum);
        // }
        
        return ans;
    }
};
