class Solution {
public:
    long long countTotal(long long n) {
        return n * (n+1) / 2;
    }

    int countHomogenous(string s) {
        int res = 0;
        int MOD = 1000000007;

        int cur = s[0];
        int frq = 1;

        for(int i=1; i<s.length(); i++) {
            if(cur==s[i]) {
                frq++;
            }
            else {
                res += countTotal(frq) % MOD;
                cur = s[i];
                frq = 1;
            }
        }

        res += countTotal(frq) % MOD;

        return res;
    }
};