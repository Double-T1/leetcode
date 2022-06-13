class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int pLen = p.size(), count = 0;
        vector<int> ans;
        int dict[26] = {0};
        for (auto c: p) {
            if (dict[c-'a'] == 0) count++;
            dict[c-'a']++;
        }
        
        for (int i=0; i<s.size(); i++) {
            auto c = s[i];
            dict[c-'a']--;
            if (dict[c-'a'] == 0) count--;
            else if (dict[c-'a'] == -1) count++;
            //cout << count << ", ";
            if (count == 0) ans.push_back(i-pLen+1);
            
            if (i >= pLen-1) {
                auto x = s[i-pLen+1];
                dict[x-'a']++;
                if (dict[x-'a'] == 0) count--;
                else if (dict[x-'a'] == 1) count++;
            }
            //cout << count << endl;
        }
        
        return ans;
    }
};
