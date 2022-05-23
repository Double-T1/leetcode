class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        vector<int> ans = {INT_MIN,INT_MIN};
        vector<int> sub;
        backtrack(ans,sub,arr);
        if (ans[0] == INT_MIN) return "";
        string s = ans[0]>9? to_string(ans[0]) : '0' + to_string(ans[0]);
        s += ':';
        s += ans[1]>9? to_string(ans[1]) : '0' + to_string(ans[1]);
        return s;
    }
    
private:
    void backtrack (vector<int>& ans, vector<int>& sub, vector<int>& arr) {
        if (sub.size() == 4) {
            isValid(sub,ans);
            return;
        } 
        
        for (int j=0; j<4; j++) {
            if (arr[j]<0) continue;
            sub.push_back(arr[j]);
            arr[j] = -1;
            backtrack(ans,sub,arr);
            arr[j] = sub.back();
            sub.pop_back();
        }
    }
    
    void isValid(vector<int>& sub, vector<int>& ans) {
        int h1 = sub[0]*10+sub[1], m1 = sub[2]*10+sub[3];
        if (h1>23 || m1>59 || h1<ans[0] || (h1<=ans[0] && m1<ans[1])) return;
        ans[0] = h1, ans[1] = m1;
    }
};
