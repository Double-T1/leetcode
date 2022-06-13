class Solution {
private:
    struct comp {
        bool operator() (const pair<int,string>& a, const pair<int,string>& b) const {
            if (a.first == b.first) return a.second<b.second;
            return a.first>b.first;
        }
    };
    
public:   
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> hashmap; //string,freq
        for (auto& w : words) {
            hashmap[w]++;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp> pq;
        for (auto&[w,freq] : hashmap) {
            pq.emplace(freq,w);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> ans(k);
        int i = k-1;
        while (!pq.empty()) {
            ans[i--] = pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};
