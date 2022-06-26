class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for (int i=1; i<n; i++) {
            cardPoints[i] += cardPoints[i-1];
        }
        
        int sum = cardPoints.back();
        if (n == k) return sum;
        int ans = max(cardPoints[k-1],sum-cardPoints[n-k-1]);
        for (int i=1; i<k; i++) {
            ans = max(ans,cardPoints[i-1] + sum - cardPoints[n-(k-i)-1]);
        }
        return ans;
    }
};

/*
k-0 => O(n+k^2) => O(n+k)





*/
