//solution 1
// n is the length of nums, w is the half of sum
//standard O(n*w)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum%2) return false;
        int target = sum/2;
        vector<bool> dp(target+1,false);
        dp[0] = true;
        
        for (auto val: nums) {
            for (int j=target-1; j>=0; j--) {
                if(j+val<=target) dp[j+val] = dp[j+val] || dp[j];
            }
        }
        return dp.back();
    }
};

//solution 2
//time: O(n*(w/32))
constexpr int x = 100*100 + 1;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum%2) return false;
        bitset<x> dp(1);
        
        for (auto val: nums) {
            dp |= dp << val;
        }
        return dp[sum/2];
    }
};

