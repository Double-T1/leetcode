class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        auto& a = firstList;
        auto& b = secondList;
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<a.size() && j<b.size()) {
            if (a[i][1]>=b[j][0] && a[i][0]<=b[j][1]) {
                ans.push_back({max(a[i][0],b[j][0]), min(a[i][1],b[j][1])});
            }
            if (a[i][1]>b[j][1]) j++;
            else if (a[i][1]<b[j][1]) i++;
            else i++,j++;
        }
        return ans;
    }
};
