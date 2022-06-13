constexpr int mod = 1e9 + 7;

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        sort(packages.begin(),packages.end());
        long total = accumulate(packages.begin(),packages.end(),0L);
        long ans = LONG_MAX;
        for (auto& each: boxes) {
            sort(each.begin(), each.end());
            if (each.back()<packages.back()) continue;
            long boxSizes = 0;
            for (int i=0, j=0; j<each.size() && i<packages.size(); j++) {
                long x = upper_bound(packages.begin()+i,packages.end(),each[j]) - packages.begin();
                boxSizes += ((x-i)*each[j]);
                i = x;
            }
            ans = min(ans, boxSizes-total);
        }
        return ans == LONG_MAX ? -1 : ans%mod;
    }
};
