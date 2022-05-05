class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> hashmap(1001,0);
        for (int i=0; i<target.size(); i++) {
            hashmap[target[i]]++;
            hashmap[arr[i]]--;
        }
        
        for (auto val: hashmap) {
            if (val) return false;
        }
        return true;
    }
};
