class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),[](vector<int>& a, vector<int>& b){
            return a[0] == b[0] ? a[1]>b[1] : a[0]<b[0];
        });
        vector<int> ps;
        for (auto& e: envelopes) {
            auto it = lower_bound(ps.begin(),ps.end(),e[1]);
            if (it == ps.end()) {
                ps.push_back(e[1]);
            } else {
                *it = e[1];   
            }
        }
        return ps.size();
    }
};
