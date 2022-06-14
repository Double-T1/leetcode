class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int ans = 0;
        int prev = 0;
        for (auto& cur: brackets) {
            int upper = cur[0], per = cur[1];
            ans += (min(upper,income)-prev)*per;
            if (upper>=income) break;
            prev = upper;
        }
        
        return ans/100.0;
    }
};
