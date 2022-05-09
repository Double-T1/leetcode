//solution 1
//tree set
//slow but passed
//time: O(n) for seat, O(logn) for delete
class ExamRoom {
private:
    set<int> treeset;
    int last;
    
public:
    ExamRoom(int n): last(n-1) {
    }
    
    int seat() {
        if (treeset.empty()) {
            treeset.insert(0);
            return 0;
        } 
        
        int prev = -1, ans = 0, dist = *treeset.begin();
        for (auto taken : treeset) {
            if (prev>-1) {
                int x = (taken-prev)/2;  
                if (x > dist) {
                    dist = x;
                    ans = x + prev;
                }
            }  
            prev = taken;
        }
        
        if (last-*treeset.rbegin() > dist) ans = last;
        treeset.insert(ans);
        return ans;
    }
    
    void leave(int p) {
        treeset.erase(p);
    }
};

//solution 2
//const O(1), seat O(logn), leave O(logn)
public:
    ExamRoom(int n) {
        IntV:: N = n;
        treeset.clear(); l2r.clear(); r2l.clear();
        treeset.emplace(0,n-1);
        l2r[0] = n-1;
        r2l[n-1] = 0;
    }
    
    int seat() {
        auto cur = *treeset.begin();
        treeset.erase(treeset.begin());
        
        int p = cur.getP();
        treeset.emplace(cur.l,p-1);
        treeset.emplace(p+1,cur.r);
        
        l2r.erase(p); r2l.erase(p);
        l2r[cur.l] = p-1; r2l[p-1] = cur.l;
        l2r[p+1] = cur.r; r2l[cur.r] = p+1;
        

        return p;
    }
    
    void leave(int p) {
        int l = r2l[p-1], r = l2r[p+1];
        treeset.erase(IntV(p+1,r));
        treeset.erase(IntV(l,p-1));
        treeset.emplace(l,r);
        
        l2r[l] = r; r2l[r] = l;
        l2r.erase(p+1); r2l.erase(p-1);
    }
};
