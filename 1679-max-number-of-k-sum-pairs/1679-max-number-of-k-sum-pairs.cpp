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

/*
find how many pairs sum up to k


*/