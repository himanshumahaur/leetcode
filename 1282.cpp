class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<pair<int, int>> link;
        for(int i=0; i<g.size(); i++) {
            link.push_back({g[i], i});
        }
        sort(link.begin(), link.end());

        vector<vector<int>> res;

        for(int i=0; i<link.size(); i++) {
            vector<int> temp;
            for(int j=i; j<i+link[i].first; j++) {
                temp.push_back(link[j].second);
            }
            i += link[i].first-1;
            res.push_back(temp);
        }

        return res;
    }
};