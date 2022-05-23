//solution 1
//time: O(n^2 * logn * logm)
//solution 2 is better
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

//solution 2
//time: O(n^2)
//for hashing multiple values, we could either string as one string, or provide a hash function
class Solution {
public:
    struct Comp {
        size_t operator() (const pair<int,int>& p) const {
            return p.first ^ p.second * 3;
        }
    };
    
    int maxPoints(vector<vector<int>>& points) {
        int s = points.size(), ans = 1;
        for (int i=0; i<s-1; i++) {
            int x = points[i][0], y = points[i][1];
            unordered_map<pair<int,int>,int, Comp> hashmap;
            for (int j=i+1; j<s; j++) {
                int dx = points[j][0]-x, dy = points[j][1]-y, d = gcd(dx,dy);
                int dxd = abs(dx/d), dyd = abs(dy/d);
                if (dx*dy<0) dxd *= -1; //dx*dy <2^31
                hashmap[make_pair(dxd,dyd)]++;
            }
            
            for (auto& line : hashmap) {
                ans = max(ans,line.second+1);
            }
        }
        return ans;
    }
};
