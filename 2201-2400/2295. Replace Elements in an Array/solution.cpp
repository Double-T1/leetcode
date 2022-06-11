class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> hashmap; //value: index
        for (int i=0; i<nums.size(); i++) {
            hashmap[nums[i]] = i;
        }
        
        for (auto& op: operations) {
            int prev = op[0], cur = op[1];
            nums[hashmap[prev]] = cur;
            hashmap[cur] = hashmap[prev];
            hashmap.erase(prev);
        }
        
        return nums;
    }
};
