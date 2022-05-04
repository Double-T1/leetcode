//Solution 1
//time: O(n*n*sum) => whcih is 9*10^7 in this case, right on the edge
//space: O(n*n*sum)
//unfortunately becomes TLE
class Solution {
private:
    int n, total;
    
public:
    bool splitArraySameAverage(vector<int>& nums) {
        n = nums.size();
        total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<unordered_map<int,int>>> dp(n+1,vector<unordered_map<int,int>>(n/2+1));
        return helper(nums,0,0,0,dp);
    }
    
private:
    int helper(vector<int>& nums, int i, int k, int sum, vector<vector<unordered_map<int,int>>>& dp) {
        if (k > n/2) return 0;
        if (dp[i][k][sum]>0) return dp[i][k][sum]-1;
        if (k!=0 && total*k == n*sum) {
            return (dp[i][k][sum] = 2) -1;
        }
        if (i == n) {
            return (dp[i][k][sum] = 1) -1;
        }
        
        dp[i][k][sum] = (helper(nums,i+1,k+1,sum+nums[i],dp) | helper(nums,i+1,k,sum,dp)) +1;
        return dp[i][k][sum]-1;
    }
};

//solution 2
//time : same as above
//space: O(n*sum)
//using hashmap as the table for sum
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<unordered_map<int,int>> dp(n/2+1,unordered_map<int,int>());
        
        for (int i = n; i>=0; i--) {
            for (int k = 0; k<=n/2; k++) {
                for(int sum = total/2; sum>=0; sum--) {
                    if (k!=0 && total*k == n*sum) dp[k][sum] = 1;
                    else if (i == n) dp[k][sum] = 0;
                    else {
                        if(sum+nums[i]<=total/2 && k<n/2) dp[k][sum] |= dp[k+1][sum+nums[i]];
                    }
                }
            }
        }
        return dp[0][0];
    }
};

//solution 2-2
//exactly same structure as the above
//only the DS of recording sum changed from hashmap to hashset
//noteworthly, this only works with bottom-up, since merely two states are required for any subproblem, being [true or false]
//whereas in a recursive algo, three states are required [true or false or unknown]
//this solution passed more case than solution2, but still TLE at the end
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<unordered_set<int>> dp(n/2+1,unordered_set<int>());
        
        for (int i = n; i>=0; i--) {
            for (int k = 0; k<=n/2; k++) {
                for(int sum = total/2; sum>=0; sum--) {
                    if (k!=0 && total*k == n*sum) dp[k].insert(sum);
                    else if (i == n) continue;
                    else {
                        if(sum+nums[i]<=total/2 && k<n/2 && dp[k+1].count(sum+nums[i])) dp[k].insert(sum);
                    }
                }
            }
        }
        return dp[0].count(0);
    }
};

//solution 3
//bitset
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0);
        
        vector<unsigned int> dp(total+1,0);
        dp[0] = 1;
        
        for (auto val: nums) {
            for (int s=total-val; s>=0; s--) {
                if(dp[s]) dp[s+val] |= dp[s]<<1;
            }
        }
        
        for (int k=1; k<=(n/2); k++) {
            if ((total*k)%n == 0 && (dp[(total*k)/n]&(1<<k))) return true;
        }
        return false;
    }
};
