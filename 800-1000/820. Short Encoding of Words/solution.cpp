//solution 1
//time: O(sum of word lengths)
//space: O(sum of word lengths)
class Solution {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
        
        TrieNode() {}
        ~TrieNode() {
            for (int i=0; i<26; i++) {
                if (this->children[i])
                    delete this->children[i];
            }
        }
        
        int insert(string& word) {
            auto node = this;
            int ans = 0, n = word.size();
            bool newWord = false;
            for (int i=n-1; i>=0; i--) {
                auto c = word[i];
                if (node->children[c-'a'] == nullptr) {
                    node->children[c-'a'] = new TrieNode();
                    if (ans == 0) newWord = true;
                }
                node = node->children[c-'a'];
                
                if (node->isEnd) {
                    node->isEnd = false;
                    ans = i;
                }
            }
            node->isEnd = newWord || ans;
            return newWord ? 1 + n : ans;
        }
    };
    
    TrieNode* root;
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        root = new TrieNode();
        int ans = 0;
        for (auto& word: words) {
            ans += root->insert(word);
        }
        return ans;
    }
};

/*
if a word is a substring of another, then we only account the larger string

trie => if exceeds all prev ends => cur length longer then all prev lengths => update answer

while inserting, 3 scenarios exist
1. it is an entirely new word, requires a new hashtag => return length + 1
2. it covers one or more previous words => return the diff in length of cur and prev longest
3. it is coverd by at least one of the previous words => return 0
*/

//solution 2
//same complexity as solution 1 but easier to implement
class Solution {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        
        TrieNode() {}
        ~TrieNode() {
            for (int i=0; i<26; i++) {
                if (this->children[i])
                    delete this->children[i];
            }
        }
        
        void insert(string& word) {
            auto node = this;
            int n = word.size();
            for (int i=n-1; i>=0; i--) {
                auto c = word[i];
                if (node->children[c-'a'] == nullptr) {
                    node->children[c-'a'] = new TrieNode();
                }
                node = node->children[c-'a'];
                
            }
        }
    };
    
    TrieNode* root;
    
public:
    int minimumLengthEncoding(vector<string>& words) {
        root = new TrieNode();
        for (auto& word: words) {
            root->insert(word);
        }
        
        int ans = 0, height= 0;
        queue<TrieNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int size = qu.size();
            ++height;
            while (size--) {
                auto node = qu.front(); qu.pop();
                bool isEnd = true;
                for (int i=0; i<26; i++) {
                    if (node->children[i]) {
                        qu.push(node->children[i]);
                        isEnd = false;
                    }
                }
                if (isEnd) ans += height;
            }
        }
        
        return ans;
    }
};

//solution 3
//even better
//time: O(nlogn)
//space: O(1)
class Solution {
public:
    int minimumLengthEncoding(vector<string>& ws, int res = 0) {
        for (auto i = 0; i < ws.size(); ++i) reverse(ws[i].begin(), ws[i].end());
        sort(ws.begin(), ws.end());
        for (auto i = 0; i < ws.size() - 1; ++i) res += ws[i] == ws[i + 1].substr(0, ws[i].size()) ? 0 : ws[i].size() + 1;
        return res + ws[ws.size() - 1].size() + 1;
    }
};
