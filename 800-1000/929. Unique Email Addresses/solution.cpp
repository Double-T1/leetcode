class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> hashset;
        int count = 0;
        for (auto& s: emails) {
            string email = "";
            for (int i=0; i<s.size(); i++) {
                auto c = s[i];
                if (c == '@') {
                    while (i<s.size()) email += s[i++];
                } else if (c == '+') {
                    while (i<s.size() && s[i+1] != '@') i++;
                } else if (c != '.') {
                    email += c;
                }
            }
            //cout << email << endl;
            hashset.insert(email);
        }
        return hashset.size();
    }
};
