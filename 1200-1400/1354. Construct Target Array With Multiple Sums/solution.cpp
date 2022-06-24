class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) return target[0] == 1;
        priority_queue<int> maxHeap(target.begin(),target.end());
        long long sum = accumulate(target.begin(),target.end(),0LL);
        
        while (true) {
            auto largest = maxHeap.top(); maxHeap.pop();
            sum -= largest;
            if (sum == 1 || largest == 1) return true;
            if (sum == 0 || largest <= sum || largest%sum == 0) return false; 
            largest %= sum;
            sum += largest;
            maxHeap.push(largest);
        }
        return true;
    }
};

/*
sort from small to big
brute force

we can set random index i as the sum of current array
at the start we have n 1s

go the other way around

the largest number is the last one constructed
set it x
x = sum of other elements + x_, x_ is the 

pq


*/
