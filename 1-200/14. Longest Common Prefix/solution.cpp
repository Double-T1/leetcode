class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string& lcp = strs[0];
        int k = strs[0].size();
        for (int i=1; i<strs.size(); i++) {
            int j = 0;
            while (j<k && j<strs[i].size() && strs[i][j] == lcp[j]) j++;
            k = j;
        }
        return lcp.substr(0,k);
    }
};
