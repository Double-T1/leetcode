class Solution {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    
    TrieNode* root = new TrieNode();
    
    void insert(string& word) {
        auto node = root;
        for (auto c: word) {
            if (node->children[c-'a'] == nullptr) node->children[c-'a'] = new TrieNode();
            node = node->children[c-'a'];
        }
        node->isEnd = true;
    } 
    
public:  
    typedef vector<string> vs;
    
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.size() <= 2) return {};
        sort(words.begin(),words.end(),[](string& a, string& b){
            return a.size()<b.size();
        });
        
        vs ans;
        for (int i=0; i<words.size(); i++) {
            backtrack(ans,words[i]);
            
            insert(words[i]);
        }
        
        return ans;
    }
    
private:
    bool backtrack(vs& ans, string& word, int trues=0, int j=0) {
        if (j == word.size()) {
            if(trues>=2) {
                ans.push_back(word);
                return true;
            } else return false;
        }
        
        auto node = root;
        for (int k=j; k<word.size(); k++) {
            if (node->children[word[k]-'a'] == nullptr) return false;
            node = node->children[word[k]-'a'];
            if (node->isEnd && backtrack(ans,word,trues+1,k+1)) return true;
        }
        return false;
    }
};
