class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int n = prices.size();

        int choc1 = INT_MAX;
        int choc2 = INT_MAX;

        for(int i=0; i<n; i++) {
            if(prices[i]<choc1) {
                choc2 = choc1;
                choc1 = prices[i];
            }
            else if(prices[i]<choc2) choc2 = prices[i];
        }

        int cost = choc1 + choc2;

        if(cost>money) return money;
        return money-cost;
    }
};
