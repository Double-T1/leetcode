class Solution {
private:
    struct TrieNode {
        int index = -1;
        vector<int> hasPalin;
        TrieNode* children[26] = {nullptr};
        
        void clear() {
            for (int k=0; k<26; k++) {
                if (children[k] == nullptr) continue;
                children[k]->clear();
                delete children[k];
                children[k] = nullptr;
            }
        }
    };    
public:
    typedef vector<vector<int>> vvi;
    
    vector<vector<int>> palindromePairs(vector<string>& words) {        
        vvi ans;
        TrieNode* root = new TrieNode();
        
        for (int i=0; i<words.size(); i++) {
            insert(words[i],root,i);
        }
        
        for (int i=0; i<words.size(); i++) {
            search(words[i],root,i,ans);
        }
        return ans;
    }
    
private:
    void insert(string& w,TrieNode* node,int k) {
        int n = w.size();
        for (int i=n-1; i>=0; i--) {
            auto c = w[i];
            if (isPalin(w,0,i)) node->hasPalin.push_back(k);
            
            if (node->children[c-'a'] == nullptr) node->children[c-'a'] = new TrieNode();
            node = node->children[c-'a'];
        }
        node->index = k;
        node->hasPalin.push_back(k);
    }
    
    void search(string& w, TrieNode* node, int k, vvi& ans) {
        int n = w.size(), i=0;
        for (; i<n; i++) {
            auto c = w[i];
            if (node->index>-1 && node->index != k && isPalin(w,i,n-1))
                ans.push_back({k,node->index});
            
            if (node->children[c-'a'] == nullptr) return;
            node = node->children[c-'a'];
        }
        
        for (int i: node->hasPalin) {
            if (i == k) continue;
            ans.push_back({k,i});
        }
    }
    
    bool isPalin(string& w, int i, int j) {
        if (i >= j) return true;
        return w[i] == w[j] ? isPalin(w,i+1,j-1) : false;
    }
};

/*
create a huge trie of all previous word

for incoming element, 
1. traverse from the start, to check if there exist fitting palindromes
2. traverse form the end .... 
=> prep a prefix trie and a suffic trie (not the actual suffix tree)

at each trieNode we record whether there is a palindromic substring as its children, if yes, what is the index of it


then we insert the start and the end into the tries


*/
