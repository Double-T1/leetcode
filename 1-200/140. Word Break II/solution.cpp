//solution 1
//backtrack but def TLE
class Solution {
public:
    typedef vector<string> vs;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vs ans;
        string sub;
        backtrack(s,wordDict,ans,sub);
        return ans;
    }
    
private:
    void backtrack(string& s, vs& wordDict, vs& ans, string& sub, int i=0) {
        if (i == s.size()) {
            ans.emplace_back(sub.begin(),sub.end()-1);
            return;
        }
        
        for (auto& word: wordDict) {
            if (s.size()-i>=word.size() && s.compare(i,word.size(),word) == 0) {
                sub += word + ' ';
                backtrack(s,wordDict,ans,sub,i+word.size());
                for (int i=0; i<=word.size(); i++) 
                    sub.pop_back();
            } 
        }
        
    }
    
};

//solution 2
//works but pretty slow
//uses z algo to preprocess all the spots 
//could be better by trie??
class Solution {
private:
    int len;
    
public:
    typedef vector<string> vs;
    typedef vector<int> vi;
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        len = s.size();
        vector<int> i2w[len];
        for (int j=0; j<wordDict.size(); j++) {
            zMatching(wordDict[j],s,i2w,j);
        }
        vs ans;
        string sub;
        backtrack(ans,sub,wordDict,i2w);
        return ans;
    }
    
private:
    void backtrack(vs& ans, string& sub, vs& wordDict, vi i2w[], int i=0) {
        if (i == len) {
            ans.emplace_back(sub.begin(), sub.end()-1);
            return;
        }
        
        for (auto w: i2w[i]) {
            sub += wordDict[w] + ' ';
            int n = wordDict[w].size();
            backtrack(ans,sub,wordDict,i2w,i+n);
            for (int k=0; k<=n; k++) sub.pop_back();
        }
    }
    
    
    void zMatching(string& pattern, string& text, vector<int> i2w[], int j) {
        string str = pattern + '&' + text;
        int n = str.size();
        int z[n];
        memset(z,0,sizeof(z));
        int left = 0, right = 0;
        for (int i=0; i<n;i++) {
            if (i>right) {
                left = right = i;
                
                while (right<n && str[right] == str[right-left]) right++;
                z[i] = right-left;
                right--;
            } else {
                int k = i-left;
                if (z[k]<right-i+1) z[i] == z[k];
                else {
                    left = i;
                    
                    while (right<n && str[right] == str[right-left]) right++;
                    z[i] = right-left;
                    right--;
                }
            }
        }
        
        int m = pattern.size();
        for (int i=m+1; i<n; i++) {
            if (z[i] == m) 
                i2w[i-m-1].push_back(j);
        }
    }
    
};
