class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size()-1, mid;
        while (left<right) {
            mid = left + (right-left)/2;
            if (mid<nums.size()-1 && nums[mid] == nums[mid+1]) {
                if (mid%2) right = mid-1;
                else left = mid+2;
            } else if (mid>0 && nums[mid] == nums[mid-1]) {
                if ((mid-1)%2) right = mid-2;
                else left = mid+1;
            } else {
                return nums[mid];
            }
        }
        return nums[right];
    }
};

/*
must have in odd eles
slice into two subarrays, the one with even number eles is safe
how to slice

1. find mid
2. find the if its equal to left or equal to right
if none equal=> thats the num

else if m,m+1 => check (l,m-1) or (m+2,r)
check(l,m-2) or (m+1,r)

l>r 


*/
