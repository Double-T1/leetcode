class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0, n = nums.size()-1;
        for (int i=0; i<=n && i<=maxReach; i++) {
            maxReach = max(maxReach,nums[i]+i);
            if (maxReach>=n) return true;
        }
        return false;
    }
};
