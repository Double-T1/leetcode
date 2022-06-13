class Solution {
private:
    const string special = "!@#$%^&*()-+";
        
public:
    bool strongPasswordCheckerII(string password) {
        bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
        int n = password.size();
        for (int i=0; i<n; i++) {
            if (i>0 && password[i] == password[i-1]) return false; 
            auto c = password[i];
            if (c >= '0' && c<= '9') hasDigit = true;
            else if (c >= 'A' && c<= 'Z') hasUpper = true;
            else if (c >= 'a' && c<= 'z') hasLower = true;
            else if (special.find(c) != string::npos) hasSpecial = true;
        }
        
        return n>=8 
            && hasLower 
            && hasUpper
            && hasDigit
            && hasSpecial;
    }
};
