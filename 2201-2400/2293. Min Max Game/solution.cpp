class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        vector<int> newNums;
        int n = static_cast<int>(nums.size()), k = 0;
        while (n>1) {
            k = 0;
            for (int i=0; i<n; i += 2) {
                newNums.push_back(eval(k,nums[i],nums[i+1]));
                k ^= 1;
            }
            swap(nums,newNums);
            newNums.clear();
            n = nums.size();
        }
        
        return nums[0];
    }
private:
    int eval(int k, int a, int b) {
        return k == 0 ? min(a,b) : max(a,b);
    }
};
