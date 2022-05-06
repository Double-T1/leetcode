class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre, post;
        int product = 1;
        for (int num: nums) {
            product *= num;
            pre.push_back(product);
        }
        product = 1;
        for (int i=nums.size()-1; i>=0; i--) {
            product *= nums[i];
            post.push_back(product);
        }
        reverse(post.begin(),post.end());
        
        vector<int>ans{post[1]};
        for (int i=1; i<nums.size()-1; i++) {
            ans.push_back(pre[i-1]*post[i+1]);
        }
        ans.push_back(pre[nums.size()-2]);
        return ans;
    }
};

//O(n) time with O(1) space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);
        for (int i=0, pre=1, post=1, j=nums.size()-1; j>=0; i++,j--) {
            ans[i] *= pre;
            pre *= nums[i];
            ans[j] *= post;
            post *= nums[j];
        }
        return ans;
    }
};
