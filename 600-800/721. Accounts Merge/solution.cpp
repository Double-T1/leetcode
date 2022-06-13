class Solution {
public:
    typedef unordered_map<string,int> omsi;
    typedef vector<vector<string>> vvs;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        omsi e2p; //[email: parent]
        int n = accounts.size(), m;
        int parent[n];
        for (int i=0; i<n; i++) {
            m = accounts[i].size();
            parent[i] = i;
            for (int j=1; j<m; j++) {
                if (e2p.find(accounts[i][j]) == e2p.end()) {
                    e2p[accounts[i][j]] = i;
                } else {
                    unite(parent,e2p[accounts[i][j]],i);   
                }
            }
        }
        
        vvs ans;
        int p2a[n]; //[accounts index/parent: answer index]
        memset(p2a,-1,sizeof(p2a));
        for (int i=0; i<n; i++) {
            int pi = find(parent,i);
            if (p2a[pi] == -1) {
                p2a[pi] = ans.size();
                ans.push_back({accounts[pi][0]});
            } 
            
            auto& vec = ans[p2a[pi]];
            for (int j=1; j<accounts[i].size(); j++) {
                if (e2p[accounts[i][j]] != -1) {
                    vec.push_back(accounts[i][j]);
                    e2p[accounts[i][j]] = -1;
                }
            }
        }
        
        for (auto& sub: ans) {
            sort(sub.begin()+1, sub.end());
        }
        
        return ans;
    }
    
private:
    void unite(int parent[], int j, int k) {
        int pj = find(parent,j), pk = find(parent,k);
        if (pj == pk) return;
        parent[pk] = pj;
    }
    
    int find(int parent[], int x) {
        if (x != parent[x]) 
            parent[x] = find(parent,parent[x]);
        return parent[x];
    }
};

/*
union find with hashmap
if the new email has no parent, set it to the curent index i
unite all the emails under the same account

use a hashmap to record emails and their parents

after all mapping, traverse through the hashmap, while utilizing another hashmap for inputtig the answer





*/
