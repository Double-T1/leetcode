class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1,-1};
        auto b = nums.begin(), e = nums.end();
        int lower = lower_bound(b,e,target) - b;
        int upper = upper_bound(b,e,target) - b;
        return lower == upper ? vector<int>({-1,-1}) 
            : vector<int>({lower,upper-1});
    }
};

/*
if mid == target => could go left and right

1. find the smallest element that is equal to or greater than target
2. find the smallest element that is greater than target




*/
