bool cmp(const int& a, const int& b) {
    return a>b;
}

class Solution {
public:
    int minDeletions(string s) {
        int count = 0;
        vector<int> freq(26);
        for(auto i:s) {
            freq[i-'a']++;
        }
        sort(freq.begin(), freq.end(), cmp);
        for(int i=0; i<26-1; i++) {
            if(freq[i]<=freq[i+1] && freq[i]!=0) {
                count += (freq[i+1]-freq[i])+1;
                freq[i+1] = freq[i]-1;
            }
            else if(freq[i]==0) {
                while(i<26-1) {
                    count += freq[i+1];
                    i++;
                }
            }
        }
        return count;
    }
};