class Solution {
public:
    int candy(vector<int>& rate) {
        int n = rate.size();
        vector<int> candy(n, 1);

        for(int i=0; i<n-1; i++) {
            if(rate[i+1]>rate[i]) {
                candy[i+1] = candy[i]+1;
            }
        }

        for(int i=n-1; i>0; i--) {
            if(rate[i-1]>rate[i]) {
                candy[i-1] = max(candy[i]+1, candy[i-1]);
            }
        }
        
        return accumulate(candy.begin(), candy.end(), 0);
    }
};