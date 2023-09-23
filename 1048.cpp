bool cmp(string& a, string& b) {
    return a.size()<b.size();
}

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int res = 0;
        int n = words.size();
        unordered_map<string, int> hash;
        sort(words.begin(), words.end(), cmp);
        for(int i=0; i<n; i++) {
            for(int j=0; j<words[i].size(); j++) {
                string str = words[i];
                str.erase(j, 1);
                hash[words[i]] = max(hash[words[i]], hash[str]+1);
                if(res<hash[words[i]]) res = hash[words[i]];
            }
        }
        for(auto i:hash) {
            cout << i.first << " " << i.second << endl;
        }
        return res;
    }
};