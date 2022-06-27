class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> nums2(nums);
        int n = nums.size();
        for (int i=2; i<n; i++) {
            nums[i] += nums[i-2];
        }
        for (int i=n-3; i>=0; i--) {
            nums2[i] += nums2[i+2];
        }
        
        int ans = 0;
        for (int i=0; i<n; i++) {
            int left1 = i>0 ? nums[i-1] : 0;
            int left2 = i>1 ? nums[i-2] : 0;
            int right1 = i<n-1 ? nums2[i+1] : 0;
            int right2 = i<n-2 ? nums2[i+2] : 0;
            ans += left1+right2 == right1+left2;
        }
        return ans;
    }
};

/*
traverse O(n)

at each index i: we need
1. sum of odd indexed left to i
2. sum of even indexed left to i


prefix sum of odd and even

1. nums[i-1] or 0
2. nums[i-2] or 0
3. nums[i+1] or 0 pairs with 2
4. nums[i+2] or 0 pairs with 1

*/
