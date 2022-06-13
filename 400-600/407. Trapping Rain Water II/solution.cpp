class Solution {
private:
    int row[4] = {0,1,0,-1};
    int col[4] = {1,0,-1,0};
    
public:
    typedef tuple<int,int,int> TIII;
    
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<TIII,vector<TIII>,greater<TIII>> pq;
        int m = heightMap.size(), n = heightMap[0].size();
        bool visited[m][n];
        memset(visited,0,sizeof(visited));
        for (int i=0; i<m; i++) {
            pq.emplace(heightMap[i][0],i,0); //[height,row,col]
            pq.emplace(heightMap[i][n-1],i,n-1);
            visited[i][0] = true;
            visited[i][n-1] = true;
        } 
        
        for (int j=0; j<n; j++) {
            pq.emplace(heightMap[0][j],0,j); //[height,row,col]
            pq.emplace(heightMap[m-1][j],m-1,j);
            visited[0][j] = true;
            visited[m-1][j] = true;
        }
        
        int ans = 0;
        while (!pq.empty()) {
            auto[height,i,j] = pq.top(); pq.pop();
            
            for (int k=0; k<4; k++) {
                int i_ = i+row[k], j_ = j+col[k];
                if (i_<0 || j_<0 || i_>=m || j_>=n || visited[i_][j_]) continue;
                visited[i_][j_] =true;
                
                if (heightMap[i_][j_]<height) {
                    ans += height - heightMap[i_][j_];
                    pq.emplace(height,i_,j_);
                } else {
                    pq.emplace(heightMap[i_][j_],i_,j_);
                }
            }
        }
        
        return ans;
    }
};

/*
constraint: O(n)

it will be enclosed area, so we start from the four sides, and find the smallest height and go from there.
if adj is < than smallest height, add their diff to answer

if adj is >= than smallest height, add it to pq, and find the next height.




*/
