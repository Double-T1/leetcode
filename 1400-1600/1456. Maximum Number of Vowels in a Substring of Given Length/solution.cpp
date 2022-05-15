class Solution {
public:
    int maxVowels(string s, int k) {
        int vCount = 0, ans = 0;
        for (int i=0, j=0; j<s.size(); j++) {
            if (isVowel(s[j])) 
                vCount++;
            
            ans = max(ans,vCount);
            
            if (j-i+1 == k) {
                if (isVowel(s[i])) 
                    vCount--;
                i++;
            }
        }
        return ans;
    }
    
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
