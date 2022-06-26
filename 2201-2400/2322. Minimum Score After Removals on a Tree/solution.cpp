class Solution {
private:
    int n;
    
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n  = nums.size();
        vector<int> adj[n];
        for (auto& edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        } 
        
        int score[n], visited[n], size[n];
        memset(score,0,sizeof(score));
        memset(visited,0,sizeof(visited));
        memset(size,0,sizeof(size));
        visited[0] = 1;
        count(score,adj,nums,0,visited,size);
        //print(size);
        
        vector<int> order;
        memset(visited,0,sizeof(visited));
        preOrder(adj,0,order,visited);
        
        int ans = INT_MAX;
        for (int i=1; i<n; i++) {
            int cur = order[i], a = score[cur], c = score[0]^a;
            int j=i+1;
            for (; j<i+size[cur]; j++) {
                int b = score[order[j]];
                int a_ = a^b;
                int max = std::max(c,std::max(b,a_)), min = std::min(c,std::min(b,a_));
                ans = std::min(ans,max-min);
            }
            for (; j<n; j++) {
                int b = score[order[j]];
                int c_ = c^b;
                int max = std::max(c_,std::max(a,b)), min = std::min(c_,std::min(a,b));
                ans = std::min(ans,max-min);
            }
        }
        
        return ans;
    }
    
private:
    void count(int score[], vector<int> adj[],vector<int>& nums, int cur,int visited[], int size[]) {
        size[cur] = 1;
        int accu = nums[cur];
        for (int next: adj[cur]) {
            if (visited[next]) continue;
            visited[next] = 1;
            count(score,adj,nums,next,visited,size);
            accu ^= score[next];
            size[cur] += size[next];
        }
        //print(size);
        score[cur] = accu;
        return;
    }
    
    void preOrder(vector<int> adj[], int cur, vector<int>& arr, int visited[]) {
        if (visited[cur]) return;
        visited[cur] = 1;
        arr.push_back(cur);
        for (int next: adj[cur]) {
            preOrder(adj,next,arr,visited);
        }
        return;
    }
    
    
    void print(int arr[]) {
        for (int i=0; i<n; i++) {
            cout << i<< ": " << arr[i] << ", ";
        }
        cout << endl;
    }
};

/*
pairs of edges => has score
score: greatest xor - smallest xor
find min

brute force: O(n^3) => TLE

a^b = c => a = b^c;

(n,3) => O(n^3) => TLE

O(n^2)

1. build the adjList
2. store the score of subtrees at the roots 
3. pair up the roots, anyone but the main root, cuz it will always be the third vertex
4. at each root, for its first children
    (1) pair with all the other children (nexted for loop)
    (2) pair with its grandchildren (queue)
5. calculate the xor through recursion
6. random node can be the main root


1. children
2. not related
3. already paired(including parents)

*/
