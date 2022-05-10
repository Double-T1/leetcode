//solution 1
//using a hashset in this case for duplicay
//time: O(n^2) 
//however, given that hash function may collide, the actual time may be longer 
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> hashset;
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            int count = 0;
            string cur = "";
            for (int j=i; j<nums.size(); j++) {
                if (nums[j]%p == 0) count++;
                if (count > k) break;
                cur += (char)(nums[j]+'0');
                if (hashset.find(cur) == hashset.end()) ans++;
                hashset.insert(cur);
            }
        }
        return ans;
    }
};

//solution 1-2
//implementing the rolling hash our self (rabin karp algo)
int PRIME_MOD = 1e9 + 7;
int PRIME_BASE = 201;
    
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_map<int,vector<int>> rabK; //the hashed value and index i;
        auto hasCollision = [&](int val,int i, int j){
            if (rabK.find(val) == rabK.end()) return false;
            for (auto m: rabK[val]) {
                int ans = true;
                for (int k=i; k<=j; k++,m++) {
                    if (nums[m] != nums[k]) {
                        ans = false;
                        break;
                    }
                }
                if (ans) return true;
            }
            return false;
        };
        
        
        int ans = 0, count = 0, rolling = 0;
        for (int i=0; i<nums.size(); i++) {
            count = 0;
            rolling = 0;
            for (int j=i; j<nums.size(); j++) {
                if (nums[j]%p == 0) count++;
                if (count > k) break;
                rolling = ((unsigned long long)rolling*PRIME_BASE + nums[j]) % PRIME_MOD;
                if (!hasCollision(rolling,i,j)) {
                    rabK[rolling].push_back(i);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//solution 2
//using trie
//same time space complexity
//time: O(n^2)
//space: O(n^2)
class Solution {
public:
    struct Trie {
        int count = 0; //how many times this node has been reached
        unordered_map<int,Trie*> children;
        
        //check whether node with same value already exist 
        //either be the first node, or insert at the end of all prev nodes
        int insert(vector<int>& nums, int i, int k, int p) {
            if (i == nums.size() || k-(nums[i]%p == 0) < 0) return 0;
            if (children[nums[i]] == nullptr) children[nums[i]] = new Trie();
            return (++(children[nums[i]]->count) == 1) 
                + children[nums[i]]->insert(nums,i+1,k-(nums[i]%p == 0),p);
        }
    };
    
    
    int countDistinct(vector<int>& nums, int k, int p) {
        Trie t;
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            ans += t.insert(nums,i,k,p);
        }
        return ans;
    }
};
