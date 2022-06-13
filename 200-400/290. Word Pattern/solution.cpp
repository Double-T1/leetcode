class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> s2c;
        unordered_map<char,string> c2s;
        s += ' ';
        string str = "";
        int i=0, j=0;
        for (; i<s.size() && j<pattern.size(); i++) {
            if (s[i] == ' ') {
                auto c = pattern[j];
                if (s2c.find(str) != s2c.end() && s2c[str] != c) return false;
                else s2c[str] = c;
                
                if (c2s.find(c) != c2s.end() && c2s[c] != str) return false;
                else c2s[c] = str;
                
                str = "";
                j++;
            } else {
                str += s[i];
            }
        }
        return i == s.size() && j == pattern.size();
    }
};
