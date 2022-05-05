//solution 1 memoization
//time: O(3*n*27*3) => O(n)
class Solution {
private: 
    const int mod = pow(10,9)+7;
    int col[3] = {0,1,2};
    
public:
    int numOfWays(int n) {
        vector<vector<int>> dp(n*3,vector<int>(27,-1));
        return helper(n,0,0,0,dp);
    }
    
private:
    int helper(int n, int i, int j, int state, vector<vector<int>>& dp) {
        if (j == 3) i++, j=0;
        if (i == n) return 1;
        if (dp[i*3+j][state]>-1) return dp[i*3+j][state];
        
        int left = j>0? state%3: -1;
        int up = i>0 ? (state/9)%3 : -1;
        
        int ans = 0;
        for (auto c: col) {
            if (c == left || c == up) continue;
            ans += helper(n,i,j+1,update(state,c),dp);
            ans %= mod;
        }
        
        return dp[i*3+j][state] = ans;
    }
    
    int update(int state, int c) {
        return (state*3)%27 + c;
    }
};

//solution 2
//bottom-up
//same complexity
class Solution {
private: 
    const int mod = pow(10,9)+7;
    int col[3] = {0,1,2};
    
public:
    int numOfWays(int n) {
        vector<vector<int>> dp(n*3,vector<int>(27,0));
        
        for (int i=n-1; i>=0; i--) {
            for (int j=2; j>=0; j--) {
                for (int state=0; state<27; state++) {
                    int left = j>0? state%3: -1;
                    int up = i>0 ? (state/9)%3 : -1;

                    for (auto c: col) {
                        if (c == left || c == up) continue;
                        dp[i*3+j][state] += i==(n-1) && j==2 ? 1 : dp[nextIndex(3*i+j)][update(state,c)]; 
                        dp[i*3+j][state] %= mod;
                    }
                }
            }
        }
        
        
        return dp[0][0];
    }
    
private:
    int update(int state, int c) {
        return (state*3)%27 + c;
    }
    
    int nextIndex(int k) {
        int i = k/3, j = k%3;
        i = j == 2? i+1: i;
        j = (j+1)%3;
        return i*3 + j;
    }
};

//solution 3 hard code all the transitions and their relations
//given that there are only 3 colors, with only 3 columns every line, there aren't much
class Solution {
private:
    long mod = 1e9+7; 
    
public:
    int numOfWays(int n) {
        long a121 = 6, a123 = 6;
        n--;
        while (n) {
            long b121 = ((a121*3)%mod + (a123*2)%mod)%mod;
            long b123 = ((a121*2)%mod + (a123*2)%mod)%mod;
            a121 = b121;
            a123 = b123;
            
            n--;
        }
        return (a121 + a123)%mod;
    }
};

/*
hard code the transistion of states

for rowA: 121 or 123, for either exist 6 permutations, including itself
for rowB: 
if rowA is 121 => 212, 213, 232, 312, 313 5 possbilities => 6*5
=> three 121 and two 123
if rowA is 123 => 212, 231, 232, 312, 4 possibilities => 6*4
=> two 121 and two 123

rowB has 
121B: 121A*3 + 123A*2
123B: 121A*2 + 123A*2


*/

//solution 4 fast matrix multiplication
//applicable to n*n matrix
//time: O(logn)
//space: O(1)
class Solution {
private:
    long mod = 1e9+7; 
    
public:
    int numOfWays(int n) {
        vector<vector<long>> init = {{6},{6}};
        vector<vector<long>> matrix = {{3,2},{2,2}};
        fast(matrix,--n);
        if (n) multiply(matrix,init);

        return (init[0][0]+init[1][0])%mod;
    }
private:
    //update the answer to matrix
    void fast(vector<vector<long>>& matrix, int k) {    
        if (k <= 1) return;
        
        vector<vector<long>> forOdds(matrix.size(), vector<long>(matrix[0].size(),0));
        for (int i=0; i<matrix.size(); i++) forOdds[i][i] = 1;
        while (k>1) {
            if (k%2) multiply(matrix,forOdds);
            multiply(matrix,matrix);
            k /= 2;
        }
        multiply(forOdds,matrix);
    }
    
    //update the answer onto m2
    void multiply(vector<vector<long>>& m1, vector<vector<long>>& m2) {
        vector<vector<long>> dup(m2.size(), vector<long>(m2[0].size()));
        for (int i=0; i<m2.size(); i++) {
            for (int j=0; j<m2[0].size(); j++) {
                dup[i][j] = 0;
                for (int m=0; m<m2.size(); m++) dup[i][j] += (m1[i][m]*m2[m][j])%mod;
                dup[i][j] %= mod;
            }
        }
        m2 = dup;
    }
};


