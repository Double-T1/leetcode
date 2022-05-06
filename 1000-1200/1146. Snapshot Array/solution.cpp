//solution 1
class SnapshotArray {
private:
    vector<vector<pair<int,int>>> arr;
    int id;
    
public:
    SnapshotArray(int length): arr(length,vector<pair<int,int>>()), id(0) {
        for (int i=0; i<length; i++) {
            arr[i].emplace_back(0,0);
        }
    }
    
    void set(int index, int val) {
        if (arr[index].back().first == id) arr[index].back().second = val;
        else arr[index].emplace_back(id,val);
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto it = upper_bound(arr[index].begin(),arr[index].end(),make_pair(snap_id,INT_MAX)); 
        //find the smallest pair that is larger than snap_id
        //if snap_id == id => our make_pair has to be larger so that the next pair will be returned
        //hence the use of INT_MAX
        return it == arr[index].begin() ? 0 : (--it)->second;
    }
};
