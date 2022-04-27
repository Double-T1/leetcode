class Solution {
public:
    int totalNQueens(int n) {
        vector<int> c(n,0);
        vector<int> lu(2*n-1,0);
        vector<int> ru(2*n-1,0);
        return count(n,0,c,lu,ru);
    }
    
private:
    int count(int n, int row, vector<int>& c, vector<int>& lu, vector<int>& ru) {
        if (row == n) return 1;
        
        int ans = 0;
        for (int col=0; col<n; col++) {
            if (c[col] || lu[col-row+n-1] || ru[col+row]) continue;
            c[col] = 1; lu[col-row+n-1] = 1; ru[col+row] = 1;
            ans += count(n,row+1,c,lu,ru);
            c[col] = 0; lu[col-row+n-1] = 0; ru[col+row] = 0;
        }
        return ans;
    } 
};
