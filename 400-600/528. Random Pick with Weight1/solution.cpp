class Solution {
private:
    vector<int> ps;
        
public:
    Solution(vector<int>& w) {
        for (int i=0; i<w.size(); i++) {
            ps.push_back(w[i]);
            if (i>0) ps.back() += ps[i-1];
        }
    }
    
    int pickIndex() {
        int t = rand()%ps.back()+1;
        return lower_bound(ps.begin(),ps.end(),t)-ps.begin();
    }
};
