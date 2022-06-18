// Q = times of query f(), L = height of trie, N = length of all words, n = the size of words array, w = the average length of each word => N = n*w

//solution 1
//two tries with the help of hashmaps
//time: O(Q*(L+n) + N) => could be TLE without repeating query and input check
//space: O(N)
class WordFilter {
private:
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        vector<int> index;
        
        void clear() {
            for (int i=0; i<26; i++) {
                if (children[i]) children[i]->clear();
                delete children[i];
            }
        }
    };
    
    TrieNode* preRoot = new TrieNode();
    TrieNode* sufRoot = new TrieNode();
    unordered_set<string> has_word;
    unordered_map<string,int> search_record;
    
public:
    //O(N) = O(n*w)
    WordFilter(vector<string>& words) {
        for (int i=words.size()-1; i>=0; i--) {
            auto& word = words[i];
            if (!has_word.insert(word).second) continue;
            insert(preRoot,word,i);
            reverse(word.begin(),word.end());
            insert(sufRoot,word,i);
        }
    }
    
    //O(L+n)
    int f(string prefix, string suffix) {
        string record = prefix + "&" + suffix;
        if (search_record.count(record)) return search_record[record];
        
        unordered_set<int> indices;
        reverse(suffix.begin(),suffix.end());
        if (search(preRoot,prefix,indices)<-1) return search_record[record] = -1;
        int x = search(sufRoot,suffix,indices);
        return x<0 ? search_record[record] = -1 : search_record[record] = x;
    }
    
private:
    //O(w)
    void insert(TrieNode* node, string& word,int i) {
        for (auto c: word) {
            if (node->children[c-'a'] == nullptr) node->children[c-'a'] = new TrieNode();
            node = node->children[c-'a'];
            node->index.push_back(i);
        }
    }
    
    //O(L+n)
    int search(TrieNode* node, string& pattern, unordered_set<int>& indices) {
        for (auto c: pattern) {
            if (node->children[c-'a'] == nullptr) return -2;
            node = node->children[c-'a'];
        }
        auto& arr = node->index;
        for (int i=0; i<arr.size(); i++) {
            if (!indices.insert(arr[i]).second) 
                return arr[i];
        }
        return -1;
    }
};

//solution 2
//pure hashmap
//time: O(n*w^2 + Q)
class WordFilter {
   private:
    unordered_map<string, int> hashMap;

   public:
    //O(n*w^2)
    WordFilter(vector<string>& words) {
        int n = words.size();
        for (int i = 0; i < n; i++) {
            string word = words[i];
            int wordSize = word.size();
            for (int j = 1; j <= wordSize; j++) {
                string p = word.substr(0, j); //O(w)
                for (int k = 0; k < wordSize; k++) {
                    string s = word.substr(k, wordSize); //O(w)
                    hashMap[p + "|" + s] = i + 1;
                }
            }
        }
    }
    
    //O(1)
    int f(string prefix, string suffix) {
        string s = prefix + "|" + suffix;
        return hashMap[s] - 1;
    }
};

//solution 3
//best solution 
//one trie with mutated suffix + prefix, '{' is the next character for ASCII after 'z'
//time: O(Q*w + n*w^2)
//space: O(n*w^2)
//the complexity seem slower than solution 2, but given the uncertainty of hashmap lookup O(1), this is in fact faster in reality
class trie {
    trie* ch[27];
    int weight;
public:
    trie() {
        memset(ch, 0, sizeof(ch));
        weight = 0;
    }
    //O(w)
    void insert(string& str, int weight) {
        trie* node = this;
        for (int i=str.size()-1; i>=0; i--) {
            auto c = str[i];
            if (node->ch[c - 'a'] == NULL)
                node->ch[c - 'a'] = new trie();
            node = node->ch[c - 'a'];
            node->weight = weight;
        }
    }
    //O(w)
    int startsWith(const string& str) {
        trie* node = this;
        for (char c: str) {
            if (node->ch[c - 'a'] == NULL)
                return -1;
            node = node->ch[c - 'a'];
        }
        return node->weight;
    }
};

class WordFilter {
public:
    trie root;
    //O(n*w^2)
    WordFilter(vector<string>& words) {
        int idx = 0;
        for (string& word: words) {
            reverse(word.begin(),word.end());
            root.insert(word, idx);
            int size = word.size();
            word += '{';
            for (int i = 0; i < size; i++) {
                word += word[i];
                root.insert(word, idx);
            }
            idx++;
        }
    }
    
    int f(string prefix, string suffix) {
        return root.startsWith(suffix + "{" + prefix);
    }
};
