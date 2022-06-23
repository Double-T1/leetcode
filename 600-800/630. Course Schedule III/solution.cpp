class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> q;
        int sum = 0;
        for(auto i : courses) {
            sum += i[0];
            q.push(i[0]);
            if(sum > i[1]) {
                sum -= q.top();
                q.pop();
            }
        }
        return q.size();
    }
};

/*
s: prev total sum of time
l1: prev lastday
d: current duration
l2: cur lastday
x: the largest duration in s

known:
l1<=l2, s<=l1, d<=l2

assuming s+d > l2
if (x>d) => s-x <= l1 <= l2
(x-d)>0 => s-x+d < s <= l1 <= l2 

if (d>=x) => s <= l1 <= l2
*/
