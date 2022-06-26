class Solution {
public:
    int countAsterisks(string s) {
        bool inBars = false;
        int ans = 0;
        for (auto c: s) {
            if (c == '|') inBars = !inBars;
            else if (c == '*' && !inBars) {
                ans++;
            } 
        }
        return ans;
    }
};
