class Solution {
public:
    string removeDuplicates(string s, int k) {
        k--;
        stack<pair<char,int>> st;
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (!st.empty() && c == st.top().first) {
                if (st.top().second == k) st.pop();
                else st.top().second++;
            } else {
                st.push({c,1});
            }
        }
        
        string ans = "";
        while (!st.empty()) {
            while(st.top().second--) {
                ans.push_back(st.top().first); 
            }
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
