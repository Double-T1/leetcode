class Solution {    
private:
    int adjRow[9] = {0,0,0,1,1,1,-1,-1,-1};
    int adjCol[9] = {1,0,-1,1,0,-1,1,0,-1};
    
public:    
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        int m = 2*n-1;
        long n_ = n;
        unordered_map<int, int> row, col, leftUp, rightUp;
        unordered_map<long, bool> grid;
        
        for (auto& l : lamps) {
            int i= l[0], j = l[1];
            if (grid[i*n_+j]) continue;
            grid[i*n_+j] = true;
            row[i]++;
            col[j]++;
            leftUp[i-j+n-1]++;
            rightUp[i+j]++;
        }
        
        vector<int> ans(queries.size(),0);
        for (int k = 0; k<queries.size(); k++) {
            int i = queries[k][0], j = queries[k][1];
            ans[k] = (row[i]>0 || col[j]>0 || leftUp[i-j+n-1]>0 || rightUp[i+j]>0) ;
            
            for (int p=0; p<9; p++) {
                int i_ = i+adjRow[p], j_ = j+adjCol[p];
                if (i_<0 || j_<0 || i_>=n || j_>=n || !grid[i_*n_+j_]) continue;
                grid[i_*n_+j_] = false;
                row[i_]--;
                col[j_]--;
                leftUp[i_-j_+n-1]--;
                rightUp[i_+j_]--;
            }
        }
        
        return ans;
    }
};
