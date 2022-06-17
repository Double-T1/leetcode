//time: O(26*25*n)
//space: O(26)
class Solution {
public:
    int largestVariance(string s) {
        int ans = 0, n = s.size();
        unordered_set<char> hashset(s.begin(),s.end());
        for (auto a: hashset) {
            for (auto b: hashset) {
                if (a == b) continue;
                bool has_b = false, first_b = false;
                for (int k=0, sum=0, left=0; k<n; k++) {
                    if (s[k] != a && s[k] != b) continue;
                    
                    if (s[k] == a) sum++;
                    else {
                        sum--;
                        has_b = true;
                        
                        if (first_b) {
                            sum++;
                            first_b = false;
                        }
                        
                        if (sum<0) {
                            sum = -1;
                            first_b = true;
                        }
                    }
                    
                    if (has_b) ans = max(ans,sum);
                }
            }
        }
        return ans;
    }
};

/*
for every pair of chars (a,b), check the largest vairance when a is larger than b.
1. when we meet a, +1. when we meet b, -1;
2. if the sum<0 => we reposition the substring and start from current position, as we're never going to compensate the diff of as and bs earlier. yet we need at least 1 b. 
3. there should at least be one b. => maintain a boolean value of has_b.
4. if we encounter a new b, and the first element is also b => we could greedily exclude the first b, as we only need at most 1 b, and we're trying to minimize the amount of b


prep:
1. boolean has_b
2. int sum

*/
