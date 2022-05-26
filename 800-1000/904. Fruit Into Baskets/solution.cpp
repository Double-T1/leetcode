class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 1, left = 0, one = -1, two = fruits[0], curLen = 1;
        for (int i=1; i<fruits.size(); i++) {
            if (fruits[i] == two) {
                curLen++;
            } else if (fruits[i] == one) {
                curLen++;
                left = i;
                one = two;
                two = fruits[i];
            } else {
                ans = max(ans,curLen);
                
                one = two;
                two = fruits[i];
                curLen = i-left+1;
                left = i;
            }
        }
        return max(ans,curLen);
    }
};

/*
at each tree/element we can pick one fruit
we can at most picked two types of fruits => find the longest subarrays with only two kind of elements

one, two, length

*/
