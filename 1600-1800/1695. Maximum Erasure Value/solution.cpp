class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, n = nums.size();
        unordered_set<int> prevExist;
        for (int left=0, right=0, cur=0; right<n; right++) {
            while (prevExist.find(nums[right]) != prevExist.end()) {
                cur -= nums[left];
                prevExist.erase(nums[left++]);
            } 
            prevExist.insert(nums[right]);
            cur += nums[right];
            ans = max(ans,cur);
        }
        return ans;
    }
};
