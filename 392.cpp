class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = t.size();
        int m = s.size();

        int idx = 0;

        for(int i=0; i<n; i++) {
            cout << idx << " ";
            if(idx==m) {
                if(t[i]==s[idx]) idx++;
            }
            else {
                break;
            }
        }

        if(idx==m) return true;
        return false;
    }
};