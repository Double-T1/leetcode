//solution 1 using long double
//best to avoid floating arithmetic unless necessary
class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        if (s.size() == 1) return 0;
        sort(s.begin(),s.end(),[](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });
        
        int ans = 1;
        long double cg = getGra(s[0],s[1]); 
        for (auto i=2; i<s.size(); i++) {
            long double ng = getGra(s[i-1],s[i]);
            // cout << cg << " " << ng << endl;
            if (ng != cg) {
                ans++;
                cg = ng;
            } 
        }
        return ans;
    }
    
private:
    long double getGra(vector<int>& a, vector<int>& b) {
        return (long double)(b[1]-a[1])/(long double)(b[0]-a[0]);
    }
};

//solution 2
class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        if (s.size() == 1) return 0;
        sort(s.begin(),s.end(),[](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });
        
        int ans = 1;
        for (auto i=2; i<s.size(); i++) {
            long long dx1 = s[i-1][0]-s[i-2][0], dx2 = s[i][0]-s[i-1][0];
            long long dy1 = s[i-1][1]-s[i-2][1], dy2 = s[i][1]-s[i-1][1];
            if (dx1*dy2 != dx2*dy1) ans++;
        }
        return ans;
    }
};

//solution 3
//using greatest common divisor
class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        if (s.size() == 1) return 0;
        sort(s.begin(),s.end(),[](vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        });
        
        int ans = 0, dx = INT_MIN, dy = INT_MIN;
        for (auto i=1; i<s.size(); i++) {
            int dx2 = s[i][0]-s[i-1][0], dy2 = s[i][1]-s[i-1][1], d = gcd(dx2,dy2);
            ans += dx != dx2/d || dy != dy2/d;
            dx = dx2/d;
            dy = dy2/d;
        }
        return ans;
    }
};
