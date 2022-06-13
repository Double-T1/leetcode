class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> map2; //val: index
        for(int i=0; i<arr2.size(); i++) {
            map2[arr2[i]] = i;
        }
        
        sort(arr1.begin(),arr1.end(),[&map2](int a, int b){
            if (map2.count(a) && map2.count(b)) {
                return map2[a]<map2[b];
            } else if (map2.count(a)) {
                return true;
            } else if (map2.count(b)) {
                return false;
            } else {
                return a<b;
            }
        });
        
        return arr1;
    }
};
