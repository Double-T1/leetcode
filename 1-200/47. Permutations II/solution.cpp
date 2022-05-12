//solution 1
//time: O(n!)
//space: O(n+m)
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
//time: O(n^n)
//space: O(n)
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

//solution 3
//a minor optimization based on solution 1
//the complexity is still the same, yet it runs faster in reality since we don't need to sort in this case
class Solution {
private:
    int n;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> sub;
        unordered_map<int,int> hashmap; //num to index
        vector<pair<int,int>> freq;
        for (auto val : nums) {
            if (hashmap.count(val)) {
                freq[hashmap[val]].second++;
            } else {
                hashmap[val] = freq.size();
                freq.emplace_back(val,1);
            }
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
                pr.second++;
                sub.pop_back();
            }
        }
    }
};

//solution 4
//swapping
//same complexity but much faster in runtime
//the key is to make sure used num is not reused
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        helper(nums,ans,0);
        return ans;
    }
    
private:
    void helper(vector<int>& nums, vector<vector<int>>& ans, int i) {
        if (i == nums.size()-1) {
            ans.push_back(nums);
        } else {
            for (int k=i; k<nums.size(); k++) {
                if (k>i && nums[i] == nums[k]) continue;
                swap(nums[i],nums[k]);
                helper(nums,ans,i+1);
            }
            
            for (int j = nums.size()-1; j>i; j--) {
                swap(nums[i],nums[j]);
            }
        }
    }
};
