class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i1 = m-1, i2 = n-1, i3 = m+n-1;
        while (i1 > -1 || i2 > -1) {
            if (i1 == -1 || nums1[i1]<nums2[i2]) {
                nums1[i3] = nums2[i2--];
            } else {
                nums1[i3] = nums1[i1--];
            }
            i3--;
        }
    }
};
