//solution 1
//using a hashset in this case for duplicay
//time: O(n^2) 
//however, given that hash function may collide, the actual time may be longer 
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> hashset;
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            int count = 0;
            string cur = "";
            for (int j=i; j<nums.size(); j++) {
                if (nums[j]%p == 0) count++;
                if (count > k) break;
                cur += (char)(nums[j]+'0');
                if (hashset.find(cur) == hashset.end()) ans++;
                hashset.insert(cur);
            }
        }
        return ans;
    }
};

//solution 1-2
//implementing the rolling hash our self (rabin karp algo)
