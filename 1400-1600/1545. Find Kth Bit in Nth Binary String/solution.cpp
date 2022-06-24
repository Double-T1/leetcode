class Solution {
public:
    char findKthBit(int n, int k) {
        //cout << n << " " << k << endl;
        if (n == 1) return '0';
        
        int len = pow(2,n) - 1, mid = len/2 + 1;
        if (k < mid) return findKthBit(n-1,k);
        if (k > mid) return (findKthBit(n-1,len-k+1) == '0') + '0';
        return '1';
    }
};

/*
kth bit in Sn
brute force: construct all S and store them as reference
O(1) search
O(n^2)

1,3,7,15,...,2*(m-1)+1 => 2m-1
1,2,3,4

len(1) = 1;
len(n) = 2*len(n-1)+1 = 2*(2*(len(n-2)-1))+1 = 4*(len(n-2))+3 = (2^3)*(len(n-3)) + 7
        = (2^m)*(len(m)) + (2^m - 1);
m = n-1 => 2^(n-1) * len(1) + 2^(n-1) - 1       
len(n) = 2^(n-1) * 2 -1 = 2^n - 1;

reverse backwards
for the Sn, it has a length of 2^n-1;

mid = len/2;
first half: k<len/2
second half: k>len/2
if (k == mid) return 1

if k is at first half:
    find kth bit of Sn-1
if k is at second half:
    find the reverse of (mid-k-1)th bit of Sn-1

*/
