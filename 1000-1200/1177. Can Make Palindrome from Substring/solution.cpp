class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int cur = 0;
        vector<int> freq(s.size(),0);
        for (int i=0; i<s.size(); i++) {
            cur ^= 1 << (s[i] - 'a');
            freq[i] = cur;
        }
        
        vector<bool> ans(queries.size());
        for (int i=0; i<queries.size(); i++) {
            int left = queries[i][0], right = queries[i][1], k = queries[i][2];
            int lf = left > 0 ? freq[left-1] : 0, rf = freq[right];
            int sub = rf^lf, count = 0;
            while (sub) {
                sub &= (sub-1);
                count++;
            }
            ans[i] = count/2 <= k;
        }
        return ans;
    }
};

/*
O(n)

at most one odd frequency
0 and 1 => 1
1 and 0 => 1

1^1


*/
