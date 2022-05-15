class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int bitcount[32];
        memset(bitcount,0,sizeof(bitcount));
        for (auto val: candidates) {
            int i=0;
            while(val) {
                bitcount[i++] += val&1;
                val >>= 1;
            }
        }
        
        int ans = 0;
        for (auto val: bitcount) {
            ans = max(ans,val);
        }
        
        return ans;
    }
};

/*
constraint: O(n) or maybe O(nlogn)
hashmap?? 
32*n

to have AND > 0 => at least one bit has to both be 1
idealy, we check all pairs, but we can't

there must be some relation


*/
