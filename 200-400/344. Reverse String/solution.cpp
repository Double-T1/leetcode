class Solution {
public:
    void reverseString(vector<char>& s) {
        int l, r;
        l = 0, r = s.size()-1;
        while (l<r) {
            swap(s[l++],s[r--]);
        }
    }
};