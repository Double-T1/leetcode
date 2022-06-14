class Solution {
public:
    vector<string> invalidTransactions(vector<string>& original) {
        vector<vector<string>> tran;        
        for (string& str: original) {
            str += ',';
            string s = "";
            vector<string> parsed;
            for(auto c: str) {
                if (c == ',') {
                    parsed.emplace_back(s);
                    s = "";
                } else {
                    s += c;
                }
            }
            str.pop_back();
            
            tran.emplace_back(parsed);
        }
        
        vector<string> ans;
        for (int i=0; i<tran.size(); i++) {
            if (stoi(tran[i][2])>1000) {
                ans.emplace_back(original[i]);
                continue;
            }
            auto& s = tran[i];
            for (int j=0; j<tran.size(); j++) {
                if (i == j) continue;
                if (abs(stoi(s[1])-stoi(tran[j][1]))<=60 
                    && s[0] == tran[j][0] && s[3] != tran[j][3]) {
                    ans.emplace_back(original[i]);
                    break;
                }
            }
        }
           
        return ans;
    }
};
