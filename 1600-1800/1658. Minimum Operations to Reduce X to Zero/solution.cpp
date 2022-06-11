class Solution {
public:
    int minOperations(vector<int>& prefixSum, int x) {
        int n = prefixSum.size();
        for (int i=1; i<n; i++) {
            prefixSum[i] += prefixSum[i-1]; 
        }
        
        int ans = findMatch(prefixSum,x,0);
        for (int i=n-1; i>0 && n-i<ans ; i--) {
            int target = x - (prefixSum.back()-prefixSum[i-1]);
            ans = min(ans,findMatch(prefixSum,target,n-i));
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
    
private:
    int findMatch(vector<int>& vec, int target, int j) {
        if (target == 0) return j;
        int n = vec.size();
        int i = lower_bound(vec.begin(),vec.end()-j,target)-vec.begin();
        return i!= n-j && vec[i] == target ? i+1+j : INT_MAX;
    }
};
