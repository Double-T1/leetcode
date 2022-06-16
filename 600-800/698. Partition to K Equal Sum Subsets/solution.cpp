class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum%k || nums.size()<k) return false;
        int target = sum/k;
        
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int> subsets(k,0);
        return dfs(0,nums,subsets,target);
    }
    
private:
    bool dfs(int i,vector<int>& nums, vector<int>& subsets,int target){
        if (i == nums.size()) return true;

        unordered_set<int> seen;
        for (int j=0; j<subsets.size(); j++) {
            if (seen.find(subsets[j]) != seen.end()) continue;
            seen.insert(subsets[j]);
            if (nums[i] + subsets[j] <= target) {
                subsets[j] += nums[i];
                if (dfs(i+1,nums,subsets,target)) return true;
                subsets[j] -= nums[i];
            }
            if (subsets[j] == 0) return false;
        }
        return false;
    };
};
