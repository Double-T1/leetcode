class Solution {
private:
    int n;
    
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        queue<int> qu;
        qu.push(1);
        int l = 0;
        bitset<401> visited;
        visited[1] = 1;
        while (!qu.empty()) {
            int size = qu.size();
            l++;
            while (size--) {
                int row, col, cur = qu.front(); qu.pop();
                bool hasPrev = false;
                for (int x=cur+6; x>cur; x--) {
                    int next = x;
                    if (next>=n*n) return l;
                    
                    getCoordinate(row,col,next);
                    if (board[row][col]>-1) {
                        next = board[row][col];
                        if (next == n*n) return l;
                    } else if (hasPrev) continue;
                    else hasPrev = true;
                    
                    if (visited[next] == 0) {
                        qu.push(next);
                        visited[next] = 1;
                    }
                }
            }
        }
        return -1;
    }
    
private:
    void getCoordinate(int& row, int& col, int val) {
        row = n-1-(val-1)/n;
        col = (val-1)%n;
        if ((val-1)/n%2) col = (n-1)-col;
    }
};
