class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> left;
        vector<int> right;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ')') {
                if (left.empty()) right.push_back(i);
                else left.pop_back();
            } else if (s[i] == '(') {
                left.push_back(i);
            }
        }
        
        string ans = "";
        for (int i=0, j=0, k=0; i<s.size(); i++) {
            if (j<right.size() && i == right[j]) j++;
            else if (k<left.size() && i == left[k]) k++;
            else ans += s[i];
        }
        return ans;
    }
};


/*
valid => pairs of paren
check if ( == )
if ( == ) cool
if ( > ) skip the first ( - ) '('
if ( < ) skip the 

every ) is valid if there is a vacant (  before, vice versas

1. record the indexes of (
2. if met with (  than pop out
3. also store indices of lonely )

*/
