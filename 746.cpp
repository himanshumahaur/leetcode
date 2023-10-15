class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> vec(n+1);

        vec[0] = 0;
        vec[1] = 0;

        for(int i=0; i<=n; i++) {
            if(i>=2) vec[i] = min(vec[i-1]+cost[i-1], vec[i-2]+cost[i-2]);
        }

        return vec[n];
    }
};