class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> fwd;

        for(auto p:pairs) {
            fwd[p[0]].push_back(p[1]);
            fwd[p[1]].push_back(p[0]);
        }

        int a = 0;
        int b = 0;

        vector<int> res;

        for(auto p:fwd) {
            if(p.second.size()==1) {
                if(a) {
                    b = p.first;
                }
                else {
                    a = p.first;
                }
            }
        }

        res.push_back(a);
        a = fwd[a][0];
        while(res.size()<pairs.size()) {
            if(fwd[a][0]==res.back()) {
                res.push_back(a);
                a = fwd[a][1];
            }
            else {
                res.push_back(a);
                a = fwd[a][0];
            }
        }
        res.push_back(b);
 
        return res;
    }
};