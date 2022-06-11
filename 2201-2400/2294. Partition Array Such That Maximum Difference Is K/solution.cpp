class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 0, prev = INT_MIN;
        for (auto val: nums) {
            if (val <= prev) continue;
            ans++;
            prev = val+k;
        }
        return ans;
    }
};
