class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char,int>> t;
        for (auto c: s) {
            if (!t.empty() && t.back().first == c) t.back().second++;
            else t.emplace_back(c,1);
        }
        
        int ans = words.size(), m = t.size();
        for (auto& w: words) {
            int n = w.size(), j = 0, i = 0;
            for (; i<n && j<m ; i++, j++) {
                //cout << t[j].first << " " << t[j].second << " " << w[i] << endl;
                if (w[i] != t[j].first)
                    break;
                
                int count = 1;
                while (i<n-1 && w[i] == w[i+1]) 
                    i++, count++;
                
                // cout << count << endl;
                if (count > t[j].second || (t[j].second<3 && count < t[j].second)) 
                    break;
            }
            
            if (i<n || j<m) ans--;
        }
        
        return ans;
    }
};
