class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = 0, i=num.size()-1;
        vector<int> ans;
        while (k || carry || i>=0) {
            if (k) carry += k%10, k /= 10;
            if (i>=0) carry += num[i--];
            ans.push_back(carry%10);
            carry /= 10;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
