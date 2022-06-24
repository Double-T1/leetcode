class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long ans = 0LL, bitmask = 0LL;
        vector<int> count(1024);
        count[0] = 1;
        for (auto c: word) {
            bitmask ^= 1<< (c-'a');
            ans += count[bitmask]++;
            for (int i=0; i<10; i++) {
                ans += count[bitmask^(1<<i)];
            }
        }
        return ans;
    }
};
