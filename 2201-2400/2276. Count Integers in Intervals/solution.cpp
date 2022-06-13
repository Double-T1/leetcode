class CountIntervals {
private:
    map<int,int> intervals; //[right:left] 
    int sum = 0;
    
public:
    CountIntervals() {
    }
    
    void add(int left, int right) {
        auto end = intervals.end(), begin = intervals.begin();
        int newLeft = left, newRight = right;
        
        auto itLeft = intervals.lower_bound(left);
        if (itLeft != end) {
            newLeft = min(left,itLeft->second);
        }
        
        for (auto it = itLeft; it != end && it->second <= right; intervals.erase(it++)) {
            sum -= it->first - it->second + 1;
            newRight = max(right,it->first);
        }
        
        sum += newRight-newLeft+1;
        intervals[newRight] = newLeft;
    }
    
    int count() {
        return sum;
    }
};
