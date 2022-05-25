//solution 1
//dp
//time: O(mn)
//space: O(mn)
class Solution {
private:
    int m,n;
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size(), n = nums2.size();
        int dp[m][n];
        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1;
                    if (i>0 && j>0) dp[i][j] += dp[i-1][j-1];
                    ans = max(dp[i][j],ans);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};

//solution 2
//DP, space optimization of solution 1
//space: O(n)
class Solution {
private:
    int m,n;
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size(), n = nums2.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        int ans = 0, diaganol = 0, temp;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                temp = dp[j];
                if (nums1[i] == nums2[j]) {
                    dp[j] = 1;
                    if (i>0 && j>0) dp[j] += diaganol;
                    ans = max(dp[j],ans);
                } else {
                    dp[j] = 0;
                }
                diaganol = temp;
            }
        }
        return ans;
    }
};

//solution 3
//sliding window
//time: O((m+n)*min(m,n)) => O(mn)
//space: O(1)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), ans = 0;
        for (int i2=0; i2<n; i2++) {
            ans = max(ans,findMax(nums1,nums2,0,i2));
        }
        
        for (int i1=1; i1<m; i1++) {
            ans = max(ans,findMax(nums1,nums2,i1,0));
        }
        
        return ans;
    }
    
private:
    int findMax(vector<int>& nums1, vector<int>& nums2, int i1, int i2) {
        int ans = 0, m = nums1.size(), n = nums2.size();
        for (int j1 = i1, j2 = i2, curLen = 0; j1<m && j2<n; j1++,j2++) {
            if (nums1[j1] == nums2[j2]) {
                curLen++;
                ans = max(curLen, ans);
            } else {
                curLen = 0;
            }
        }
        return ans;
    }
};

/*
the windows are as follows, each {a,b} denotes a window that starts at index a of nums1 and index b of nums2
{0,n-1} - {0,0}
{1,0} - {m-1,0}
*/

//solutin 4
//there is a KMP solution
//time: O(min(m,n)*(m+n))
//space: O(min(m,n))
//slower in reality than solution 3 given the construction of lps array
class Solution {
public:
    typedef vector<int> vi;
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()<nums2.size()) swap(nums1,nums2);
        int m=nums1.size(), n = nums2.size(), ans = 0;
        for (int k=0; k<n; k++) {
            int lps[n-k];
            getLPS(lps,nums2,k);
            
            for (int i2=k, i1=0; i2<n && i1<m;) {
                while (nums2[i2] != nums1[i1] && i2>k) i2 = lps[i2-1-k] + k;
                if (nums2[i2] == nums1[i1]) ans = max(ans,++i2-k);
                i1++;
            }
        }
        return ans;
    }
    
private:
    void getLPS(int lps[], vi& nums, int start) {
        lps[0] = 0;
        for (int i=start, j= start+1; j<nums.size();) {
            while (nums[j] != nums[i] && i>start) i = lps[i-1-start] + start;
            if (nums[j] == nums[i]) lps[j-start] = ++i - start;
            else lps[j-start] = 0;
            j++;
        }
    }
};

//solution 5
//rabin karp with binary search
//time: O(log<sub>2</sub>min(m,n) * (m+n))
//we binary search within possible range of answer length [0,min(m,n)]
//to check the particular length k, rolling hash all the corresponding subarry in nums1 and nums2, use a hashset to check if any two coincide
//due to the unfamiliarity of rolling hash, no code is provided here
