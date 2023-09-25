class Solution {
public:
    char findTheDifference(string s, string t) {
        int A = 0;
        for(int i=0; i<s.size(); i++) {
            A = A^int(s[i]);
            A = A^int(t[i]);
        }
        return char(A^int(t[t.size()-1]));
    }
};