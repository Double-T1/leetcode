class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size(), ans = 0;
        stack<int> st;
        for (int i=0; i<n; i++) {
            int cur = heights[i];
            while (!st.empty() && heights[st.top()]>=cur) {
                int h = heights[st.top()]; st.pop();
                int left = st.empty() ? -1 : st.top();
                int area = (i-left-1)*h;
                ans = max(area,ans);
            }
            st.push(i);
        }
        
        return ans;
    }
};
