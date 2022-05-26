//solution 1
//time: O(32)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            if (n&1) count++;
            n >>= 1;
        }
        return count;
    }
};

//solution 2
//time: O(n) , n being the amount of bits
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            count++;
            n &= (n-1);
        }
        return count;
    }
};

//solution 3
//time: O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        n = (n& 0x55555555) + (n >> 1 & 0x55555555);
        n = (n& 0x33333333) + (n >> 2 & 0x33333333);
        n = (n& 0x0F0F0F0F) + (n >> 4 & 0x0F0F0F0F);
        n = (n& 0x00FF00FF) + (n >> 8 & 0x00FF00FF);
        n = (n& 0x0000FFFF) + (n >> 16 & 0x0000FFFF);
        return n;
    }
};
