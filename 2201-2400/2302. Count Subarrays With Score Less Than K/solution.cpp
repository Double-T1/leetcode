class Solution {
public:
    long long countSubarrays(vector<int>& nums2, long long k) {
        long long ans = 0;
        int n = nums2.size();
        vector<long long> nums(n);
        nums[0] = nums2[0];
        for (int i=1; i<n; i++) {
            nums[i] = static_cast<long long>(nums2[i]);
            nums[i] += nums[i-1];
        }
        
        for (int left=0, right=0; right<n; right++) {
            long long length = right-left+1;
            long long score = left>0 ? (nums[right]-nums[left-1])*length : nums[right]*length;
            while (left<=right && score>=k) { 
                ++left;
                length = right-left+1;
                score = (nums[right]-nums[left-1])*length;
            }
            length = right-left+1;
            ans += length;
        }
        
        return ans;
    }
};

/*
if subarray x has a score larger than or equal to k, than all of its superArray are invalid
vice versa
if subarray x has a score smaller than equal to k, all of its subarray are valid


*/
