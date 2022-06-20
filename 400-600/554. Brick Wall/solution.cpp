class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> freq;
        int n = wall.size(), ans = n;
        for (auto& w: wall) {
            for (int i=0, len=0; i<w.size()-1; i++) {
                len += w[i];
                freq[len]++;
                ans = min(ans,n-freq[len]);
            }
        }
        return ans;
    }
};


/*
brute force: O(n*(sum of width)) => TLE

O(sum of lengths)

the lines are the gaps between each brick

insert them into a set and find the most recurring ones
*/
