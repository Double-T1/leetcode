class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        colors += 'A';
        neededTime.push_back(0);
        char prevCol = '&';
        int ans = 0, prevTime = 0, n = colors.size(), sum = 0;
        for (int i=0; i<n; i++) {
            auto c = colors[i];
            if (prevCol == c) {
                prevTime = max(prevTime,neededTime[i]);
                sum += neededTime[i];
            } else {
                ans += sum - prevTime;
                prevTime = sum = neededTime[i];
                prevCol = c;
            }
        }
        return ans;
    }
};
