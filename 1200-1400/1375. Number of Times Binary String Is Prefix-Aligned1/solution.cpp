//solution 1
//time: O(nlogn)
//space: O(n)
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        set<int> treeset;
        int count = 0;
        for (int i=0; i<flips.size(); i++) {
            treeset.insert(flips[i]);
            if (*treeset.rbegin() == i+1) count++;
        }
        return count;
    }
};

//solution 2
//time: O(n)
//space: O(1)
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int count = 0, x = 0;
        for (int i=0; i<flips.size(); i++) {
            x = max(flips[i],x);
            if (x == i+1) count++;
        }
        return count;
    }
};
