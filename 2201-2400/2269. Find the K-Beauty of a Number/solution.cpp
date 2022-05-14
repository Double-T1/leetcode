class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int count = 0, dup = num, d = 0;
        int i = 0;
        while (k--) {
            d += dup%10*pow(10,i++);
            dup /= 10;
            
            i *= 10;
        }
        
        while (dup) {
            if (d>0 && num%d == 0) count++;
            d += dup%10*pow(10,i);
            dup /= 10;
            d /= 10;
        }
        if (d>0 && num%d == 0) count++;
        return count;
    }
};

/*
length <= 10
make it 
sliding window of k elements from the back;
check 

edge case:
1. leading can be 0
2. but if k = 1, 0 is not allowed


*/
