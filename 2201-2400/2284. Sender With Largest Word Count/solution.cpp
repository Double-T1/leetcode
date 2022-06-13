class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> n2c;
        
        int n = senders.size(), curMax = 0;
        string ans = "";
        for (int i=0; i<n; i++) {
            auto& name = senders[i];
            
            int count = 1;
            for (auto c: messages[i]) {
                if (c == ' ') count++;
            }
            
            n2c[name] += count;
            if (n2c[name] == curMax) {
                if (ans == "" || ans<name) ans = name;  
            } else if (curMax < n2c[name]) {
                ans = name;
                curMax = n2c[name];
            }
        }
        return ans;
    }
};
