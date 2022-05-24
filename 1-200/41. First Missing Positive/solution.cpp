//solution 1
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (auto& val: nums) {
            if (val<=0) val = INT_MAX;
        }
        
        int n = nums.size();
        for (auto& val: nums) {
            if (abs(val) <= n && nums[abs(val)-1]>0) {
                nums[abs(val)-1] *= -1;
            }
        } 
        
        for (int i=0; i<n; i++) {
            if (nums[i]>0) return i+1;
        }
        return n+1;
    }
};

/*
the size of the vector gives us the possible candidates of answers: 
[1,vector.length] => use the index to record => [0,vector.length-1]

1. all negative numbers are converted into INT_MAX
2. if abs(num) < vector.length => vector[abs(num)-1] => negative 
*/

//solution 2
//same complexity, but better 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int val = nums[i];
            while (val != i+1 && val>0 && val<=n && nums[val-1] != val) {
                nums[i] = nums[val-1];
                nums[val-1] = val;
                
                val = nums[i];
            }
        }
        
        for (int i=0; i<n; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};
