class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> sub;
        vector<vector<int>> ans;
        backtrack(ans,k,n,1,sub);
        return ans;
    }
private:
    void backtrack(vector<vector<int>>& ans, int k, int n, int i, vector<int>& sub) {
        if (n == 0 && k == 0) {
            ans.push_back(sub);
        } else if (n == 0 || k == 0) {
            return;
        }
        
        for (int j=i; j<=9 && j<=n; j++) {
            sub.push_back(j);
            backtrack(ans,k-1,n-j,j+1,sub);
            sub.pop_back();
        }
    }
};
