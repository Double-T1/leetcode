class NumArray {
private:
    vector<int> fenwick;
    
public:
    NumArray(vector<int>& nums): fenwick(nums.size()+1,0) {
        for(int i=0; i<nums.size(); i++) {
            update(i,nums[i]);
        }
    }
    
    void update(int index, int val) {
        int delta = val - sumRange(index,index);
        index++;
        while(index<fenwick.size()) {
            fenwick[index] += delta;
            index += lowbit(index);
        }
    }
    
    int sumRange(int left, int right) {
        return query(right+1) - query(left);
    }
    
private:
    int lowbit(int x) {
        return x & (-x);
    }
    
    int query(int j) {
        int sum = 0;
        while(j>0) {
            sum += fenwick[j];
            j -= lowbit(j);
        }
        return sum;
    }
};
