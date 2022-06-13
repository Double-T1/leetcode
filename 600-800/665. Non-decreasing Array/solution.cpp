class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool oneFalse = false;
        int n = nums.size();
        for (int i=0; i<n-1; i++) {
            if (nums[i]<=nums[i+1]) continue;
            if (oneFalse) return false;
            
            oneFalse = true;
            if (i == 0 || nums[i-1]<=nums[i+1]) nums[i] = nums[i+1];
            else nums[i+1] = nums[i];
        }
        return true;
    }
};
