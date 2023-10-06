class Solution {
public:
    int integerBreak(int n) {
        static unordered_map<int, int> memo;
        if(memo.count(n)) return memo[n];

        if(n==1) return 1;
        int m = n/2;
        int M = 0;

        for(int i=1; i<=m; i++) {
            M = max(M, integerBreak(i)*integerBreak(n-i));
            M = max(M, i*integerBreak(n-i));
            M = max(M, integerBreak(i)*(n-i));
            M = max(M, i*(n-i));
        }

        memo[n] = M;
        return M;
    }
};