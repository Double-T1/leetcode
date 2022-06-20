class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        
        int n = searchWord.size();
        vector<vector<string>> ans(n);
        for (int i=0, left = 0, right = products.size()-1; i<n; i++) {
            auto c = searchWord[i];
            while (left<=right && (i>=products[left].size() || products[left][i] != c)) {
                left++;
            }
            while (left<= right && (i>=products[right].size() || products[right][i] != c)) {
                right--;
            }
            for (int w=0; w<3 && left+w<=right; w++) {
                ans[i].push_back(products[left+w]);
            }   
        }
        return ans;
    }
};
