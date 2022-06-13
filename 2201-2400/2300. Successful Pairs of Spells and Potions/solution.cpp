class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size(), m = potions.size();
        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            long long target = success/spells[i];
            if(success%spells[i]) target++;
            int x = lower_bound(potions.begin(),potions.end(),target) - potions.begin(); //the smallest element that is not smaller than target
            ans[i] = m - x;
        }
        return ans;
    }
};
