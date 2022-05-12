//backtracking: O(n*2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        for (int size=0; size<=nums.size(); size++) {
            helper(nums,ans,sub,0,size);
        }
        return ans; 
    }
private:
    void helper(vector<int>& nums, vector<vector<int>>& ans, vector<int>& sub,int i,int size) {
        if (size == 0) {
            ans.push_back(sub);
        } else {
            for (int k=i; k<nums.size()-size+1; k++) {
                sub.push_back(nums[k]);
                helper(nums,ans,sub,k+1,size-1);
                sub.pop_back();
            }
        }
    }
};

//iterative 
//building the subsets by adding one number at a time
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>());
        for (auto val: nums) {
            int size = ans.size();
            for (;size; size--) {
                ans.push_back(ans[size-1]);
                ans.back().push_back(val);
            }
        }
        return ans;
    }
};

//bitset
//since every element either join or not
//just try out the 2^n possibilities
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), p = 1 << n;
        vector<vector<int>> ans(p);
        for (int i=0; i<p; i++) {
            for (int j=0; j<n; j++) {
                if ((i >> j) & 1) {
                    ans[i].push_back(nums[j]);
                }
            }
        }
        return ans;
    }
};
