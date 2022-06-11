class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int seen[101] = {0};
        int ans = 0;
        for (auto val: nums) {
            ans += seen[val];
            seen[val]++;
        }
        return ans;
    }
};
