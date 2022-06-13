class Solution {
private:
    int op[3] = {'-','+','*'};
    int t;
    
public:
    typedef vector<string> vs;
    
    vector<string> addOperators(string num, int target) {
        t = target;
        vs ans;
        vector<pair<int,char>> vop;
        long val = 0;
        for (int i=0; i<num.size(); i++) {
            if (i == 1 && num[0] == '0') break; //no leading zeros
            val *=  10;
            val += num[i] - '0';
    
            backtrack(ans,num,vop,val,val,i+1);
        }
        return ans;
    }
    
private:
    void backtrack(vs& ans, string& num, vector<pair<int,char>>& vop,long val, long prev, int i) {
        if (i == num.size()) {
            //cout << val << " " << sub << endl;
            if (val == t) {
                string str = "";
                build(str,vop,num);
                ans.emplace_back(str);
            }    
        } else {
            long cur = 0;
            vop.emplace_back(i,'+');
            for (int j=i; j<num.size(); j++) {
                if (j == i+1 && num[i] == '0') break; //no leading zeros
                cur *= 10;
                cur += num[j] - '0';
                
                for (int k=0; k<3; k++) {
                    vop.back().second = op[k];
                    
                    if (k == 0) backtrack(ans,num,vop,val-cur,-cur,j+1);
                    if (k == 1) backtrack(ans,num,vop,val+cur,cur,j+1);
                    if (k == 2) {
                        long newP = prev*cur;
                        long newV = val - prev + newP;
                        backtrack(ans,num,vop,newV,newP,j+1);
                    }
                }
            }
            vop.pop_back();
        }
    }
    
    void build(string& str, vector<pair<int,char>>& vop,string& num) {
        int x = 0;
        vop.emplace_back(num.size(),'$');
        for (auto&[index,oper] : vop) {
            for (int j=x; j<index; j++) {
                str += num[j];
            }
            x = index;
            str += oper;
        } 
        str.pop_back();
        vop.pop_back();
    }
};
