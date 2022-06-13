class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> pre = {"100","#"};
        int n = preorder.size();
        string cur = "";
        for (int i=0; i<n; i++) {
            if (preorder[i] == ',') {
                pre.push_back(cur);
                cur = "";
            } else {
                cur += preorder[i];
            }
        }
        pre.push_back(cur);
        
        int m = pre.size();
        queue<string> qu;
        int i = 1;
        qu.push(pre[0]);
        while (!qu.empty() && i<m) {
            //cout << i << endl;
            auto parent = qu.front(); qu.pop();
            if (i>m-2) return false;
            if (pre[i] != "#") qu.push(pre[i]);
            if (pre[i+1] != "#") qu.push(pre[i+1]);
            i += 2;
        }
        return i == m && qu.empty();
    }
};
