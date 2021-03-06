//s = s.length, w = wordDict.length, n = each words length
//O(s*w*n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(),-1);
        return helper(s,wordDict,memo,0);
    }
    
private:
    bool helper(string& s, vector<string>& wordDict, vector<int>& memo, int i) {
        if (i == s.size()) return true;
        if (memo[i]>-1) return (bool)memo[i];
        for (auto& word : wordDict) {
            if (s.compare(i,word.size(),word,0,word.size()) == 0 
                && helper(s,wordDict,memo,i+word.size())) {
                memo[i] = 1;
                return true; 
            }
        }
        memo[i] = 0;
        return false;
    }
};
