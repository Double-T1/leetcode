class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<bool> leftGood(n,false);
        for (int i=0,count=0; i<n; i++) {
            if(i>0 && security[i] <= security[i-1]) count++;
            else count = 0;
            
            leftGood[i] = count >= time;
        }
        
        vector<int> ans;
        for (int i=n-1, count=0; i>=0; i--) {
            if(i<n-1 && security[i] <= security[i+1]) count++;
            else count = 0;
            
            if (count >= time && leftGood[i]) ans.push_back(i);
        }
        
        return ans;
    }
};
