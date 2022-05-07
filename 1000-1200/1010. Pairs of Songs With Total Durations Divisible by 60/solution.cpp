class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> hashmap;
        int ans = 0;
        for (auto val: time) {
            int x2 = val%60;
            int x1 = (60-x2)%60;
            if (hashmap[x1]) {
                ans += hashmap[x1];
            }
            hashmap[x2]++;
        }
        return ans;
    }
};

/*
(a+b)%60 == 0
=> ((x1 + 60y1) + (x2 + 60y2)) %60 == 0

(x1 + x2) % 60
x1 < 60 and x2 < 60
x1 + x2 < 120


1. for each ele, record its remainder of 60
2. for remainder of each ele, find if there are compliments of 0,60
*/
