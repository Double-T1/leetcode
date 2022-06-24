class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        string sub = "";
        bool lineComment = false, blockComment = false;
        for (auto& lines: source) {
            lineComment = false;
            for (int i=0; i<lines.size() && !lineComment; i++) {
                if (lines[i] == '/' && i<lines.size()-1 && !blockComment) {
                    if (lines[i+1] == '/' && !blockComment) lineComment = true;
                    else if (lines[i+1] == '*') {
                        lines[++i] = '&';
                        blockComment = true;
                    }
                }
                   
                if (!lineComment && !blockComment) sub += lines[i];
                
                if (lines[i] == '*' && i<lines.size()-1) {
                    if (lines[i+1] == '/' && blockComment) {
                        i++;
                        blockComment = false; 
                    }
                }
            }
            if (sub.size()>0 && !blockComment) {
                ans.push_back(sub);
                sub = "";
            }
        }
        return ans;
    }
};

