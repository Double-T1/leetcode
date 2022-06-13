bool comp (int p, int q) {
    return p>q;
}


class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end(),comp);
        int mod = pow(10,9) + 7;
        for (int i=0; i<k; i++) {
            int smallest = nums[0];
            pop_heap(nums.begin(),nums.end(),comp);
            nums.pop_back();
            
            smallest++;
            smallest %= mod;
            nums.push_back(smallest);
            push_heap(nums.begin(),nums.end(),comp);
        }
        
        long long p = 1;
        for (int num : nums) {
            p *= (long long) num;
            p %= mod;
        }
        return (int)p;
    }
};
