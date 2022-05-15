class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev = "$";
        for (auto& w: words) {
            string dub = w;
            sort(dub.begin(),dub.end());
            if (prev == dub) continue;
            ans.push_back(w);
            prev = dub;
        }
        return ans;
    }
};
