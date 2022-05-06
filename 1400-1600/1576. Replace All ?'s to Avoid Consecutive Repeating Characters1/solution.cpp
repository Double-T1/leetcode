//time: O(n)
//space: O(1)
class Solution {
public:
    string modifyString(string s) {
        for(int i=0; i<s.size(); i++) {
            if (s[i] == '?') {
                for (int j=0; j<26; j++) {
                    if (i>0 && (j+'a') == s[i-1]) continue;
                    if (i<s.size()-1 && (j+'a') == s[i+1]) continue;
                    s[i] = (char)(j+'a');
                    break;
                }
            }
        }
        return s;
    }
};
