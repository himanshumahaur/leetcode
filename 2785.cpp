class Solution {
public:
    bool isvov(char c, char* vov) {
        for(int i=0; i<10; i++) if(c==vov[i]) return true;
        return false;
    } 

    string sortVowels(string s) {
        int n = s.length();

        vector<char> vec;
        char vov[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        for(int i=0; i<n; i++) {
            if(isvov(s[i], vov)) {
                vec.push_back(s[i]);
            }
        }

        sort(vec.begin(), vec.end());

        int idx = 0;
        for(int i=0; i<n; i++) {
            if(isvov(s[i], vov)) {
                s[i] = vec[idx];
                idx++;
            }
        }

        return s;
    }
};