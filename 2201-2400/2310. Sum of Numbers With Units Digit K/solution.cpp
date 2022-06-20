class Solution {
public:
    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        if (k == 0) {
            if (num%10 == 0) return 1;
            else return -1;
        }
        
        int count = 1;
        while (num%10 != k) {
            count++;
            num -= k;
            
            if (num < k) return -1;
        }
        return count;
    }
};

/*
the unit digit of num has to be able to be built up by k
suppose num has a unit digit of x, with int k

if (k == 0) return 0
if (k == 1) all x is possible => answer would be x;
if (k == 2) x has to be even => answer would be x/2;
if (k == 3) x could be 3,6,9,2,5,8,1,4,7,0 => all 
                       0,2,3,
                       
while x != k
keep on subtracting num with k
if (x<0) return -1




*/
