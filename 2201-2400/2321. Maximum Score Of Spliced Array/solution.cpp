class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> diff(n);
        for (int i=0; i<n; i++) {
            diff[i] = nums1[i] - nums2[i];
        }
        
        return max(maxSwap(diff,nums2,nums1),maxSwap(diff,nums1,nums2));
    }
    
private:
    int maxSwap(vector<int>& diff, vector<int>& target, vector<int>& original) {
        int curMax = 0, totalMax = INT_MIN, n = diff.size();
        int curLeft =-1, totalLeft = -1, totalRight = -1;
        for (int i=0; i<n; i++) {
            if (curMax+diff[i]<=diff[i]) {
                curMax = diff[i];
                curLeft = i;
            } else {
                curMax += diff[i];
            }
            
            if (curMax>totalMax) {
                totalLeft = curLeft;
                totalRight = i;
                totalMax = curMax;
            }
            diff[i] *= -1;
        }
        
        int ans = 0;
        for (int i=0; i<totalLeft; i++) ans += target[i];
        for (int i=totalLeft; i<=totalRight; i++) ans += original[i];
        for (int i=totalRight+1; i<n; i++) ans += target[i];
        return ans; 
    }
};

/*
brute force:
try all swaps => all subarrays => O(n^2)
we need O(n) or O(nlogn)

find the subarray pair with the largest diff

1. subtract the two arrays
2. find the maximum abs subarray sum of this new array
3. nums1 - nums2 => the larger meaning that subarray has to be converted to nums2
4. have a left right pointer that records the subarray
5. find of the sum of the rest and compare max and min


*/
