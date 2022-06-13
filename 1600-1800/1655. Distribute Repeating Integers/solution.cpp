class Solution {  
private:
    int m,n;
    
public:
    typedef vector<int> vi;
    typedef vector<vi> vvi;
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        vector<int> freq;
        unordered_map<int,int> hashmap;
        int last = 0;
        for (auto val: nums) {
            if (hashmap.find(val) == hashmap.end()) {
                hashmap[val] = freq.size();
                freq.push_back(1);
            } else {
                freq[hashmap[val]]++;
            }
        }
        return CanAllFit(freq,quantity);
    }
    
private:
    bool CanAllFit(vector<int> &contSize, vector<int> &itemSize) {
        vector<vector<bool>> dp(contSize.size(), vector(1 << itemSize.size(), false));
        function<bool(int, int)> BT;
        BT = [&](int i, int avail) {
            if (!avail) return true;
            if (i == contSize.size()) return false;
            if (dp[i][avail]) return false;
            for (int mask = avail; ; mask = (mask - 1) & avail) {
                int sum = 0;
                for (int j = 0; (1 << j) <= mask; ++j)
                    if ((1 << j) & mask) sum += itemSize[j];
                if (sum <= contSize[i] && BT(i + 1, avail ^ mask)) return true;
                if (!mask) break;
            }
            dp[i][avail] = true;
            return false;
        };

        return BT(0, (1 << itemSize.size()) - 1);
    }
};


/*
1000*1024*50*10

or 50*1024*1024*10

NPC

at each i for q, we try all the possibilities, 
=> 1. prep a list of counts of nums (at most 50)
2. prep a bitset of choosen numbers.


freq = [2,4]
q = [1,2,3]

observations:
1. start from small, since if the smallest element in q is bigger than current freq, than no other i in q is smaller than or equal to current freq 
=> sort both freq and quantity

2. we can either try to fill quantities into freqs => backtracking
or we can fill freqs up by quantities, meaning we look for quantities from the perspective of freqs
=> better since the states of freq is limited compared to quantity
criteria: f>=q
=> decreasing order for both freq and q
*/
