class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left = 0, right = nums.size()-1, count =0;
        while (left<right) {
            int sum = nums[left] + nums[right];
            if (sum == k) {
                left++,right--;
                count++;
            } else if (sum > k) {
                right--;
            } else {
                left++;
            }
        }
        return count;
    }
};

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> hashmap;
        int count = 0;
        for (int val: nums) {
            if (hashmap[k-val]) {
                hashmap[k-val]--;
                count++;
            } else hashmap[val]++;
        }
        return count;
    }
};
