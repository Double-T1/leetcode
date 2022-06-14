class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),[](vector<int>& a, vector<int>& b){
            return a[0]-a[1] < b[0]-b[1];
        });
        
        int ans = 0;
        int n = costs.size()/2;
        for (int i=0; i<n; i++) ans += costs[i][0];
        for (int i=n; i<2*n; i++) ans += costs[i][1];
        
        return ans;
    }
};

//quickselect 
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        nth_element(costs.begin(),costs.begin()+n,costs.end(),[](vector<int>& a, vector<int>& b){
            return a[0]-a[1] < b[0]-b[1];
        });
        
        int ans = 0;
        for (int i=0; i<n; i++) ans += costs[i][0];
        for (int i=n; i<2*n; i++) ans += costs[i][1];
        
        return ans;
    }
};
