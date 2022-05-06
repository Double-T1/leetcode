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

/*
constraint: O(n) or O(logn)
prefix align: if all the 1 tp i bits are 1 and i+1 to n-1 is 0
only flipped once

for each element, we have to make sure that all the previous elements 
1. are continuous including itself
2. start from 1


binary indexed tree, for every index i (1-indexed)
1. insert element of i
2. find the prefix sum of i to see if it equals to 

or treemap
at index i, see if the last element is equal to index i

*/
