class Solution {    
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> prevPoints;
        long agArea = 0;
        int x1 = INT_MAX, x2 = INT_MIN, y1 = INT_MAX, y2 = INT_MIN;
        for (auto& rec: rectangles) {
            checkExist(prevPoints,rec[0],rec[1]);
            checkExist(prevPoints,rec[2],rec[3]);
            checkExist(prevPoints,rec[0],rec[3]);
            checkExist(prevPoints,rec[2],rec[1]);
            
            agArea += ((long)rec[3]-rec[1])*(rec[2]-rec[0]);
            
            x1 = min(x1,min(rec[0],rec[2]));
            x2 = max(x2,max(rec[0],rec[2]));
            y1 = min(y1,min(rec[1],rec[3]));
            y2 = max(y2,max(rec[1],rec[3]));
        }
        long area = ((long)x2-x1)*(y2-y1);
        return area == agArea 
            && prevPoints.count(getKey(x1,y1)) 
            && prevPoints.count(getKey(x1,y2))
            && prevPoints.count(getKey(x2,y1))
            && prevPoints.count(getKey(x2,y2))
            && prevPoints.size() == 4;
    }
private:
    void checkExist(unordered_set<string>& st, int a, int b) {
        string key = getKey(a,b);
        if (st.count(key)) st.erase(key);
        else st.insert(key);
    }
    
    string getKey(int a,int b) {
        return to_string(a) + "_" + to_string(b);
    }
};
