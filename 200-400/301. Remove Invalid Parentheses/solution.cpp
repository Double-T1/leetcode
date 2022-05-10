class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, minMove = 0;
        for (auto c: s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                if (left == 0) minMove++;
                else left--;
            }
        }
        minMove += left;
        
        set<string> hashset;
        string sub;
        backtrack(hashset,sub,minMove,s,0,0);
        
        vector<string> ans;
        for (auto& s : hashset) {
            ans.push_back(s);
        }
        return ans;
    }
    
private:
    void backtrack(set<string>& ans, string& sub, int minMove, string& s, int i, int left) {
        if (minMove < 0) return;
        if (i == s.size()) {
            if (left == 0) ans.insert(sub);
        } else {
            if (s[i] == '(') {
                backtrack(ans,sub,minMove-1,s,i+1,left);
                
                sub += s[i];
                backtrack(ans,sub,minMove,s,i+1,left+1);
                sub.pop_back();
            } else if (s[i] == ')') {
                if (left > 0) {
                    sub += s[i];
                    backtrack(ans,sub,minMove,s,i+1,left-1);
                    sub.pop_back();
                }
                backtrack(ans,sub,minMove-1,s,i+1,left);
            } else {
                sub += s[i];
                backtrack(ans,sub,minMove,s,i+1,left);
                sub.pop_back();
            }
        }
    }
};
