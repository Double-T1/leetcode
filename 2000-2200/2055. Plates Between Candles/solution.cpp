class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> covered(n,0); 
        vector<int> toRight(n,n), toLeft(n,-1);
        for (int i=0, plates = 0, prevCandle = -1; i<n; i++) {
            if (s[i] == '*') {
                if (prevCandle>-1) plates++;
                toLeft[i] = prevCandle;
            } else {
                covered[i] = plates;
                for (int j=i-1; j>prevCandle; j--) {
                    toRight[j] = i;
                }
                prevCandle = i;
            }
        }
        
        int m = queries.size();
        vector<int> ans(m);
        for (int i=0; i<m; i++) {
            int left = queries[i][0], right = queries[i][1];
            if (s[left] == '*') left = toRight[left];
            if (s[right] == '*') right = toLeft[right];
            if (left>=right) ans[i] = 0;
            else ans[i] = covered[right] - covered[left];
        }
        return ans;
    }
};

/*
bind the amount of plates to the candles

for every query:
toLeft[right]: the amount of bounded candles to the left of right
toRight[left]: 

left,right

|*|*|*
001122

*/
