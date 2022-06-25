class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0;
        vector<int> onesBefore; //the index of prev 1s, the zeros before it
        for (int i=0, zeroCount=0; i<s.size(); i++) {
            int cur = zeroCount+1;
            ans = max(ans,cur);
            int limit = k - (s[i] == '1');
            for (int j=onesBefore.size()-1; j>=0 && limit>0; j--) {
                auto pre1 = onesBefore[j];
                if (i-pre1>30) break;
                limit -= 1 << (i - pre1);
                if (limit>=0) ans = max(ans,++cur);
            }
            
            if (s[i] == '0') {
                zeroCount++;
            } else {
                onesBefore.push_back(i);
            }
        }
        return ans;
    }
};

/*
for every i, what is the longest subseq that ends at i??
1. all the prev 0 will be considered
2. always considered the 1s closer to i(rightmost), since they all cover one spot, the more rightward they are, the smaller is the overall number
3. count the amount of 0s till i
*/

//solution 2
//greedy solution: take all the zeros and try to fit in as many 1 as possible
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int res = 0, cost = 1, n = s.size();
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0' || cost <= k) {
                k -= cost * (s[i] - '0');
                res++;
            }
            if (cost <= k)
                cost *= 2;
        }
        return res;
    }
};
