class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](vector<int>& a, vector<int>& b){
            return a[0] == b[0] ? a[1]<b[1] : a[0]<b[0];
        });
        
        int n = points.size(), ans = 1;
        map<tuple<int,int,int,int>,int> hashmap;
        set<tuple<int,int,int,int>> seen;
        for (int i=1; i<n; i++) {
            int x = points[i][0], y = points[i][1];
            seen.clear();
            for (int j=i-1; j>=0; j--) {
                int dx = x - points[j][0], dy = y - points[j][1], d = gcd(dx,dy);
                dx /= d, dy /= d;
                int cn = dx*y-dy*x, cd = dx, dd = gcd(cn,cd);
                if (dx == 0) {
                    cn = x, cd = INT_MAX;
                } else if (dd > 0) {
                    cn /= dd, cd /= dd;   
                }
                auto t = make_tuple(dx,dy,cn,cd);
                if (seen.find(t) == seen.end()) {
                    hashmap[t]++;
                    ans = max(ans,hashmap[t]+1);
                    seen.emplace(dx,dy,cn,cd);
                }
            }
        }
        return ans;
    }
};
