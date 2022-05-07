class Solution {
public:
    string decodeString(string s) {
        s += '$';
        vector<string> st;
        string cur = "";
        int i = 0;
        for (auto& c: s) {
            if (c == '$' || c == '[') {
                //cur could be "" or chars or nums
                if (cur != "") st.push_back(cur);
                cur = "";
            } else if (c == ']') {
                int freq = stoi(st.back());
                auto base = cur;
                while (--freq) {
                    cur += base;
                }
                
                st.pop_back();
                if (!st.empty() && st.back()[0] >= 'a' && st.back()[0] <= 'z') {
                    st.back() += cur;
                    swap(cur,st.back());
                    st.pop_back();
                }
            } else if (c>='0' && c<='9') {
                //cur could be nums or "" or chars
                if (cur != "" && cur.back()>='a' && cur.back()<='z') 
                    st.push_back(cur), cur = ""; 
                cur += c;
            } else {
                //cur could be chars or "" 
                cur += c;
            }
            i++;
        }
        
        string& ans =  st[0];
        for (int i=1; i<st.size(); i++) {
            ans += st[i];
        }
        return ans;
    }
};
