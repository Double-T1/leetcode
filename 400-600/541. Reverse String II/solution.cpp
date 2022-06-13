class Solution {
public:
    string reverseStr(string s, int k) {
        bool doReverse= true;
        int n = s.size();
        for (int i=0; i<n;) {
            int left = i, right = min(i+k-1,n-1);
            while (doReverse && left<right) {
                swap(s[left++],s[right--]);
            }
            doReverse = !doReverse;
            i = i+k;
        }
        return s;
    }
};
