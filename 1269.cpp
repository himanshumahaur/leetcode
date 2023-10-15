int getnum(int idx, int step, int& n, map<pair<int, int>, int>& memo) {
    if(memo.count({idx, step})) return memo[{idx, step}];

    if(idx>=n || idx<0 || step<0) return 0;
    if(step==0 && idx==0) return 1;

    int way = 0;

    way += getnum(idx-1, step-1, n, memo);
    way %= 1000000007;
    way += getnum(idx, step-1, n, memo);
    way %= 1000000007;
    way += getnum(idx+1, step-1, n, memo);
    way %= 1000000007;

    memo[{idx, step}] = way;
    return way;
}

class Solution {
public:
    int numWays(int step, int n) {
        map<pair<int, int>, int> memo;
        return getnum(0, step, n, memo);
    }
};