//the offical way
class Solution {
public:
    vector<int> grayCode(int n) {
        int x = 1 << n;
        vector<int> ans(x,0);
        for (int i=0; i<x; i++) {
            ans[i] = i^(i>>1);
        }
        return ans;
    }
};

//backtracking way
//do this if haven't seen gray code algo before
class Solution {
private:
    int x;
    
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        x = pow(2,n);
        bool seen[x];
        memset(seen,0,sizeof(seen));
        for (int i=0; i<x; i++) {
            ans.push_back(i);
            seen[i] = true;
            if (helper(ans,n,seen)) break;
            ans.pop_back();
            seen[i] = false;
        }
        
        return ans;
    }
    
private:
    bool helper(vector<int>& ans, int n, bool seen[]) {
        if (ans.size() == x) {
            int y = ans.front() ^ ans.back();
            if ((y&(y-1)) == 0) return true;
            return false;
        }
        
        for (int i=0; i<n; i++) {
            int bit = 1 << i;
            if ((ans.back()&bit)>0 ) {
                int cur = ans.back() ^ bit;
                if (helper2(seen,cur,ans,n)) return true;
            } else {
                int cur = ans.back() | bit;
                if (helper2(seen,cur,ans,n)) return true;
            }
        }
        return false;
    }
    
    bool helper2(bool seen[], int cur, vector<int>& ans, int n) {
        if (seen[cur]) return false;
        seen[cur] = true;
        ans.push_back(cur);
        if (helper(ans,n,seen)) return true;
        ans.pop_back();
        seen[cur] = false;  
        return false;
    } 
};
