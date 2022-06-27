class Solution {
private:
    int all;
    
public:
    string shortestSuperstring(vector<string>& words) {
        int n = words.size(), limit = 1 << n;
        int adj[n][n];
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                adj[i][j] = match(words[i],words[j]);
                adj[j][i] = match(words[j],words[i]);
                //cout << adj[i][j] << " " << adj[j][i] << endl;
            }
        }
        
        vector<vector<int>> dp(limit,vector<int>(n));
        vector<vector<int>> path(dp);
        int end = -1, totalLength= INT_MAX;
        
        for (int mask=1; mask<limit; mask++) {
            for (int last=0; last<n; last++) {
                dp[mask][last] = INT_MAX;
                int bit = 1 << last;
                if ((mask&bit) == 0) continue;
                int prevMask = mask^bit;
                if (prevMask == 0) dp[mask][last] = words[last].size();
                else for (int j=0; j<n; j++) {
                    if ((prevMask&(1<<j)) 
                        && dp[prevMask][j] + adj[j][last] < dp[mask][last]) {
                        dp[mask][last] = dp[prevMask][j] + adj[j][last];
                        path[mask][last] = j;
                    }
                }
                
                if (mask == limit-1 && totalLength>dp[mask][last]) {
                    totalLength = dp[mask][last];
                    end = last;
                }
            }
        }
        
        //build the path
        stack<int> st;
        int state = limit-1;
        while (state) {
            //cout << end << endl;
            st.push(end);
            int temp = state;
            state = state^(1<<end);
            end = path[temp][end];
        }
        
        //build the string
        int prev = st.top(); st.pop();
        string ans = words[prev];
        while(!st.empty()) {
            int cur = st.top();
            ans += words[cur].substr(words[cur].size()-adj[prev][cur],adj[prev][cur]);
            st.pop();
            prev = cur;
        }
        return ans;
    }
    
private:   
    //return the index of pre where pre has its prefix matching suf's suffix
    int match(string& suf, string& pre) {
        int n = suf.size(), m = pre.size(), ans = m;
        for (int i=n-1; i>=0 && (n-i)<=m; i--) {
            string sub = suf.substr(i);
            if (pre.find(sub) == 0) ans = m-(n-i);
        }
        return ans;
    }
    
};

/*
words may overlap one another => may have more than one way to build an overlapping string
e.g [aabb,bbaa,cbb]
DP??

two words can concatenate if its prefix matches others suffix, or vice versas
if a's suffix matches b's prefix, consider an a to b edge, the weight would be the overlapping length
=> a graph with possible negative cycle

brute force: O(12!) => TLE

x(mask,i): the shortest length of superstring containing mask with i being the last one
x(mask|(1<<j),j) = min(x(mask,i) + overlap(i,j)| for all i in mask)  
goal: x(all,)

path[mask][i] => the path from i to its parent with mask, i included in mask

maximum spanning tree??
*/
