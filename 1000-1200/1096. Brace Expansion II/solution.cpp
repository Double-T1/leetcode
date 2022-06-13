class Solution {
public:
    typedef set<string> SS;
    typedef pair<char,SS> PCSS;
    
    vector<string> braceExpansionII(string expr) {
        stack<PCSS> st;
        st.emplace(',',SS({""}));
        for (auto c: expr) {
            if (c == ',') {
                st.emplace(',',SS({""}));
            } else if (c == '{') {
                st.emplace('{',SS());
                st.emplace(',',SS({""}));
            } else if (c == '}') {
                SS strset;
                while (st.top().first != '{') {
                    for (string prev: st.top().second) {
                        strset.emplace(prev);
                    }
                    st.pop();
                }
                st.pop();
                
                //merge with the prefix 
                SS newset;
                for (string cur: strset) {
                    for (string prev: st.top().second) {
                        newset.emplace(prev+cur);
                    }
                }
                st.top().second = newset;
                
            } else {
                SS newset;
                for (string prev: st.top().second) {
                    newset.emplace(prev+c);
                }
                st.top().second = newset;
            }
        }
     
        vector<string> ans;        
        for(string v: st.top().second) {
            ans.push_back(v);
        }
        
        //sort (ans.begin(),ans.end());
        return ans;
    }
};
