//O(n^2) time
//O(1) space
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size(), maxLen = 0, maxL=-1;
        int left, right;
        for (int i=0; i<n; i++) {
            left = i, right = i;
            while (left>=0 && right<n && s[left] == s[right]) {
                left--, right++;
            }
            left++,right--;
            if (right-left+1>maxLen) {
                maxLen = right-left+1;
                maxL = left;
            }
            
            left = i, right = i+1;
            while (left>=0 && right<n && s[left] == s[right]) {
                left--, right++;
            }
            left++,right--;
            if (right<n && right-left+1>maxLen) {
                maxLen = right-left+1;
                maxL = left;
            }
        } 
        return s.substr(maxL,maxLen);
    }
};
