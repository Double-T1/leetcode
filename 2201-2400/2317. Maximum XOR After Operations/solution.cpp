class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for (auto val: nums) {
            ans |= val;
        }
        return ans;
    }
};

/*
goal: find the max XOR of all elements
for one bit, if it occurs odd times, it will eventually stay 

[0,1]

k&(k^x), x is arbitrary => find submask of k (a number smaller than k)
=> deleting 1s arbitrarily

to maximize, we need odd numbers of 1s at a bit

every bit that has 1s can be considered to have one

and: 1&1 => 1 all else 0
*/
