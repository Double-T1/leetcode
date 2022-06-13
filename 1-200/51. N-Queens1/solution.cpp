//time: O(n^3)
//space: O(n^2)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string arch = "";
        for (int i=0; i<n; i++) arch += "0";
        vector<string> sub(n,arch);
        helper(ans,sub);
        return ans;
    }
    
private:
    void helper(vector<vector<string>>& ans, vector<string>& sub, int row=0) {
        if (row == sub.size()) {
            ans.push_back(sub);
            render(ans.back());
        } else {
            for (int col=0; col<sub.size(); col++) {
                if (sub[row][col] > '0') continue;
                mark(sub,row,col);
                helper(ans,sub,row+1);
                erase(sub,row,col);
            }
        }
    }
    
    void render(vector<string>& sub) {
        for (int i=0; i<sub.size(); i++) {
            for (int j=0; j<sub[0].size(); j++) {
                if (sub[i][j] != 'Q') sub[i][j] = '.';
            }
        }
    }
    
    void mark(vector<string>& sub,int row, int col) {
        sub[row][col] = 'Q';
        int col1 = col-1, col2 = col+1;
        for (int i=row+1; i<sub.size(); i++) {
            if (col1>=0) sub[i][col1] = (char)(sub[i][col1]+'1'-'0');
            if (col2<sub.size()) sub[i][col2] = (char)(sub[i][col2]+'1'-'0');
            sub[i][col] = (char)(sub[i][col]+'1'-'0');
            col1--,col2++;
        }
    }
    
    void erase(vector<string>& sub, int row, int col) {
        sub[row][col] = '0';
        int col1 = col-1, col2 = col+1;
        for (int i=row+1; i<sub.size(); i++) {
            if (col1>=0) sub[i][col1] = (char)(sub[i][col1]-'1'+'0');
            if (col2<sub.size()) sub[i][col2] = (char)(sub[i][col2]-'1'+'0');
            sub[i][col] = (char)(sub[i][col]-'1'+'0');
            col1--,col2++;
        }
    }
};


//solution 2
//a better time complexity with the compromise of space
//time: O(n^2)
//space: O(n)
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> sub(n,string(n,'.'));
        vector<int> col(n,1);
        vector<int> leftUp(2*n-1,1);
        vector<int> rightUp(2*n-1,1);
        helper(ans,sub,col,leftUp,rightUp);
        return ans;
    }
    
private:
    void helper(vector<vector<string>>& ans, vector<string>& sub, vector<int>& col, vector<int>& leftUp, vector<int>& rightUp, int i=0) {
        if (i == sub.size()) {
            ans.push_back(sub);
        } else {
            for (int j=0; j<sub.size(); j++) {
                if (!isAvai(col,leftUp,rightUp,i,j,sub.size())) continue;
                update(sub,col,leftUp,rightUp,i,j,0);
                helper(ans,sub,col,leftUp,rightUp,i+1);
                update(sub,col,leftUp,rightUp,i,j,1);
            }
        }
    }
    
    bool isAvai(vector<int>& col, vector<int>& leftUp, vector<int>& rightUp, int i, int j,int n) {
        return col[j] && leftUp[(i-j)+n-1] && rightUp[i+j];  
    }
    
    void update(vector<string>& sub, vector<int>& col, vector<int>& leftUp, vector<int>& rightUp, int i, int j, int val) {
        sub[i][j] = val? '.' : 'Q';
        col[j] = val;
        leftUp[(i-j)+(int)sub.size()-1] = val;
        rightUp[i+j] = val;
    }
};


/**
backtracking: 
put one queen at a spot and go on for next
!!! queen attacks diaganolly, horizontally and vertically

we need a way to quickly check whether the row or col is occupied
=> go by row, so only need to check whether the col is occupied
=> at most 9
but how to deal with diaganol attack??
brute force would be to mark all the attack route while we place the queen



*/
