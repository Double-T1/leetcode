class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i=0, sum=0; i<heights.size()-1; i++) {
            if (heights[i]>=heights[i+1]) continue;
            
            int gap = heights[i+1] - heights[i];
            pq.push(gap);
            if (pq.size()>ladders) {
                sum += pq.top();
                pq.pop();
            }
            
            if (sum>bricks) return i;
        }
        
        return heights.size()-1;
    }
};


/*
dp
greedy

ladders can reach inifinte height

[9,2,2]

pick leftmost k gaps such that
the sum of (k-ladders) gaps are smaller than or equal to bricks

binary search k ??

store the traversed gaps from small to larget, and the total amount to them, 
as long as the k-ladders has a sum <= bricks than such i is reachable

fast way to calculate sum(k-ladders)

1. maintain a min priority queue of ladders size, if the size exeeds ladders, than pop the min element as the sum



*/
