class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        int bitmask = 0;
        int size = 1;
        for (int i=2; i<n; size*=i,i++);
        
        for (int p=n; p>=1; p--) {
            int i = (k-1)/size + 1;
            for (int j=1, m=0; j<=n; j++) {
                if ((1<<j)&bitmask) continue;
                if (++m == i) {
                    bitmask |= 1<<j;
                    ans += (char)(j+'0');
                    break;
                }  
            }
            k = (k-1)%size +1;
            if(p>1) size /= (p-1);
        }
        return ans;
    }
};

/*
for a total of K permus, we can group them into n group
for the kth of K (1-indexed), we can get their first element by getting the ith number of the remaining nums
i = (k-1)/n

for next
groups--;
k %= groups 

for 1st char
there are n group
k/nth num is the first char

for 2th char
n--;
k = k%n
if (k == 0) k++;

need a ds to dynaimcally reorder
1. search for ith biggest element
2. deleted ith element, while maiting a sorted order

=> brute force O(n)



*/
