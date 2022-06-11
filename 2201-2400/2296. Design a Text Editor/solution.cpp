class TextEditor {
private:
    vector<char> left;
    stack<char> right;
public:
    TextEditor() {
    }
    
    void addText(string text) {
        for(auto c: text) {
            left.push_back(c);
        }
    }
    
    int deleteText(int k) {
        int i = 0;
        for (; i<k && !left.empty(); i++) {
            left.pop_back();
        }
        return i;
    }
    
    string cursorLeft(int k) {
        while (k-- && !left.empty()) {
            right.push(left.back());
            left.pop_back();
        }
        
        return getLeft10();
    }
    
    string cursorRight(int k) {
        while (k-- && !right.empty()) {
            left.push_back(right.top());
            right.pop();
        }
        
        return getLeft10();
    }
    
private:
    string getLeft10() {
        string ans = "";
        int n = left.size();
        for (int i = n-10; i<n; i++) {
            if (i>=0) ans += left[i];
        }
        
        return ans;
    }
};
