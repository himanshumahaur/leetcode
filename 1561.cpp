class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int res = 0;

        int low = 0;
        int high = piles.size()-1;

        sort(piles.begin(), piles.end());

        while(low<high) {
            high--;
            res += piles[high];
            high--;
            low++;
        }

        return res;
    }
};