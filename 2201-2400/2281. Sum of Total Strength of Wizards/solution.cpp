constexpr int mod = 1e9+7;

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        int ps[n], pps[n];
        ps[0] = pps[0] = strength[0];
        for (int i=1; i<n; i++) {
            ps[i] = strength[i];
            ps[i] += ps[i-1];
            ps[i] %= mod;
            
            pps[i] = ps[i];
            pps[i] += pps[i-1];
            pps[i] %= mod;
        }
        
        int ans = 0;
        stack<int> st; //index
        for (int i=0; i<n; i++) {
            int val = strength[i];
            while(!st.empty() && strength[st.top()]>=val) {
                ans += calc(st,i,pps,strength);
                ans %= mod;
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            ans += calc(st,n,pps,strength);
            ans %= mod;
        }
        
        return ans;
    }
    
private:
    int calc(stack<int>& st, int r,int pps[],vector<int>& strength) {
        long long j = st.top(); st.pop();
        int l = st.empty() ? -1 : st.top();
        long long pos = (j-l)*((findSum(pps,r-1)-findSum(pps,j-1)+mod)%mod)%mod;
        long long neg = (r-j)*((findSum(pps,j-1)-findSum(pps,l-1)+mod)%mod)%mod;
        return strength[j]*((pos-neg+mod)%mod)%mod;
    }
    
    int findSum(int pps[], int x) {
        if (x<0) return 0;
        return pps[x];
    }
};
