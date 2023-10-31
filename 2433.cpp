class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        int buff;
        for(int i=0; i<pref.size(); i++) {
            if(i) {
                res.push_back(buff^pref[i]);
                buff = buff^res[res.size()-1];
            }
            else {
                res.push_back(pref[0]);
                buff = pref[0];
            }
        }
        return res;
    }
};