class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {        
        int dx = c[1][0]-c[0][0], dy = c[1][1]-c[0][1], d = gcd(dx,dy);
        dx/=d, dy/=d;
        int n = c.size();
        for (int i=2; i<n; i++) {
            int dx2 = c[i][0]-c[i-1][0], dy2 = c[i][1] - c[i-1][1], d2 = gcd(dx2,dy2);
            dx2 /= d2, dy2 /= d2;
            if (dx2 != dx || dy2 != dy) return false;
        }
        return true;
    }
    
private:    
    int gcd(int a, int b) {
        return b== 0 ? a : gcd(b, a%b);
    }
};
