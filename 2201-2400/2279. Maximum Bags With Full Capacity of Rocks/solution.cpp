class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int a) {
        int ans = 0;
        vector<int> remains;
        for (auto i=0; i<capacity.size(); i++) {
            int x = capacity[i]-rocks[i];
            if (x>0) remains.push_back(x);
            else ans++;
        }
        
        sort(remains.begin(),remains.end());
        for (auto val: remains) {
            if (a<val) break;
            a -= val;
            ans++;
        }
        return ans;
    }
};
