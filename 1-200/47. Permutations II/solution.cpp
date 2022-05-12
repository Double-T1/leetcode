class Solution {
private:
    int n;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> sub;
        vector<pair<int,int>> freq;
        sort(nums.begin(),nums.end());
        for (int i=0; i<nums.size(); i++) {
            if (i>0 && nums[i] == nums[i-1]) freq.back().second++;
            else freq.emplace_back(nums[i],1);
        }
        helper(freq,ans,sub);
        return ans;
    }
    
private:
    void helper(vector<pair<int,int>>& freq, vector<vector<int>>& ans, vector<int>& sub) {
        if (sub.size() == n) {
            ans.push_back(sub);
        } else {
            for (auto& pr : freq) {
                if (pr.second == 0) continue;
                sub.push_back(pr.first);
                pr.second--;
                helper(freq,ans,sub);
                sub.pop_back();
                pr.second++;
            }
        }
    }
};

//solution 2
//another way with same complexity
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        sort(nums.begin(),nums.end());
        helper(nums,ans,sub);
        return ans;
    }
    
private:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& sub) {
        
        if (sub.size() == nums.size()) {
            ans.push_back(sub);
        } else {
            for (int i=0; i<nums.size(); i++) {
                if (nums[i] == -11 || (i>0 && nums[i] == nums[i-1])) continue;
                sub.push_back(nums[i]);
                nums[i] = -11;
                helper(nums,ans,sub);
                nums[i] = sub.back();
                sub.pop_back();
            }
        }
    }
};
