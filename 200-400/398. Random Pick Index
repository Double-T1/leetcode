class Solution {
private:
    vector<pair<int,int>> vec;
    
public:
    Solution(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            vec.push_back(make_pair(nums[i],i));
        }
        sort(vec.begin(),vec.end());
    }
    
    int pick(int target) {
        int left=0, right = vec.size();
        while (left<right) {
            int mid = left + (right-left)/2;
            if (vec[mid].first>=target) right = mid;
            else left = mid+1;
        }
        
        int ans = 0;
        for (int i=right, n=1; i<vec.size() && vec[i].first == target; i++) {
            if (rand()%n == 0) ans = vec[i].second;
            n++;
        }
        return ans;
    }
};
