class Solution {
public:
    string toGoatLatin(string sentence) {
        string ans = "";
        int i= 0;
        string a = "a", cur = "";
        while (i<=sentence.size()) {
            if (i == sentence.size() || sentence[i] == ' ') {
                if (!isVowel(cur[0])) cur = cur.substr(1,cur.size()-1) + cur[0];
                cur += "ma" + a;
                a += "a";
                
                ans += cur;
                cur = "";
                if (sentence[i] == ' ') ans += " ";
            } else {
                cur += sentence[i];
            }
            i++;
        }
        return ans;
    }
    
private:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};

