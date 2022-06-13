class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> dict;
        for (int i=0; i<arr.size(); i++) {
            dict[arr[i]] = i;
        }
        
        for (auto& sub: pieces) {
            int prev = -1;
            for (auto val: sub) {
                if (dict.count(val) && (prev == -1 || dict[val] == prev+1)) {
                    prev = dict[val];
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};
