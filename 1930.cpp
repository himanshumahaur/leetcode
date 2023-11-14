class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        vector<vector<int>> left;
        vector<vector<int>> right;

        vector<int> l(26, 0);
        vector<int> r(26, 0);

        for(int i=0; i<n; i++) {
            left.push_back(l);
            right.push_back(r);
            l[int(s[i]-'a')] = 1;
            r[int(s[n-1-i]-'a')] = 1;
        }

        int res = 0;

        map<pair<char, pair<char, char>>, int> memo;

        for(int i=0; i<n; i++) {
            for(int j=0; j<26; j++) {
                if(left[i][j] && right[n-1-i][j] && !memo.count({char(j+'a'), {s[i], char(j+'a')}})) {
                    res++;
                    memo[{char(j+'a'), {s[i], char(j+'a')}}] = 1;
                }
            }
        }

        return res;
    }
};