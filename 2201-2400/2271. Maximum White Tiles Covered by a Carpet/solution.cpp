
//solution 1 is much better, inspired by an answer from leetcode discussion 
//solution 2 is spaghetti code, 
//unfortunately written by myself

//solution 1
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
        sort(tiles.begin(),tiles.end());
        int x = helper(tiles,len);
        for (auto& block: tiles) swap(block[0],block[1]);
        reverse(tiles.begin(),tiles.end());
        return max(x,helper(tiles,len));
    }
    
private:
    int helper(vector<vector<int>>& tiles, int len) {
        int ans = 0, curLen = 0, covered = 0;
        for (int i=0,j=0; j<tiles.size() && ans < len;) {
            if (len > abs(tiles[j][1]-tiles[i][0])) {
                covered += abs(tiles[j][1]-tiles[j][0])+1;
                ans = max(ans,covered);
                
                j++;
            } else {
                int partial = len - abs(tiles[i][0] - tiles[j][0]);
                covered += partial;
                ans = max(ans,covered);
                
                covered -= partial;
                covered -= abs(tiles[i][1]-tiles[i][0])+1;
                i++;
            }
        }
        return ans;
    }
};

//solution 2
//O(n) time
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());        
        int ans = helper(tiles,carpetLen,tiles[0][0]-1);
        for (auto& b: tiles) swap(b[0],b[1]);
        reverse(tiles.begin(),tiles.end());
        int x = helper(tiles,carpetLen,tiles[0][0]+1);
        return max(ans,x);
    }
    
private:    
    int helper(vector<vector<int>>& tiles, int carpetLen, int end) {
        queue<pair<int,int>> qu;
        int curLen = 0, i = 0, covered = 0;
        for (; i<tiles.size(); i++) {
            auto& block = tiles[i];
            int x = abs(block[1]-end);
            if (x + curLen<= carpetLen)  {
                curLen += x;
                qu.emplace(abs(block[0]-end)-1,0);
                qu.emplace(abs(block[1]-block[0])+1,1);
                covered += abs(block[1]-block[0])+1;
                end = block[1];
                
                if (curLen == carpetLen) break;
            } else {
                int l = (curLen + x) - carpetLen;
                while (!qu.empty() && qu.front().first<=l) {
                    l -= qu.front().first;
                    covered -= qu.front().first*qu.front().second;
                    qu.pop();
                }
                if (l && !qu.empty()) {
                    covered -= qu.front().second* l;
                    qu.front().first -= l;
                }
                
                qu.emplace(abs(block[0]-end)-1,0);
                qu.emplace(abs(block[1]-block[0])+1,1);
                covered += abs(block[1]-block[0])+1;
                end = block[1];
                break;
            }
        }
        
        if (i == tiles.size()) return covered;

        i++;
        int ans = covered;
        for (; i<tiles.size(); i++) {
            auto& block = tiles[i];
            int l = abs(block[1]-end);
            while (!qu.empty() && qu.front().first<=l) {
                l -= qu.front().first;
                covered -= qu.front().first* qu.front().second;
                qu.pop();
            }
            if (l && !qu.empty()) {
                covered -= qu.front().second* l;
                qu.front().first -= l;
            }
            
            qu.emplace(abs(block[0]-end)-1,0);
            qu.emplace(abs(block[1]-block[0])+1,1);
            covered += abs(block[1]-block[0])+1;
            end = block[1];
            
            ans = max(ans,covered);
        }
        
        return ans;
    }
};
/*
can't simulate
O(n) with the origianl tile


!!! reverse


observations:
1. if we were to cover a block of tiles, we cover the whole block
=> for each element in tiles, always consider the end. 
2. at the start of current element, the carpet would be at the end of previous block
=> drag it all over to the the end of current block

how to kick out all the pre-covered tiles?? how many of them were tiles or spaces?
struct with type, tiles: 1, spaces: 0


possible that the carpet covers all the tiles without using it up


*/
